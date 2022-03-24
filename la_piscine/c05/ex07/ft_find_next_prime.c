/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshim <kshim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 12:57:01 by kshim             #+#    #+#             */
/*   Updated: 2022/01/25 09:49:29 by kshim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
unsigned int	ft_sqrt(int nb, unsigned int i);
int				ft_is_prime(int nb, unsigned int sqrt, unsigned int i);

int	ft_find_next_prime(int nb)
{
	unsigned int	sqrt;

	if (nb <= 2)
		return (2);
	sqrt = ft_sqrt(nb, 1);
	if (ft_is_prime(nb, sqrt, 2) == 1)
		return (nb);
	else
	{
		if (nb % 2 == 0)
			return (ft_find_next_prime(nb + 1));
		return (ft_find_next_prime(nb + 2));
	}
}

unsigned int	ft_sqrt(int nb, unsigned int i)
{
	if ((unsigned int)nb == i * i)
		return (i);
	else if ((unsigned int)nb < i * i)
		return (i + 1);
	else
		return (ft_sqrt(nb, i + 1));
}

int	ft_is_prime(int nb, unsigned int sqrt, unsigned int i)
{
	if (nb % i == 0)
		return (0);
	else if (i > sqrt)
		return (1);
	else
		return (ft_is_prime(nb, sqrt, i + 1));
}
