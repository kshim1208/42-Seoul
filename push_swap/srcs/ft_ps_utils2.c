/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ps_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshim <kshim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 14:01:47 by kshim             #+#    #+#             */
/*   Updated: 2022/07/13 13:42:50 by kshim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include "../libft/ft_printf.h"

unsigned int	ft_ps_value_of_stack_node(t_detower *stack, unsigned int node)
{
	unsigned int	i;
	t_d_list		*tmp;

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
	arr[sa] = "sa";
	arr[sb]= "sb";
	arr[ss]= "ss";
	arr[pa]= "pa";
	arr[pb]= "pb";
	arr[ra]= "ra";
	arr[rb]= "rb";
	arr[rr]= "rr";
	arr[rra]= "rra";
	arr[rrb]= "rrb";
	arr[rrr]= "rrr";
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
