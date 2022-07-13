/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ps_sorting_only_3_4.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshim <kshim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 12:55:38 by kshim             #+#    #+#             */
/*   Updated: 2022/07/13 13:39:22 by kshim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	ft_ps_sort_only_3(t_ps_struct_list *struct_list, unsigned int num)
{
	unsigned int	biggest;

	biggest = num - 1;
	if ((ft_ps_value_of_stack_node(struct_list -> st_a, 1) == biggest)
		|| (ft_ps_value_of_stack_node(struct_list -> st_a, 2) == biggest))
	{
		if (!(ft_ps_sort_only_3_other_cases(struct_list, biggest)))
			return (0);
	}
	else if (ft_ps_value_of_stack_node(struct_list -> st_a, 2) == biggest)
	{
		if (!(ft_ps_sort_del_b_add_f(struct_list, 0)))
			return (0);
		if (ft_ps_value_of_stack_node(struct_list -> st_a, 1) == biggest - 1)
		{
			if (!(ft_ps_sort_2(struct_list, 0)))
				return (0);
		}
	}
	else
	{
		if (!(ft_ps_sort_2(struct_list, 0)))
			return (0);
	}
	return (1);
}

int	ft_ps_sort_only_3_other_cases(t_ps_struct_list *struct_list,
	unsigned int biggest)
{
	if (ft_ps_value_of_stack_node(struct_list -> st_a, 1) == biggest)
	{
		if (ft_ps_value_of_stack_node(struct_list -> st_a, 2) == (biggest - 1))
		{
			if (!(ft_ps_sort_del_f_add_b(struct_list, 0))
				|| !(ft_ps_sort_2(struct_list, 0)))
				return (0);
		}
		else
		{
			if (!(ft_ps_sort_del_f_add_b(struct_list, 0)))
				return (0);
		}
	}
	else if (ft_ps_value_of_stack_node(struct_list -> st_a, 2) == biggest)
	{
		if (!(ft_ps_sort_del_b_add_f(struct_list, 0)))
			return (0);
		if (ft_ps_value_of_stack_node(struct_list -> st_a, 1) == biggest - 1)
		{
			if (!(ft_ps_sort_2(struct_list, 0)))
				return (0);
		}
	}
	return (1);
}

int	ft_ps_sort_only_4(t_ps_struct_list *struct_list, unsigned int num)
{
	if (ft_ps_value_of_stack_node(struct_list -> st_a, 1) == num - 1)
	{
		if (!(ft_ps_sort_only_4_node_move(struct_list)))
			return (0);
	}
	else if (ft_ps_value_of_stack_node(struct_list -> st_a, 2) == num - 1)
	{
		if (!(ft_ps_sort_del_f_add_b(struct_list, 0))
			|| !(ft_ps_sort_only_4_node_move(struct_list)))
			return (0);
	}
	else if (ft_ps_value_of_stack_node(struct_list -> st_a, 3) == num - 1)
	{
		if (!(ft_ps_sort_del_b_add_f(struct_list, 0))
			|| !(ft_ps_sort_del_b_add_f(struct_list, 0))
			|| !(ft_ps_sort_only_4_node_move(struct_list)))
			return (0);
	}
	else
	{
		if (!(ft_ps_sort_del_b_add_f(struct_list, 0))
			|| !(ft_ps_sort_only_4_node_move(struct_list)))
			return (0);
	}
	return (1);
}

int	ft_ps_sort_only_4_node_move(t_ps_struct_list *struct_list)
{
	if (!(ft_ps_sort_del_f_add_f(struct_list, 0))
		|| !(ft_ps_sort_only_3(struct_list, 3))
		|| !(ft_ps_sort_del_f_add_f(struct_list, 1))
		|| !(ft_ps_sort_del_f_add_b(struct_list, 0)))
		return (0);
	return (1);
}
