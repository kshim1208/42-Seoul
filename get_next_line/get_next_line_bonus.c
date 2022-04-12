/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshim <kshim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 11:05:37 by kshim             #+#    #+#             */
/*   Updated: 2022/04/12 16:29:15 by kshim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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
	free_gnl(work_lst, &ret);
	if (work_lst -> check_result == 0 || work_lst -> check_result == -1)
		free_lst(&gnl_head, &work_lst);
	return (ret);
}

t_lst	*gnl_select_lst(int fd, t_lst **gnl_head)
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

ssize_t	process_buffer(t_lst *lst, char **ret)
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
	tmp = join_buffer_to_ret(*ret, lst -> buffer);
	if (tmp == NULL)
		return (-1);
	*ret = tmp;
	return (1);
}

void	free_gnl(t_lst *lst, char **ret)
{
	free(lst -> buffer);
	lst -> buffer = NULL;
	if ((lst -> check_result <= 0 && lst -> str_next != NULL)
		|| ((lst -> str_next != NULL) && (*(lst -> str_next) == '\0')))
	{
		free(lst -> str_next);
		lst -> str_next = NULL;
	}
	if (lst -> check_result == -1 && *ret != NULL)
	{
		free(*ret);
		*ret = NULL;
	}
	return ;
}

void	free_lst(t_lst **head, t_lst **lst)
{
	t_lst	*tmp;

	tmp = *head;
	if (*head == *lst)
		*head = (*lst)-> next;
	else
	{
		while (tmp -> next != *lst)
			tmp = tmp -> next;
	}
	tmp -> next = (*lst)-> next;
	free(*lst);
	*lst = NULL;
	return ;
}
