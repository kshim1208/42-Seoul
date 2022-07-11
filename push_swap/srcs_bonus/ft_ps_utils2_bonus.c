/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ps_utils2_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshim <kshim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 14:01:47 by kshim             #+#    #+#             */
/*   Updated: 2022/07/08 13:45:29 by kshim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

unsigned int	ft_ps_value_of_stack_node(t_detower *stack, unsigned int node)
{
	t_d_list		*tmp;
	unsigned int	i;

	tmp = stack -> head;
	i = 0;
	while (i < node)
	{
		if (i == node - 1)
		{
			return ((*(unsigned int *)tmp -> content));
		}
		else
		{
			tmp = tmp -> next;
			i++;
		}
	}
	return (0);
}
