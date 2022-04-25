/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshim <kshim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 09:05:37 by kshim             #+#    #+#             */
/*   Updated: 2022/04/25 09:37:19 by kshim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	how_long(unsigned int n, int base);
static void	distribute_char(char *str, unsigned int n, int len, int base);
static char	process_num_base(unsigned int num, int base);

char	*ft_uitoa_base(unsigned int n, int base)
{
	char	*str;
	int		len;

	if (base != 10 && base != 16)
		return (NULL);
	len = how_long(n, base);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		return (NULL);
	str[len] = '\0';
	distribute_char(str, n, len, base);
	return (str);
}

static int	how_long(unsigned int n, int base)
{
	int				len;
	unsigned int	temp;

	len = 0;
	temp = n;
	if (temp == 0)
		len++;
	while (temp != 0)
	{
		temp = temp / base;
		len++;
	}
	return (len);
}

static void	distribute_char(char *str, unsigned int n, int len, int base)
{
	unsigned int	temp;
	int				i;

	temp = n;
	i = len - 1;
	if (temp == 0)
		str[0] = '0';
	while (temp != 0)
	{
		str[i--] = process_num_base(temp % base, base);
		temp = temp / base;
	}
}

static char	process_num_base(unsigned int num, int base)
{
	char	c;
	
	c = 0;
	if (base == 10)
		c = num + '0';
	else if (base == 16)
	{
		if (num >= 0 && num <= 9)
			c = num + '0';
		else if (num >= 10 && num <= 15)
			c = (char)(num + 87);
	}
	return (c);
}
