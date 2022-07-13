/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ps_sorting_main.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshim <kshim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 16:41:18 by kshim             #+#    #+#             */
/*   Updated: 2022/07/13 13:39:19 by kshim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	ft_ps_move_a_to_b(t_ps_struct_list *struct_list,
	unsigned int biggest, unsigned int num, int flag)
{
	if (flag == 1)
	{
		if (!(ft_ps_bef_sort_rev_rotate(struct_list, num, 0)))
			return (0);
	}
	if (num <= 5)
	{
		if (!(ft_ps_rec_sort_under_5(struct_list, biggest, num, 0)))
			return (0);
	}
	else
	{
		if (!(ft_ps_rec_sort_move_a_to_b(struct_list, biggest, num)))
			return (0);
	}
	return (1);
}

int	ft_ps_move_b_to_a(t_ps_struct_list *struct_list,
	unsigned int biggest, unsigned int num, int flag)
{
	if (flag == 1)
		ft_ps_bef_sort_rev_rotate(struct_list, num, 1);
	if (num <= 5)
	{
		if (!(ft_ps_rec_sort_under_5(struct_list, biggest, num, 1)))
			return (0);
	}
	else
	{
		if (!(ft_ps_rec_sort_move_b_to_a(struct_list, biggest, num)))
			return (0);
	}
	return (1);
}

int	ft_ps_rec_sort_under_5(t_ps_struct_list *struct_list,
	unsigned int biggest, unsigned int num, int direction)
{
	int	ret;

	ret = 1;
	if (num == 5)
		ret = ft_ps_sort_5(struct_list, biggest, direction);
	else if (num == 4)
		ret = ft_ps_sort_4(struct_list, biggest, direction);
	else if (num == 3)
		ret = ft_ps_sort_3(struct_list, biggest, direction);
	else if (num == 2)
		ret = ft_ps_sort_2(struct_list, direction);
	else if (num == 1 && direction == 1)
		ret = ft_ps_sort_del_f_add_f(struct_list, direction);
	if (ret == 0)
		return (0);
	return (1);
}

int	ft_ps_rec_sort_move_a_to_b(t_ps_struct_list *struct_list,
	unsigned int biggest, unsigned int num)
{
	unsigned int	pivot_a;
	unsigned int	pivot_b;
	t_sort_data		*sort_data;

	pivot_a = (biggest - (num * 0.3));
	pivot_b = (biggest - (num * 0.55));
	sort_data = ft_ps_sorting_data_init(pivot_a, pivot_b);
	if (sort_data == NULL)
		return (0);
	if (!(ft_ps_sort_a_to_b(struct_list, sort_data, num))
		|| !(ft_ps_sort_a_to_b_reverse_rotate(struct_list, sort_data))
		|| !(ft_ps_move_a_to_b(struct_list, biggest,
				(sort_data -> ra), 0))
		|| !(ft_ps_move_b_to_a(struct_list, pivot_a,
				(sort_data -> rb), 0))
		|| !(ft_ps_move_b_to_a(struct_list, pivot_b,
				((sort_data -> pb) - (sort_data -> rb)), 0)))
	{
		ft_ps_free_sort_data(&sort_data);
		return (0);
	}
	ft_ps_free_sort_data(&sort_data);
	return (1);
}

int	ft_ps_rec_sort_move_b_to_a(t_ps_struct_list *struct_list,
	unsigned int biggest, unsigned int num)
{
	unsigned int	pivot_a;
	unsigned int	pivot_b;
	t_sort_data		*sort_data;

	pivot_a = (biggest - (num * 0.3));
	pivot_b = (biggest - (num * 0.55));
	sort_data = ft_ps_sorting_data_init(pivot_a, pivot_b);
	if (sort_data == NULL)
		return (0);
	if (!(ft_ps_sort_b_to_a(struct_list, sort_data, num))
		|| !(ft_ps_move_a_to_b(struct_list, biggest,
				((sort_data -> pa) - (sort_data -> ra)), 0))
		|| !(ft_ps_move_a_to_b(struct_list, pivot_a,
				(sort_data -> ra), 1))
		|| !(ft_ps_move_b_to_a(struct_list, pivot_b,
				(sort_data -> rb), 1)))
	{
		ft_ps_free_sort_data(&sort_data);
		return (0);
	}
	ft_ps_free_sort_data(&sort_data);
	return (1);
}
