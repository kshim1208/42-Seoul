/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ps_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshim <kshim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 14:01:47 by kshim             #+#    #+#             */
/*   Updated: 2022/06/24 16:49:26 by kshim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	ft_ps_is_sorted(t_detower *stack,
		unsigned int start, unsigned int num, int descend)
{
	unsigned int	i;
	t_d_list		*tmp;

	tmp = stack -> head;
	i = 1;
	while (tmp != NULL && i < num)
	{
		if ((*(unsigned int *)tmp-> content) != (start))
			return (0);
		tmp = tmp -> next;
		if (descend == 0)
			start = start + i;
		else
			start = start - i;
	}
	return (1);
}

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

	tmp = list -> head;
	node = 1;
	while (tmp != NULL)
	{
		ft_ps_print_operation(ft_ps_value_of_stack_node(list, node));
		tmp = tmp -> next;
		node++;
	}
	return ;
}

void	ft_ps_print_operation(unsigned int oper_code)
{
	if (oper_code == 0)
		ft_printf("sa\n");
	else if (oper_code == 1)
		ft_printf("sb\n");
	else if (oper_code == 2)
		ft_printf("ss\n");
	else if (oper_code == 3)
		ft_printf("pa\n");
	else if (oper_code == 4)
		ft_printf("pb\n");
	else if (oper_code == 5)
		ft_printf("ra\n");
	else if (oper_code == 6)
		ft_printf("rb\n");
	else if (oper_code == 7)
		ft_printf("rr\n");
	else if (oper_code == 8)
		ft_printf("rra\n");
	else if (oper_code == 9)
		ft_printf("rrb\n");
	else if (oper_code == 10)
		ft_printf("rrr\n");
	return ;
}
