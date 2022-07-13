/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ps_sorting_structs.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshim <kshim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 14:00:34 by kshim             #+#    #+#             */
/*   Updated: 2022/07/13 13:39:07 by kshim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_ps_struct_list	*ft_ps_set_struct_list(t_detower *stack_a,
		t_detower *stack_b, t_detower *oper_list)
{
	t_ps_struct_list	*new_list;

	new_list = (t_ps_struct_list *)malloc(sizeof(t_ps_struct_list));
	if (new_list == NULL)
		return (NULL);
	new_list -> st_a = stack_a;
	new_list -> st_b = stack_b;
	new_list -> list = oper_list;
	return (new_list);
}

t_sort_data	*ft_ps_sorting_data_init(
	unsigned int pivot_big, unsigned int pivot_small)
{
	t_sort_data	*new_data;

	new_data = (t_sort_data *)malloc(sizeof(t_sort_data));
	if (new_data == NULL)
		return (NULL);
	new_data -> pivot_a = pivot_big;
	new_data -> pivot_b = pivot_small;
	new_data -> pa = 0;
	new_data -> pb = 0;
	new_data -> ra = 0;
	new_data -> rb = 0;
	return (new_data);
}

t_d_list	*ft_ps_sort_list_node_init(int flag)
{
	t_d_list		*new_node;
	unsigned int	*oper_flag;

	new_node = (t_d_list *)malloc(sizeof(t_d_list));
	oper_flag = (unsigned int *)malloc(sizeof(unsigned int));
	if (new_node == NULL || oper_flag == NULL)
		return (NULL);
	*oper_flag = flag;
	new_node -> content = (void *)oper_flag;
	new_node -> prev = NULL;
	new_node -> next = NULL;
	return (new_node);
}

void	ft_ps_free_sort_data(t_sort_data **sort_data)
{
	(*sort_data)-> pivot_a = 0;
	(*sort_data)-> pivot_b = 0;
	(*sort_data)-> pa = 0;
	(*sort_data)-> pb = 0;
	(*sort_data)-> ra = 0;
	(*sort_data)-> rb = 0;
	free(*sort_data);
	*sort_data = NULL;
	return ;
}
