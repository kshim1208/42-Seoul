/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshim <kshim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 11:05:37 by kshim             #+#    #+#             */
/*   Updated: 2022/04/08 15:26:21 by kshim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static t_lst	*gnl_head;
	t_lst			*work_lst;

	if (fd < 0)
		return (NULL);
	work_lst = gnl_select_lst(fd, &gnl_head);
	while (work_lst -> str_next == NULL || work_lst -> ret == NULL)
	{
		work_lst -> buffer = get_buffer(fd, &(work_lst -> str_next),
				&(work_lst -> check_eof));
		if (work_lst -> check_eof <= 0 || work_lst -> buffer == NULL)
			break ;
		process_buffer(&(work_lst -> str_next), &(work_lst -> buffer),
			&(work_lst -> ret));
		if (work_lst -> ret == NULL)
			break ;
	}
	free_gnl(&(work_lst -> str_next), &(work_lst -> buffer),
		&(work_lst -> ret), work_lst -> check_eof);
	return (work_lst -> ret);
}

t_lst	*gnl_select_lst(int fd, t_lst **gnl_head)
{
	t_lst	*work_lst;
	t_lst	*tmp;

	work_lst = NULL;
	if (*gnl_head == NULL)
	{
		*gnl_head = (t_lst *)malloc(sizeof(t_lst));
		work_lst = *gnl_head;
		work_lst -> saved_fd = fd;
	}
	else
	{
		tmp = *gnl_head;
		while (tmp != NULL)
		{
			if (tmp -> saved_fd == fd)
				work_lst = tmp;
			tmp = tmp -> next;
			return (work_lst);
		}
		tmp -> next = work_lst;
		work_lst = (t_lst *)malloc(sizeof(t_lst));
	}
	return (work_lst);
}

char	*get_buffer(int fd, char **str_next, ssize_t *check_eof)
{
	char		*buffer;

	if (*str_next != NULL)
	{
		buffer = *str_next;
		*str_next = NULL;
	}
	else
	{
		buffer = (char *)malloc(BUFFER_SIZE + 1);
		if (buffer == NULL)
			return (NULL);
		*check_eof = read(fd, buffer, BUFFER_SIZE);
		if (*check_eof <= 0)
			return (buffer);
		buffer[*check_eof] = '\0';
	}
	return (buffer);
}

void	process_buffer(char **str_next, char **buffer, char **ret)
{
	char	*tmp;

	*str_next = ft_strchr(*buffer, (int) '\n');
	if (*str_next != NULL)
	{
		tmp = ft_strndup(*buffer, (*str_next - *buffer + 1));
		*str_next = ft_strndup(*buffer + (*str_next - *buffer + 1),
				ft_strlen(*buffer + (*str_next - *buffer + 1)));
		free(*buffer);
		*buffer = tmp;
	}
	if (*ret == NULL)
		*ret = ft_strjoin("", *buffer);
	else
	{
		tmp = ft_strjoin(*ret, *buffer);
		free(*ret);
		*ret = tmp;
	}
	free(*buffer);
	*buffer = NULL;
}


void	free_gnl(char **str_next, char **buffer, char **ret, ssize_t check_eof)
{
	if (check_eof <= 0)
	{
		free(*buffer);
		*buffer = NULL;
	}
	if (check_eof == -1 && *ret != NULL)
	{
		free(*ret);
		*ret = NULL;
	}
	if (*str_next != NULL && **str_next == '\0')
	{
		free(*str_next);
		*str_next = NULL;
	}
}
