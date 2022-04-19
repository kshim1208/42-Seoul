/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshim <kshim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 11:05:37 by kshim             #+#    #+#             */
/*   Updated: 2022/04/14 08:47:48 by kshim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static t_lst	*gnl_select_lst(int fd, t_lst **gnl_head);
static ssize_t	get_buffer(int fd, t_lst *lst);
static ssize_t	process_buffer(t_lst *lst, char **ret);
static char		*join_buffer_to_ret(char **ret, char *buffer);

char	*get_next_line(int fd)
{
	static t_lst	*gnl_head;
	t_lst			*work_lst;
	char			*ret;

	if (fd < 0)
		return (NULL);
	ret = NULL;
	work_lst = gnl_select_lst(fd, &gnl_head);
	if (work_lst == NULL)
		return (NULL);
	while (work_lst -> str_next == NULL || ret == NULL)
	{
		work_lst -> check_result = get_buffer(fd, work_lst);
		if (work_lst -> check_result <= 0 || work_lst -> buffer == NULL)
			break ;
		work_lst -> check_result = process_buffer(work_lst, &ret);
		if (work_lst -> check_result == -1)
			return (NULL);
	}
	ft_free_elements_gnl(work_lst, &ret);
	if (work_lst -> check_result == 0 || work_lst -> check_result == -1)
		ft_free_lst_gnl(&gnl_head, &work_lst);
	return (ret);
}

static t_lst	*gnl_select_lst(int fd, t_lst **gnl_head)
{
	t_lst	*work_lst;
	t_lst	*tmp;

	tmp = *gnl_head;
	work_lst = NULL;
	while (tmp != NULL)
	{	
		if (tmp -> saved_fd == fd)
			return (tmp);
		if (tmp -> next == NULL)
			break ;
		tmp = tmp -> next;
	}
	work_lst = (t_lst *)malloc(sizeof(t_lst));
	if (work_lst == NULL)
		return (NULL);
	if (*gnl_head != NULL)
		tmp -> next = work_lst;
	else if (*gnl_head == NULL)
		*gnl_head = work_lst;
	work_lst -> saved_fd = fd;
	work_lst -> str_next = NULL;
	work_lst -> buffer = NULL;
	work_lst -> next = NULL;
	return (work_lst);
}

static ssize_t	get_buffer(int fd, t_lst *lst)
{
	ssize_t	check_result;

	check_result = 0;
	if (lst -> buffer != NULL)
	{
		free(lst -> buffer);
		lst -> buffer = NULL;
	}
	if (lst -> str_next != NULL)
	{
		lst -> buffer = lst -> str_next;
		lst -> str_next = NULL;
		check_result = ft_strlen(lst -> buffer);
	}
	else
	{
		lst -> buffer = (char *)malloc(BUFFER_SIZE + 1);
		if (lst -> buffer == NULL)
			return (-1);
		check_result = read(fd, lst -> buffer, BUFFER_SIZE);
		if (check_result <= 0)
			return (check_result);
		(lst -> buffer)[check_result] = '\0';
	}
	return (check_result);
}

static ssize_t	process_buffer(t_lst *lst, char **ret)
{
	char	*tmp;
	size_t	len_until_nextline;

	lst -> str_next = ft_strchr(lst -> buffer, (int) '\n');
	if (lst -> str_next != NULL)
	{
		len_until_nextline = (lst -> str_next) - (lst -> buffer) + 1;
		tmp = ft_strndup(lst -> buffer, len_until_nextline);
		if (tmp == NULL)
			return (-1);
		lst -> str_next = ft_strndup(lst -> buffer + len_until_nextline,
				ft_strlen(lst -> buffer + len_until_nextline));
		if (lst -> str_next == NULL)
		{
			free(tmp);
			return (-1);
		}
		free(lst -> buffer);
		lst -> buffer = tmp;
	}
	tmp = join_buffer_to_ret(&(*ret), lst -> buffer);
	if (tmp == NULL)
		return (-1);
	*ret = tmp;
	return (1);
}

static char	*join_buffer_to_ret(char **ret, char *buffer)
{
	size_t	i;
	size_t	j;
	size_t	len;
	char	*str;

	if (*ret == NULL)
		len = ft_strlen(buffer);
	else
		len = ft_strlen(*ret) + ft_strlen(buffer);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (i < len && *ret != NULL && (*ret)[j] != '\0')
		str[i++] = (*ret)[j++];
	if (*ret != NULL)
		free(*ret);
	j = 0;
	while (i < len && buffer[j] != '\0')
		str[i++] = buffer[j++];
	str[i] = '\0';
	return (str);
}
