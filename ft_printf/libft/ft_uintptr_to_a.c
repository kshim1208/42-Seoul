/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uintptr_to_a.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshim <kshim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 09:45:54 by kshim             #+#    #+#             */
/*   Updated: 2022/04/25 09:51:17 by kshim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdint.h>

static int	how_long(uintptr_t n);
static void	distribute_char(char *str, uintptr_t n, int len);
static char	process_num_base(uintptr_t num);

char	*ft_uitoa_base(uintptr_t n)
{
	char	*str;
	int		len;

	len = how_long(n);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		return (NULL);
	str[len] = '\0';
	distribute_char(str, n, len);
	return (str);
}

static int	how_long(uintptr_t n)
{
	int			len;
	uintptr_t	temp;

	len = 0;
	temp = n;
	if (temp == 0)
		len++;
	while (temp != 0)
	{
		temp = temp / 16;
		len++;
	}
	return (len);
}

static void	distribute_char(char *str, uintptr_t n, int len)
{
	uintptr_t	temp;
	int			i;

	temp = n;
	i = len - 1;
	if (temp == 0)
		str[0] = '0';
	while (temp != 0)
	{
		str[i--] = process_num_base(temp % 16);
		temp = temp / 16;
	}
}

static char	process_num_base(uintptr_t num)
{
	char	c;

	c = 0;
	if (num >= 0 && num <= 9)
		c = num + '0';
	else if (num >= 10 && num <= 15)
		c = (char)(num + 87);
	return (c);
}
