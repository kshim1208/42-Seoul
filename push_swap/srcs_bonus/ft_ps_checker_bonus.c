/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ps_checker_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshim <kshim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 15:04:41 by kshim             #+#    #+#             */
/*   Updated: 2022/07/13 13:43:35 by kshim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/checker_bonus.h"
#include "../libft/libft.h"

int	ft_ps_bn_checker(t_ps_struct_list *struct_list, char *operation)
{
	int	oper_code;

	oper_code = ft_ps_bn_check_oper(operation);
	if (oper_code == -1)
		return (0);
	if (oper_code <= pa && !(ft_ps_bn_do_oper_0_to_3(struct_list, oper_code)))
		return (0);
	if ((oper_code >= pb && oper_code <= rr)
		&& !(ft_ps_bn_do_oper_4_to_7(struct_list, oper_code)))
		return (0);
	if ((oper_code >= rra && oper_code <= rrr)
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
	if (oper_code == sa)
	{
		if (!(ft_ps_sort_swap(struct_list, 0)))
			return (0);
	}
	else if (oper_code == sb)
	{
		if (!(ft_ps_sort_swap(struct_list, 1)))
			return (0);
	}
	else if (oper_code == ss)
	{
		if (!(ft_ps_sort_swap(struct_list, 0))
			|| !(ft_ps_sort_swap(struct_list, 1)))
			return (0);
	}
	else if (oper_code == pa)
	{
		if (!(ft_ps_sort_del_f_add_f(struct_list, 1)))
			return (0);
	}
	return (1);
}

int	ft_ps_bn_do_oper_4_to_7(t_ps_struct_list *struct_list, int oper_code)
{
	if (oper_code == pb)
	{
		if (!(ft_ps_sort_del_f_add_f(struct_list, 0)))
			return (0);
	}
	else if (oper_code == ra)
	{
		if (!(ft_ps_sort_del_f_add_b(struct_list, 0)))
			return (0);
	}
	else if (oper_code == rb)
	{
		if (!(ft_ps_sort_del_f_add_b(struct_list, 1)))
			return (0);
	}
	else if (oper_code == rr)
	{
		if (!(ft_ps_sort_del_f_add_b(struct_list, 0))
			|| !(ft_ps_sort_del_f_add_b(struct_list, 1)))
			return (0);
	}
	return (1);
}

int	ft_ps_bn_do_oper_8_to_10(t_ps_struct_list *struct_list, int oper_code)
{
	if (oper_code == rra)
	{
		if (!(ft_ps_sort_del_b_add_f(struct_list, 0)))
			return (0);
	}
	else if (oper_code == rrb)
	{
		if (!(ft_ps_sort_del_b_add_f(struct_list, 1)))
			return (0);
	}
	else if (oper_code == rrr)
	{
		if (!(ft_ps_sort_del_b_add_f(struct_list, 0))
			|| !(ft_ps_sort_del_b_add_f(struct_list, 1)))
			return (0);
	}
	return (1);
}
