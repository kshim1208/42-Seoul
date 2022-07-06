/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ps_bn_checker.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshim <kshim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 15:04:41 by kshim             #+#    #+#             */
/*   Updated: 2022/06/25 11:17:13 by kshim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/checker.h"

int	ft_ps_bn_checker(t_ps_struct_list *struct_list, char *operation)
{
	int	oper_code;

	oper_code = ft_ps_bn_check_oper(operation);
	if (oper_code == -1)
		return (0);
	if (oper_code <= 3 && !(ft_ps_bn_do_oper_0_to_3(struct_list, oper_code)))
		return (0);
	if ((oper_code >= 4 && oper_code <= 7)
		&& !(ft_ps_bn_do_oper_4_to_7(struct_list, oper_code)))
		return (0);
	if ((oper_code >= 8 && oper_code <= 10)
		&& !(ft_ps_bn_do_oper_8_to_10(struct_list, oper_code)))
		return (0);
	return (1);
}

int	ft_ps_bn_check_oper(char *operation)
{
	if (ft_strcmp(operation, "sa\n") == 0)
		return (0);
	else if (ft_strcmp(operation, "sb\n") == 0)
		return (1);
	else if (ft_strcmp(operation, "ss\n") == 0)
		return (2);
	else if (ft_strcmp(operation, "pa\n") == 0)
		return (3);
	else if (ft_strcmp(operation, "pb\n") == 0)
		return (4);
	else if (ft_strcmp(operation, "ra\n") == 0)
		return (5);
	else if (ft_strcmp(operation, "rb\n") == 0)
		return (6);
	else if (ft_strcmp(operation, "rr\n") == 0)
		return (7);
	else if (ft_strcmp(operation, "rra\n") == 0)
		return (8);
	else if (ft_strcmp(operation, "rrb\n") == 0)
		return (9);
	else if (ft_strcmp(operation, "rrr\n") == 0)
		return (10);
	return (-1);
}

int	ft_ps_bn_do_oper_0_to_3(t_ps_struct_list *struct_list, int oper_code)
{
	if (oper_code == 0)
	{
		if (!(ft_ps_sort_swap(struct_list, 0)))
			return (0);
	}
	else if (oper_code == 1)
	{
		if (!(ft_ps_sort_swap(struct_list, 1)))
			return (0);
	}
	else if (oper_code == 2)
	{
		if (!(ft_ps_sort_swap(struct_list, 0))
			|| !(ft_ps_sort_swap(struct_list, 1)))
			return (0);
	}
	else if (oper_code == 3)
	{
		if (!(ft_ps_sort_del_f_add_f(struct_list, 1)))
			return (0);
	}
	return (1);
}

int	ft_ps_bn_do_oper_4_to_7(t_ps_struct_list *struct_list, int oper_code)
{
	if (oper_code == 4)
	{
		if (!(ft_ps_sort_del_f_add_f(struct_list, 0)))
			return (0);
	}
	else if (oper_code == 5)
	{
		if (!(ft_ps_sort_del_f_add_b(struct_list, 0)))
			return (0);
	}
	else if (oper_code == 6)
	{
		if (!(ft_ps_sort_del_f_add_b(struct_list, 1)))
			return (0);
	}
	else if (oper_code == 7)
	{
		if (!(ft_ps_sort_del_f_add_b(struct_list, 0))
			|| !(ft_ps_sort_del_f_add_b(struct_list, 1)))
			return (0);
	}
	return (1);
}

int	ft_ps_bn_do_oper_8_to_10(t_ps_struct_list *struct_list, int oper_code)
{
	if (oper_code == 8)
	{
		if (!(ft_ps_sort_del_b_add_f(struct_list, 0)))
			return (0);
	}
	else if (oper_code == 9)
	{
		if (!(ft_ps_sort_del_b_add_f(struct_list, 1)))
			return (0);
	}
	else if (oper_code == 10)
	{
		if (!(ft_ps_sort_del_b_add_f(struct_list, 0))
			|| !(ft_ps_sort_del_b_add_f(struct_list, 1)))
			return (0);
	}
	return (1);
}
