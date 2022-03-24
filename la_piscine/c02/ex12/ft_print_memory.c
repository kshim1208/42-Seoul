/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshim <kshim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 11:06:42 by kshim             #+#    #+#             */
/*   Updated: 2022/01/22 21:19:54 by kshim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	print_address(unsigned long long str);
void	put_hex(unsigned long long num, int digit);
void	print_last(unsigned char *str, unsigned int how_many, int x);
void	put_str(char *c, int n);

void	*ft_print_memory(void *addr, unsigned int size)
{
	unsigned char	*str;
	unsigned int	i;
	unsigned int	how_many;

	str = addr;
	i = 0;
	while (i * 16 < size)
	{
		if (size >= 16)
			how_many = 16;
		if (size - (16 * i) < 16)
			how_many = size % 16;
		print_address((unsigned long long)(str + i * 16));
		print_last(str, how_many, i * 16);
		write(1, "\n", 1);
		i++;
	}
	return (addr);
}

void	print_address(unsigned long long str)
{
	int					i;
	unsigned long long	check;

	i = 0;
	check = str;
	while (i < 15)
	{
		if (check != 0)
		{
			check = check / 16;
			i++;
		}
		else
			break ;
	}
	put_str("0000000000000000", 16 - i);
	put_hex(str, 1);
	put_str(": ", 2);
}

void	put_hex(unsigned long long num, int digit)
{
	int		i;
	char	*hex;

	i = 0;
	hex = "0123456789abcdef";
	if (num < 16 && digit == 1)
	{
		put_str("0", 1);
		put_str(&hex[num % 16], 1);
	}
	else if (num >= 16)
	{
		put_hex(num / 16, digit + 1);
		put_str(&hex[num % 16], 1);
	}
	else
		put_str(&hex[num % 16], 1);
}

void	print_last(unsigned char *str, unsigned int how_many, int x)
{
	unsigned int		i;	
	unsigned long long	hex_val;
	int					padding;

	i = 0;
	padding = 0;
	while (i < how_many)
	{
		hex_val = *(str + x + i);
		put_hex(hex_val, 1);
		if ((i + 1) % 2 == 0)
			put_str(" ", 1);
		i++;
	}
	if (how_many < 16)
	{
		padding = ((16 - how_many) * 2) + (8 - (how_many / 2));
		put_str("                                        ", padding);
	}
	i = 0;
	while (i < how_many)
	{	
		put_str((char *)(str + i + x), 1);
		i++;
	}
}

void	put_str(char *c, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{	
		if (c[i] < 32 || c[i] > 126)
			write(1, ".", 1);
		else
			write(1, &c[i], 1);
		i++;
	}
}
