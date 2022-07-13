/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ps_sorting_5.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshim <kshim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 12:01:14 by kshim             #+#    #+#             */
/*   Updated: 2022/07/13 13:39:18 by kshim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	ft_ps_sort_5(t_ps_struct_list *struct_list, unsigned int biggest, int flag)
{
	if (flag == 0)
	{
		if ((ft_ps_is_sorted(struct_list -> st_a, biggest - 4, 5, 0)) != 1
			&& !(ft_ps_sort_5_stack_a(struct_list, biggest)))
			return (0);
	}
	else if (flag == 1)
	{
		if (ft_ps_is_sorted(struct_list -> st_b, biggest, 5, 1) != 1)
		{
			if (!(ft_ps_sort_5_stack_b(struct_list, biggest)))
				return (0);
		}
		else
		{
			if (!(ft_ps_sort_del_f_add_f(struct_list, 1))
				|| !(ft_ps_sort_del_f_add_f(struct_list, 1))
				|| !(ft_ps_sort_del_f_add_f(struct_list, 1))
				|| !(ft_ps_sort_del_f_add_f(struct_list, 1))
				|| !(ft_ps_sort_del_f_add_f(struct_list, 1)))
				return (0);
		}
	}
	return (1);
}

int	ft_ps_sort_5_stack_a(t_ps_struct_list *struct_list, unsigned int biggest)
{
	unsigned int	i;

	i = 0;
	while (i++ < 5)
	{
		if (ft_ps_value_of_stack_node(struct_list -> st_a, 1) == biggest
			|| ft_ps_value_of_stack_node(struct_list -> st_a, 1)
			== (biggest - 1))
		{
			if (!(ft_ps_sort_del_f_add_b(struct_list, 0)))
				return (0);
		}
		else
		{
			if (!(ft_ps_sort_del_f_add_f(struct_list, 0)))
				return (0);
		}
	}
	if (!(ft_ps_sort_del_b_add_f(struct_list, 0))
		|| !(ft_ps_sort_del_b_add_f(struct_list, 0))
		|| !(ft_ps_sort_2(struct_list, 0))
		|| !(ft_ps_sort_3(struct_list, biggest - 2, 1)))
		return (0);
	return (1);
}

int	ft_ps_sort_5_stack_b(t_ps_struct_list *struct_list, unsigned int biggest)
{
	unsigned int	i;

	i = 0;
	while (i++ < 5)
	{
		if (ft_ps_value_of_stack_node(struct_list -> st_b, 1) == biggest
			|| ft_ps_value_of_stack_node(struct_list -> st_b, 1)
			== (biggest - 1))
		{
			if (!(ft_ps_sort_del_f_add_f(struct_list, 1)))
				return (0);
		}
		else
		{
			if (!(ft_ps_sort_del_f_add_b(struct_list, 1)))
				return (0);
		}
	}
	if (!(ft_ps_sort_del_b_add_f(struct_list, 1))
		|| !(ft_ps_sort_del_b_add_f(struct_list, 1))
		|| !(ft_ps_sort_del_b_add_f(struct_list, 1))
		|| !(ft_ps_sort_2(struct_list, 0))
		|| !(ft_ps_sort_3(struct_list, biggest - 2, 1)))
		return (0);
	return (1);
}
