/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshim <kshim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 15:05:02 by kshim             #+#    #+#             */
/*   Updated: 2022/04/14 08:56:25 by kshim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	size_t	i;
	char	x;

	i = 0;
	x = (char)c;
	while (s[i] != x)
	{
		if (s[i] == '\0')
			return (NULL);
		i++;
	}
	return ((char *)(s + i));
}

char	*ft_strndup(const char *s1, size_t n)
{
	char	*str;
	size_t	len;
	size_t	i;

	len = ft_strlen(s1);
	if (len > n)
		len = n;
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		str[i] = s1[i];
		i++;
	}
	str[len] = '\0';
	return (str);
}

void	ft_free_gnl(char **str_next, char **buffer, char **ret,
		ssize_t check_result)
{
	if (*buffer != NULL)
	{
		free(*buffer);
		*buffer = NULL;
	}
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
	return ;
}
