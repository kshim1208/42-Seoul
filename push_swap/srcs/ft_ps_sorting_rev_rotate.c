/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ps_sorting_rev_rotate.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshim <kshim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 13:54:05 by kshim             #+#    #+#             */
/*   Updated: 2022/07/13 13:39:08 by kshim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	ft_ps_sort_a_to_b_reverse_rotate(t_ps_struct_list *struct_list,
		t_sort_data *sort_data)
{
	unsigned int	rrr;
	unsigned int	r_left;
	int				flag;

	r_left = 0;
	flag = -1;
	if ((sort_data -> ra) == (sort_data -> rb))
		rrr = sort_data -> ra;
	else if ((sort_data -> ra) > (sort_data -> rb))
	{
		rrr = sort_data -> rb;
		r_left = (sort_data -> ra) - (sort_data -> rb);
		flag = 0;
	}
	else
	{
		rrr = sort_data -> ra;
		r_left = (sort_data -> rb) - (sort_data -> ra);
		flag = 1;
	}
	if (!(ft_ps_sort_do_reverse_rotate(struct_list, rrr, r_left, flag)))
		return (0);
	return (1);
}

int	ft_ps_bef_sort_rev_rotate(
		t_ps_struct_list *struct_list, unsigned int num, int flag)
{
	if (flag == 0)
		ft_ps_sort_do_reverse_rotate(struct_list, 0, num, 0);
	else if (flag == 1)
		ft_ps_sort_do_reverse_rotate(struct_list, 0, num, 1);
	return (1);
}

int	ft_ps_sort_do_reverse_rotate(t_ps_struct_list *struct_list,
		unsigned int rrr, unsigned int r_left, int flag)
{
	unsigned int	tmp;

	tmp = 0;
	while (tmp++ < rrr)
	{
		if (!(ft_ps_sort_del_b_add_f(struct_list, 0))
			|| !(ft_ps_sort_del_b_add_f(struct_list, 1)))
			return (0);
	}
	tmp = 0;
	while (tmp++ < r_left)
	{
		if (flag == 0)
		{
			if (!(ft_ps_sort_del_b_add_f(struct_list, 0)))
				return (0);
		}
		else if (flag == 1)
		{
			if (!(ft_ps_sort_del_b_add_f(struct_list, 1)))
				return (0);
		}
	}
	return (1);
}
