/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshim <kshim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 13:42:36 by kshim             #+#    #+#             */
/*   Updated: 2022/01/18 15:05:30 by kshim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
unsigned int	ft_strlen(char *str);

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	deslen;

	i = 0;
	deslen = ft_strlen(dest);
	if (size <= deslen)
		return (size + ft_strlen(src));
	while (src[i] != '\0' && deslen + i + 1 < size)
	{
		dest[deslen + i] = src[i];
		i++;
	}
	if (size > 0)
		dest[deslen + i] = '\0';
	return (deslen + ft_strlen(src));
}

unsigned int	ft_strlen(char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}
