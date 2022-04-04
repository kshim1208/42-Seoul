/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshim <kshim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 12:28:11 by kshim             #+#    #+#             */
/*   Updated: 2022/04/04 12:18:55 by kshim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*str_next;
	char		*next_buffer;
	char		*ret;
	char		*tmp;

	ret = NULL;
	tmp = NULL;
	if (str_next != NULL)
	{
		/* tmp가 null이 될 수 있다. 다른 방법으로 마지막 자리를 탐색할까? */
		tmp = ft_strchr(++str_next, (int) '\n');
		ret = ft_strndup(str_next, (tmp - str_next + 1));
		*tmp = '\0';
		if (str_next != NULL)
		{
			tmp = ft_strdup(str_next + (tmp - str_next + 1));
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
			str_next = next_buffer;
			break ;
		}
		free(next_buffer);
	}
	*str_next = '\0';
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
	if (check_eof == -1)
		return (NULL);
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
