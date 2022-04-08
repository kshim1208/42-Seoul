/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshim <kshim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 12:28:11 by kshim             #+#    #+#             */
/*   Updated: 2022/04/08 12:56:48 by kshim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*str_next;
	char		*buffer;
	char		*ret;
	ssize_t		check_eof;

	ret = NULL;
	while (str_next == NULL || ret == NULL)
	{
		buffer = get_buffer(fd, &str_next, &check_eof);
		if (check_eof <= 0 || buffer == NULL)
			break ;
		process_buffer(&str_next, &buffer, &ret);
		if (ret == NULL)
			break ;
	}
	free_gnl(&str_next, &buffer, &ret, check_eof);
	return (ret);
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
