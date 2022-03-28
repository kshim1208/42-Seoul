/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshim <kshim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 12:28:11 by kshim             #+#    #+#             */
/*   Updated: 2022/03/28 15:34:17 by kshim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*str_next;
	char		*next_buffer;
	char		*tmp;

	if (str_next != NULL)
	{
		tmp = ft_strchr(++str_next, (int) '\n');
		*tmp = '\0';
		str_next = tmp;
		if (tmp != NULL)
			return(tmp = ft_strdup(str_next));
		else
			tmp = ft_strdup(str_next);
	}
	while (*str_next != '\n')
	{
		next_buffer = get_line(fd, &str_next);
		if (*str_next == '\n')
			break;
		if (tmp == NULL)
			tmp = ft_strjoin("", next_buffer);
		else
			tmp = ft_strjoin(tmp, next_buffer);	
	}
	
	*str_next == '\0';
	

	return ();
}

char	*get_line(int fd, char **str_next)
{
	char		*buffer;

	buffer = (char *)malloc(BUFFER_SIZE + 1);
	if (buffer == NULL)
		return (NULL);
	buffer[BUFFER_SIZE] == '\0';
	read(fd, buffer, BUFFER_SIZE);
	*str_next = ft_strchr(buffer, (int) '\n');
	return (buffer);
}
