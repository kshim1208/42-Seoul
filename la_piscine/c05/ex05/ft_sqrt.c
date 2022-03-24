/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshim <kshim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 15:58:40 by kshim             #+#    #+#             */
/*   Updated: 2022/01/23 21:05:14 by kshim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
unsigned int	ft_sqrt_rec(int nb, unsigned int i);

int	ft_sqrt(int nb)
{	
	if (nb == 0)
		return (0);
	else if (nb == 1)
		return (1);
	else if (nb < 0)
		return (0);
	return (ft_sqrt_rec(nb, 1));
}

unsigned int	ft_sqrt_rec(int nb, unsigned int i)
{	
	if ((unsigned int)nb == i * i)
		return (i);
	else if ((unsigned int)nb < i * i)
		return (0);
	else
		return (ft_sqrt_rec(nb, i + 1));
}
