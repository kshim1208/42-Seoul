/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshim <kshim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 15:05:02 by kshim             #+#    #+#             */
/*   Updated: 2022/04/12 14:42:10 by kshim            ###   ########.fr       */
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

char	*join_buffer_to_ret(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	size_t	len;
	char	*str;

	if (s1 == NULL)
		len = ft_strlen(s2);
	else
		len = ft_strlen(s1) + ft_strlen(s2);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (i < len && s1 != NULL && s1[i] != '\0')
		str[i++] = s1[j++];
	j = 0;
	while (i < len && s2[j] != '\0')
		str[i++] = s2[j++];
	str[i] = '\0';
	return (str);
}
