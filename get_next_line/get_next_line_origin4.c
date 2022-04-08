/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshim <kshim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 12:28:11 by kshim             #+#    #+#             */
/*   Updated: 2022/04/08 12:19:27 by kshim            ###   ########.fr       */
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
	if (str_next != NULL)
	{
		check_str_next(&str_next, &ret);
		if (ret == NULL)
			return (NULL);
	}
	while (str_next == NULL)
	{
		buffer = get_buffer(fd, &str_next, &check_eof);
		if (check_eof <= 0 || buffer == NULL)
			break ;
		assemble_line(&ret, &buffer);
	}
	free_gnl(&str_next, &buffer, &ret, check_eof);
	return (ret);
}

char	*get_buffer(int fd, char **str_next, ssize_t *check_eof)
{
	char		*tmp;
	char		*buffer;

	buffer = (char *)malloc(BUFFER_SIZE + 1);
	if (buffer == NULL)
		return (NULL);
	*check_eof = read(fd, buffer, BUFFER_SIZE);
	if (*check_eof <= 0)
		return (buffer);
	buffer[*check_eof] = '\0';
	*str_next = ft_strchr(buffer, (int) '\n');
	if (*str_next != NULL)
	{
		tmp = ft_strndup(buffer, (*str_next - buffer + 1));
		*str_next = ft_strndup(buffer + (*str_next - buffer + 1),
				ft_strlen(buffer + (*str_next - buffer + 1)));
		if (*str_next == NULL)
			return (NULL);
		free(buffer);
		buffer = tmp;
	}
	return (buffer);
}

void	assemble_line(char **ret, char **buffer)
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
	free(*buffer);
	*buffer = NULL;
}

void	check_str_next(char **str_next, char **ret)
{
	char	*tmp;
	size_t	len;

	tmp = ft_strchr(*str_next, (int) '\n');
	if (tmp == NULL)
	{
		*ret = ft_strndup(*str_next, ft_strlen(*str_next));
		free(*str_next);
		*str_next = NULL;
	}
	else
	{
		len = (size_t)((tmp - *str_next) + 1);
		*ret = ft_strndup(*str_next, len);
		tmp = ft_strndup(*str_next + len, ft_strlen(*str_next + len));
		free(*str_next);
		*str_next = tmp;
	}
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
