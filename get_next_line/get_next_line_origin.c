/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshim <kshim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 12:28:11 by kshim             #+#    #+#             */
/*   Updated: 2022/04/06 09:03:12 by kshim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*str_next;
	char		*next_buffer;
	char		*ret;
	char		*tmp;
	size_t		len;

	ret = NULL;
	tmp = NULL;
	if (str_next != NULL)
	{
		tmp = ft_strchr(str_next, (int) '\n');
		if (tmp == NULL)
			len = ft_strlen(str_next);
		else
			len = (size_t)(tmp - str_next + 1);
		ret = ft_strndup(str_next, len);
		if (*(str_next + len) != '\0')
		{
			tmp = ft_strdup(str_next + len);
			free(str_next);
			str_next = tmp;
			return (ret);
		}
		free(str_next);
		str_next = NULL;
	}
	while (str_next == NULL)
	{
		next_buffer = get_line(fd, &str_next);
		if (next_buffer == NULL)
		{
			free(ret);
			return (NULL);
		}
		if (ret == NULL)
			ret = ft_strjoin("", next_buffer);
		else
		{
			tmp = ft_strjoin(ret, next_buffer);
			free(ret);
			ret = tmp;
		}
		if (str_next != NULL)
		{
			free(next_buffer);
			break ;
		}
		free(next_buffer);
	}
	return (ret);
}

char	*get_line(int fd, char **str_next)
{
	char		*buffer;
	char		*tmp;
	ssize_t		check_eof;

	buffer = (char *)malloc(BUFFER_SIZE + 1);
	if (buffer == NULL)
		return (NULL);
	buffer[BUFFER_SIZE] = '\0';
	check_eof = read(fd, buffer, BUFFER_SIZE);
	if (check_eof == -1 || check_eof == 0)
	{
		free(buffer);
		return (NULL);
	}
	*str_next = ft_strchr(buffer, (int) '\n');
	if (*str_next != NULL)
	{
		tmp = ft_strndup(buffer, (*str_next - buffer + 1));
		*str_next = ft_strdup(buffer + (*str_next - buffer + 1));
		free(buffer);
		buffer = tmp;
	}
	return (buffer);
}
