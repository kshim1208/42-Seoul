/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshim <kshim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 12:21:58 by kshim             #+#    #+#             */
/*   Updated: 2022/01/23 17:34:38 by kshim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
unsigned int	ft_sqrt(int nb, unsigned int i);
int				ft_is_prime_rec(int nb, unsigned int sqrt, unsigned int i);

int	ft_is_prime(int nb)
{
	int	sqrt;

	if (nb <= 1)
		return (0);
	else if (nb == 2)
		return (1);
	else
	{
		sqrt = ft_sqrt(nb, 1);
		return (ft_is_prime_rec(nb, sqrt, 2));
	}
}

int	ft_is_prime_rec(int nb, unsigned int sqrt, unsigned int i)
{
	if (nb % i == 0)
		return (0);
	else if (i > sqrt)
		return (1);
	else
		return (ft_is_prime_rec(nb, sqrt, i + 1));
}

unsigned int	ft_sqrt(int nb, unsigned int i)
{
	if ((unsigned)nb == i * i)
		return (i);
	else if ((unsigned)nb < i * i)
		return (i + 1);
	else
		return (ft_sqrt(nb, i + 1));
}
