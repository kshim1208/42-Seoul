/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ps_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshim <kshim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 14:01:47 by kshim             #+#    #+#             */
/*   Updated: 2022/07/11 17:29:34 by kshim            ###   ########.fr       */
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

void	ft_ps_print_oper_list(t_detower *list)
{
	t_d_list		*tmp;
	unsigned int	node;
	char			*arr[11];

	tmp = list -> head;
	node = 1;
	ft_ps_print_oper_table_set(arr);
	while (tmp != NULL)
	{
		ft_ps_print_operation(ft_ps_value_of_stack_node(list, node), arr);
		tmp = tmp -> next;
		node++;
	}
	return ;
}

void	ft_ps_print_oper_table_set(char *arr[])
{
	arr[sa] = "sa\0";
	arr[sb]= "sb\0";
	arr[ss]= "ss\0";
	arr[pa]= "pa\0";
	arr[pb]= "pb\0";
	arr[ra]= "ra\0";
	arr[rb]= "rb\0";
	arr[rr]= "rr\0";
	arr[rra]= "rra\0";
	arr[rrb]= "rrb\0";
	arr[rrr]= "rrr\0";
	return ;
}

int	ft_ps_print_operation(unsigned int oper_code, char *arr[])
{
	unsigned int	idx;

	idx = 0;
	while (idx < 11)
	{
		if (oper_code == idx)
		{
			if (!ft_printf("%s\n", arr[idx]))
				return (0);
		}
		idx++;
	}
	return (1);
}
