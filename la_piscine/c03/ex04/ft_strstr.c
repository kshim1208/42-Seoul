/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshim <kshim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 13:08:34 by kshim             #+#    #+#             */
/*   Updated: 2022/01/18 14:26:18 by kshim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

int	ft_strlen(char *src);

char	*ft_strstr(char *str, char *to_find)
{
	int		i;
	int		j;

	i = 0;
	if (ft_strlen(to_find) == 0)
		return (str);
	while (i < ft_strlen(str) && str[i] != '\0')
	{
		j = 0;
		if (str[i] == to_find[0])
		{
			while (j < ft_strlen(to_find) && to_find[j] != '\0')
			{
				if (str[i + j] == to_find[j])
					j++;
				else
					break ;
			}
			if (j == ft_strlen(to_find))
				return (str + i);
		}	
		i++;
	}
	return (NULL);
}

int	ft_strlen(char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		i++;
	}
	return (i);
}
