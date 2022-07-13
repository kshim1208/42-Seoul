/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ps_sorting_2_3.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshim <kshim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 12:53:40 by kshim             #+#    #+#             */
/*   Updated: 2022/07/13 13:39:18 by kshim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	ft_ps_sort_2(t_ps_struct_list *struct_list, int flag)
{
	if (flag == 0)
	{
		if (ft_ps_value_of_stack_node(struct_list -> st_a, 1)
			> ft_ps_value_of_stack_node(struct_list -> st_a, 2))
		{
			if (!(ft_ps_sort_swap(struct_list, 0)))
				return (0);
		}
	}
	else if (flag == 1)
	{
		if (ft_ps_value_of_stack_node(struct_list -> st_b, 1)
			<ft_ps_value_of_stack_node(struct_list -> st_b, 2))
		{
			if (!(ft_ps_sort_swap(struct_list, 1)))
				return (0);
		}
		if (!(ft_ps_sort_del_f_add_f(struct_list, 1))
			|| !(ft_ps_sort_del_f_add_f(struct_list, 1)))
			return (0);
	}
	return (1);
}

int	ft_ps_sort_3(t_ps_struct_list *struct_list,
	unsigned int biggest, int flag)
{
	if (flag == 0)
	{
		if (ft_ps_is_sorted(struct_list -> st_a, biggest - 2, 3, 0) != 1)
		{
			if (!(ft_ps_sort_3_set_a_to_b(struct_list, biggest)))
				return (0);
		}
	}
	else if (flag == 1)
	{
		if (ft_ps_is_sorted(struct_list -> st_b, biggest, 3, 1) != 1)
		{
			if (!(ft_ps_sort_3_set_b_to_a(struct_list, biggest)))
				return (0);
		}
		else
		{
			if (!(ft_ps_sort_del_f_add_f(struct_list, 1))
				|| !(ft_ps_sort_del_f_add_f(struct_list, 1))
				|| !(ft_ps_sort_del_f_add_f(struct_list, 1)))
				return (0);
		}
	}
	return (1);
}

int	ft_ps_sort_3_set_a_to_b(
	t_ps_struct_list *struct_list, unsigned int biggest)
{
	if (ft_ps_value_of_stack_node(struct_list -> st_a, 1) == biggest)
	{
		if (!(ft_ps_sort_del_f_add_b(struct_list, 0))
			|| !(ft_ps_sort_del_f_add_f(struct_list, 0))
			|| !(ft_ps_sort_del_b_add_f(struct_list, 0))
			|| !(ft_ps_sort_swap(struct_list, 0))
			|| !(ft_ps_sort_del_f_add_f(struct_list, 1))
			|| !(ft_ps_sort_2(struct_list, 0)))
			return (0);
	}
	else if (ft_ps_value_of_stack_node(struct_list -> st_a, 2) == biggest)
	{
		if (!(ft_ps_sort_del_f_add_f(struct_list, 0))
			|| !(ft_ps_sort_2(struct_list, 0))
			|| !(ft_ps_sort_del_f_add_f(struct_list, 1))
			|| !(ft_ps_sort_2(struct_list, 0)))
			return (0);
	}
	else
	{
		if (!(ft_ps_sort_2(struct_list, 0)))
			return (0);
	}
	return (1);
}

int	ft_ps_sort_3_set_b_to_a(
		t_ps_struct_list *struct_list, unsigned int biggest)
{
	if (ft_ps_value_of_stack_node(struct_list -> st_b, 1) == biggest)
	{
		if (!(ft_ps_sort_del_f_add_f(struct_list, 1))
			|| !(ft_ps_sort_2(struct_list, 1)))
			return (0);
	}
	else if (ft_ps_value_of_stack_node(struct_list -> st_b, 2) == biggest)
	{
		if (!(ft_ps_sort_swap(struct_list, 1))
			|| !(ft_ps_sort_del_f_add_f(struct_list, 1))
			|| !(ft_ps_sort_2(struct_list, 1)))
			return (0);
	}
	else
	{
		if (!(ft_ps_sort_del_f_add_f(struct_list, 1))
			|| !(ft_ps_sort_swap(struct_list, 1))
			|| !(ft_ps_sort_del_f_add_f(struct_list, 1))
			|| !(ft_ps_sort_swap(struct_list, 0))
			|| !ft_ps_sort_del_f_add_f(struct_list, 1)
			|| !(ft_ps_sort_2(struct_list, 0)))
			return (0);
	}
	return (1);
}
