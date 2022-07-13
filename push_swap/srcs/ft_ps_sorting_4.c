/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ps_sorting_4.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshim <kshim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 11:18:26 by kshim             #+#    #+#             */
/*   Updated: 2022/07/13 13:39:17 by kshim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	ft_ps_sort_4(t_ps_struct_list *struct_list,
		unsigned int biggest, int flag)
{
	if (flag == 0)
	{
		if (ft_ps_is_sorted(struct_list -> st_a, biggest - 3, 4, 0) != 1
			&& !(ft_ps_sort_4_stack_a(struct_list, biggest)))
			return (0);
	}
	else if (flag == 1)
	{
		if (ft_ps_is_sorted(struct_list -> st_b, biggest, 4, 1) != 1)
		{
			if (!(ft_ps_sort_4_stack_b(struct_list, biggest)))
				return (0);
		}
		else
		{
			if (!(ft_ps_sort_del_f_add_f(struct_list, 1))
				|| !(ft_ps_sort_del_f_add_f(struct_list, 1))
				|| !(ft_ps_sort_del_f_add_f(struct_list, 1))
				|| !(ft_ps_sort_del_f_add_f(struct_list, 1)))
				return (0);
		}
	}
	return (1);
}

int	ft_ps_sort_4_stack_a(t_ps_struct_list *struct_list, unsigned int biggest)
{
	unsigned int	i;
	int				ret;

	i = 0;
	ret = 1;
	if (ft_ps_value_of_stack_node(struct_list -> st_a, 4) == biggest)
	{
		if (!(ft_ps_sort_4_is_biggest_top(struct_list, biggest, 0)))
			return (0);
	}
	else
	{
		while (i++ < 4)
		{
			if (ft_ps_value_of_stack_node(struct_list -> st_a, 1)
				== biggest)
				ret = ft_ps_sort_del_f_add_b(struct_list, 0);
			else
				ret = ft_ps_sort_del_f_add_f(struct_list, 0);
			if (ret == 0)
				return (0);
		}
		ft_ps_sort_4_call_sort_3(struct_list, biggest, 0);
	}
	return (1);
}

int	ft_ps_sort_4_stack_b(t_ps_struct_list *struct_list, unsigned int biggest)
{
	unsigned int	i;
	int				ret;

	i = 0;
	ret = 0;
	if (ft_ps_value_of_stack_node(struct_list -> st_b, 1) == biggest)
	{
		if (!(ft_ps_sort_4_is_biggest_top(struct_list, biggest, 1)))
			return (0);
	}
	else
	{
		while (i++ < 4)
		{
			if (ft_ps_value_of_stack_node(struct_list -> st_b, 1)
				== biggest)
				ret = ft_ps_sort_del_f_add_f(struct_list, 1);
			else
				ret = ft_ps_sort_del_f_add_b(struct_list, 1);
			if (ret == 0)
				return (0);
		}
		ft_ps_sort_4_call_sort_3(struct_list, biggest, 1);
	}
	return (1);
}

int	ft_ps_sort_4_is_biggest_top(t_ps_struct_list *struct_list,
		unsigned int biggest, int flag)
{
	if (flag == 0)
	{
		if (!(ft_ps_sort_3(struct_list, biggest - 1, 0)))
			return (0);
	}
	else
	{
		if (!(ft_ps_sort_del_f_add_f(struct_list, 1))
			|| !(ft_ps_sort_3(struct_list, biggest - 1, 1)))
			return (0);
	}
	return (1);
}

int	ft_ps_sort_4_call_sort_3(t_ps_struct_list *struct_list,
		unsigned int biggest, int flag)
{
	unsigned int	i;

	i = 0;
	if (flag == 0)
	{
		if (!(ft_ps_sort_del_b_add_f(struct_list, 0))
			|| !(ft_ps_sort_3(struct_list, biggest - 1, 1)))
			return (0);
	}
	else
	{
		while (i++ < 3)
		{
			if (!(ft_ps_sort_del_b_add_f(struct_list, 1)))
				return (0);
		}
		if (!(ft_ps_sort_3(struct_list, biggest - 1, 1)))
			return (0);
	}
	return (1);
}
