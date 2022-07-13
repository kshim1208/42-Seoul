/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ps_sorting_move.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshim <kshim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 16:41:21 by kshim             #+#    #+#             */
/*   Updated: 2022/07/13 13:39:20 by kshim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	ft_ps_sort_a_to_b(t_ps_struct_list *struct_list,
	t_sort_data *sort_data, unsigned int num)
{
	unsigned int	i;

	i = 0;
	while (i < num)
	{
		if (ft_ps_value_of_stack_node(struct_list -> st_a, 1)
			> sort_data -> pivot_a)
		{
			if (!(ft_ps_sort_del_f_add_b(struct_list, 0)))
				return (0);
			(sort_data -> ra)++;
		}
		else if (ft_ps_value_of_stack_node(struct_list -> st_a, 1)
			<= sort_data -> pivot_a)
		{
			if (!(ft_ps_sort_a_to_b_below_piv_a(struct_list, sort_data)))
				return (0);
		}
		i++;
	}
	return (1);
}

int	ft_ps_sort_b_to_a(t_ps_struct_list *struct_list,
	t_sort_data *sort_data, unsigned int num)
{
	unsigned int	i;

	i = 0;
	while (i < num)
	{
		if (ft_ps_value_of_stack_node(struct_list -> st_b, 1)
			> sort_data -> pivot_b)
		{
			if (!(ft_ps_sort_a_to_b_more_than_piv_b(struct_list, sort_data)))
				return (0);
		}
		else if (ft_ps_value_of_stack_node(struct_list -> st_b, 1)
			<= sort_data -> pivot_b)
		{
			if (!(ft_ps_sort_del_f_add_b(struct_list, 1)))
				return (0);
			(sort_data -> rb)++;
		}
		i++;
	}
	return (1);
}

int	ft_ps_sort_a_to_b_below_piv_a(t_ps_struct_list *struct_list,
	t_sort_data *sort_data)
{
	if (!(ft_ps_sort_del_f_add_f(struct_list, 0)))
		return (0);
	(sort_data -> pb)++;
	if (ft_ps_value_of_stack_node(struct_list -> st_b, 1)
		> sort_data -> pivot_b)
	{
		if (!(ft_ps_sort_del_f_add_b(struct_list, 1)))
			return (0);
		(sort_data -> rb)++;
	}
	return (1);
}

int	ft_ps_sort_a_to_b_more_than_piv_b(t_ps_struct_list *struct_list,
	t_sort_data *sort_data)
{
	if (!(ft_ps_sort_del_f_add_f(struct_list, 1)))
		return (0);
	(sort_data -> pa)++;
	if (ft_ps_value_of_stack_node(struct_list -> st_a, 1)
		<= sort_data -> pivot_a)
	{
		if (!(ft_ps_sort_del_f_add_b(struct_list, 0)))
			return (0);
		(sort_data -> ra)++;
	}
	return (1);
}
