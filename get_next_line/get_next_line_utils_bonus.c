/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshim <kshim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 11:10:38 by kshim             #+#    #+#             */
/*   Updated: 2022/04/12 15:42:17 by kshim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line_bonus.h"

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

char	*join_buffer_to_ret(char *s1, char *s2)
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
	if (s1 != NULL)
		free(s1);
	while (i < len && s2[j] != '\0')
		str[i++] = s2[j++];
	str[i] = '\0';
	return (str);
}

ssize_t	get_buffer(int fd, t_lst *lst)
{
	ssize_t	check_result;

	check_result = 0;
	if (lst -> buffer != NULL)
	{
		free(lst -> buffer);
		lst -> buffer = NULL;
	}
	if (lst -> str_next != NULL)
	{
		lst -> buffer = lst -> str_next;
		lst -> str_next = NULL;
		check_result = ft_strlen(lst -> buffer);
	}
	else
	{
		lst -> buffer = (char *)malloc(BUFFER_SIZE + 1);
		if (lst -> buffer == NULL)
			return (-1);
		check_result = read(fd, lst -> buffer, BUFFER_SIZE);
		if (check_result <= 0)
			return (check_result);
		(lst -> buffer)[check_result] = '\0';
	}
	return (check_result);
}
