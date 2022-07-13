/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ps_sorting_only_main_5.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshim <kshim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 13:13:09 by kshim             #+#    #+#             */
/*   Updated: 2022/07/13 10:39:37 by kshim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	ft_ps_sort_only_under_5(t_ps_struct_list *struct_list, unsigned int num)
{
	int	ret;

	ret = 1;
	if (num == 5)
		ret = ft_ps_sort_only_5(struct_list, num);
	else if (num == 4)
		ret = ft_ps_sort_only_4(struct_list, num);
	else if (num == 3)
		ret = ft_ps_sort_only_3(struct_list, num);
	else if (num == 2)
		ret = ft_ps_sort_2(struct_list, 0);
	if (ret == 0)
		return (0);
	return (1);
}

int	ft_ps_sort_only_5(t_ps_struct_list *struct_list, unsigned int num)
{
	if (!(ft_ps_sort_only_5_distribute_nodes(struct_list, num)))
		return (0);
	if (!(ft_ps_sort_only_3(struct_list, 3)))
		return (0);
	if (ft_ps_value_of_stack_node(struct_list -> st_b, 1)
		< ft_ps_value_of_stack_node(struct_list -> st_b, 2))
	{
		if (!(ft_ps_sort_swap(struct_list, 1)))
			return (0);
	}
	if (!(ft_ps_sort_del_f_add_f(struct_list, 1))
		|| !(ft_ps_sort_del_f_add_f(struct_list, 1))
		|| !(ft_ps_sort_del_f_add_b(struct_list, 0))
		|| !(ft_ps_sort_del_f_add_b(struct_list, 0)))
		return (0);
	return (1);
}

int	ft_ps_sort_only_5_distribute_nodes(t_ps_struct_list *struct_list,
	unsigned int num)
{
	unsigned int	i;

	i = 0;
	while (i < num)
	{
		if ((ft_ps_value_of_stack_node(struct_list -> st_a, 1) == num - 1)
			|| (ft_ps_value_of_stack_node(struct_list -> st_a, 1) == (num - 2)))
		{
			if (!(ft_ps_sort_del_f_add_f(struct_list, 0)))
				return (0);
		}
		else
		{
			if (!(ft_ps_sort_del_f_add_b(struct_list, 0)))
				return (0);
		}
		i++;
	}
	return (1);
}
