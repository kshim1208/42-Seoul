/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshim <kshim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 13:59:34 by kshim             #+#    #+#             */
/*   Updated: 2022/01/27 17:24:53 by kshim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
int		ft_count_sep(char *str, char *charset);
char	**ft_distribute_str(char **strs, char *str, char *charset);
void	ft_strncpy(char *dest, char *src, int n);
int		ft_sep(char c, char *charset);

char	**ft_split(char *str, char *charset)
{
	char	**strs;
	int		len;

	len = ft_count_sep(str, charset);
	strs = (char **)malloc(sizeof(char *) * (len + 1));
	if (strs == NULL)
		return (NULL);
	strs[len] = 0;
	return (ft_distribute_str(strs, str, charset));
}

int	ft_count_sep(char *str, char *charset)
{
	int	i;
	int	ret;

	ret = 0;
	i = 0;
	if (ft_sep(str[0], charset) == -1)
		ret++;
	while (str[i] != '\0')
	{
		if (ft_sep(str[i], charset) != -1)
		{
			if (ft_sep(str[i + 1], charset) == -1)
				ret++;
			i++;
		}
		else
			i++;
	}
	return (ret);
}

char	**ft_distribute_str(char **strs, char *str, char *charset)
{
	int	i;
	int	j;
	int	idx;

	i = 0;
	idx = 0;
	while (str[i] != '\0')
	{
		if (ft_sep(str[i], charset) == -1)
		{
			j = 0;
			while (ft_sep(str[i + j], charset) == -1 && str[i + j] != '\0')
				j++;
			strs[idx] = (char *)malloc(sizeof(char) * (j + 1));
			if (strs[idx] == NULL)
				return (NULL);
			ft_strncpy(strs[idx], (str + i), j);
			i = i + j;
			idx++;
		}
		else
			i++;
	}
	return (strs);
}

void	ft_strncpy(char *dest, char *src, int n)
{
	int	i;

	i = 0;
	while (src[i] != '\0' && i < n)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
}

int	ft_sep(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i] != '\0')
	{
		if (charset[i] == c)
			return (i);
		i++;
	}
	if (c == '\0')
		return (-2);
	return (-1);
}
