/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshim <kshim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 19:25:45 by kshim             #+#    #+#             */
/*   Updated: 2022/01/24 10:21:28 by kshim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_power(int nb, int power)
{	
	if (power == 0 && nb == 0)
		return (1);
	else if (power == 0 && nb != 0)
		return (1);
	else if (power < 0)
		return (0);
	return (nb * (ft_recursive_power(nb, power - 1)));
}
