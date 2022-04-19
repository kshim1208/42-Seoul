/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshim <kshim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 11:10:38 by kshim             #+#    #+#             */
/*   Updated: 2022/04/14 08:57:07 by kshim            ###   ########.fr       */
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

void	ft_free_elements_gnl(t_lst *lst, char **ret)
{
	if (lst -> buffer != NULL)
	{
		free(lst -> buffer);
		lst -> buffer = NULL;
	}
	if ((lst -> check_result <= 0 && lst -> str_next != NULL)
		|| ((lst -> str_next != NULL) && (*(lst -> str_next) == '\0')))
	{
		free(lst -> str_next);
		lst -> str_next = NULL;
	}
	if (lst -> check_result == -1 && *ret != NULL)
	{
		free(*ret);
		*ret = NULL;
	}
	return ;
}

void	ft_free_lst_gnl(t_lst **head, t_lst **lst)
{
	t_lst	*tmp;

	tmp = *head;
	if (*head == *lst)
		*head = (*lst)-> next;
	else
	{
		while (tmp -> next != *lst)
			tmp = tmp -> next;
	}
	tmp -> next = (*lst)-> next;
	free(*lst);
	*lst = NULL;
	return ;
}
