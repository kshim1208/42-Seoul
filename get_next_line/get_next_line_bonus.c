/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshim <kshim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 11:05:37 by kshim             #+#    #+#             */
/*   Updated: 2022/04/10 18:13:43 by kshim            ###   ########.fr       */
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
		work_lst -> check_result = get_buffer(fd, &(work_lst -> str_next),
				&(work_lst -> buffer));
		if (work_lst -> check_result <= 0 || work_lst -> buffer == NULL)
			break ;
		work_lst -> check_result = process_buffer(&(work_lst -> str_next),
				&(work_lst -> buffer), &ret);
		if (work_lst -> check_result <= -2)
			break ;
		free(work_lst -> buffer);
		work_lst -> buffer = NULL;
	}
	free_gnl(&(work_lst -> str_next), &(work_lst -> buffer),
		&ret, work_lst -> check_result);
	if (work_lst -> check_result == 0 || work_lst -> check_result == -1)
		free_lst(&gnl_head, &work_lst);
	return (ret);
}

t_lst	*gnl_select_lst(int fd, t_lst **gnl_head)
{
	t_lst	*work_lst;
	int		how_many;

	work_lst = *gnl_head;
	how_many = 0;
	while (++how_many)
	{	
		if (work_lst == NULL)
		{
			work_lst = (t_lst *)malloc(sizeof(t_lst));
			if (work_lst == NULL)
				return (NULL);
			if (how_many == 1)
				*gnl_head = work_lst;
			break ;
		}
		if (work_lst -> saved_fd == fd)
			return (work_lst);
		work_lst = work_lst -> next;
	}
	work_lst -> saved_fd = fd;
	work_lst -> str_next = NULL;
	work_lst -> buffer = NULL;
	work_lst -> next = NULL;
	return (work_lst);
}

ssize_t	process_buffer(char **str_next, char **buffer, char **ret)
{
	char	*tmp;

	if (*ret == NULL)
		*ret = ft_strjoin("", *buffer);
	else
	{
		tmp = ft_strjoin(*ret, *buffer);
		free(*ret);
		*ret = tmp;
	}
	if (*ret == NULL)
		return (-2);
	*str_next = ft_strchr(*ret, (int) '\n');
	if (*str_next != NULL)
	{
		tmp = ft_strndup(*ret, (*str_next - *ret + 1));
		if (tmp == NULL)
			return (-3);
		*str_next = ft_strndup(*ret + (*str_next - *ret + 1),
				ft_strlen(*ret + (*str_next - *ret + 1)));
		if (*str_next == NULL)
		{
			free(tmp);
			return (-3);
		}
		free(*ret);
		*ret = tmp;
	}
	return (1);
}

void	free_gnl(char **str_next, char **buffer, char **ret,
		ssize_t check_result)
{
	if (check_result <= 0)
	{
		free(*buffer);
		*buffer = NULL;
	}
	if ((check_result <= 0 && *str_next != NULL)
		|| ((*str_next != NULL) && (**str_next == '\0')))
	{
		free(*str_next);
		*str_next = NULL;
	}
	if (check_result == -1 && *ret != NULL)
	{
		free(*ret);
		*ret = NULL;
	}
}

void	free_lst(t_lst **gnl_head, t_lst **work_lst)
{
	t_lst	*tmp;

	tmp = *gnl_head;
	if (tmp == *work_lst)
		*gnl_head = (*work_lst)-> next;
	else
	{
		while (tmp -> next != *work_lst)
			tmp = tmp -> next;
	}
	tmp -> next = (*work_lst)-> next;
	free(*work_lst);
	*work_lst = NULL;
}
