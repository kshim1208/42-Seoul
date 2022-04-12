/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshim <kshim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 12:28:11 by kshim             #+#    #+#             */
/*   Updated: 2022/04/12 14:56:32 by kshim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*str_next;
	char		*buffer;
	char		*ret;
	ssize_t		check_result;

	if (fd < 0)
		return (NULL);
	ret = NULL;
	buffer = NULL;
	while (str_next == NULL || ret == NULL)
	{
		check_result = get_buffer(fd, &str_next, &buffer);
		if (check_result <= 0 || buffer == NULL)
			break ;
		check_result = process_buffer(&str_next, &buffer, &ret);
		if (check_result <= -1)
			break ;
	}
	free_gnl(&str_next, &buffer, &ret, check_result);
	return (ret);
}

ssize_t	get_buffer(int fd, char **str_next, char **buffer)
{
	ssize_t	check_result;

	check_result = 0;
	if (*buffer != NULL)
	{
		free(*buffer);
		*buffer = NULL;
	}
	if (*str_next != NULL)
	{
		*buffer = *str_next;
		*str_next = NULL;
		check_result = ft_strlen(*buffer);
	}
	else
	{
		*buffer = (char *)malloc(BUFFER_SIZE + 1);
		if (*buffer == NULL)
			return (-1);
		check_result = read(fd, *buffer, BUFFER_SIZE);
		if (check_result <= 0)
			return (check_result);
		(*buffer)[check_result] = '\0';
	}
	return (check_result);
}

ssize_t	process_buffer(char **str_next, char **buffer, char **ret)
{
	char	*tmp;

	*str_next = ft_strchr(*buffer, (int) '\n');
	if (*str_next != NULL)
	{
		tmp = ft_strndup(*buffer, (*str_next - *buffer + 1));
		if (tmp == NULL)
			return (-1);
		*str_next = ft_strndup(*buffer + (*str_next - *buffer + 1),
				ft_strlen(*buffer + (*str_next - *buffer + 1)));
		if (*str_next == NULL)
		{
			free(tmp);
			return (-1);
		}
		free(*buffer);
		*buffer = tmp;
	}
	tmp = join_buffer_to_ret(*ret, *buffer);
	if (tmp == NULL)
		return (-1);
	if (*ret != NULL)
		free(*ret);
	*ret = tmp;
	return (1);
}

void	free_gnl(char **str_next, char **buffer, char **ret,
		ssize_t check_result)
{
	free(*buffer);
	*buffer = NULL;
	if ((check_result <= 0 && *str_next != NULL)
		|| (*str_next != NULL && **str_next == '\0'))
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
