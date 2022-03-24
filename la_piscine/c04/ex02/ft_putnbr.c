/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshim <kshim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 16:24:55 by kshim             #+#    #+#             */
/*   Updated: 2022/01/24 10:41:50 by kshim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
void	ft_calldigit(int x);
void	ft_putdigit(int n);

void	ft_putnbr(int nb)
{
	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	else if (nb < 0)
	{
		write(1, "-", 1);
		nb = -nb;
	}
	ft_calldigit(nb);
}

void	ft_calldigit(int x)
{
	if (x >= 10)
	{
		ft_calldigit(x / 10);
		ft_putdigit(x % 10);
	}
	else
		ft_putdigit(x % 10);
}

void	ft_putdigit(int n)
{
	n = n + 48;
	write(1, &n, 1);
}
