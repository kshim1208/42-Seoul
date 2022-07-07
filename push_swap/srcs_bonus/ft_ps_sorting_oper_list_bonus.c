/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ps_sorting_oper_list_bonus.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshim <student.42seoul.kr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 13:57:45 by kshim             #+#    #+#             */
/*   Updated: 2022/07/07 16:15:08 by kshim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/checker_bonus.h"

int	ft_ps_sort_list_node_rotate_check(
		t_ps_struct_list *struct_list, int *oper_code)
{
	t_detower	*oper_list;

	oper_list = struct_list -> list;
	if ((*oper_code == ra && oper_list -> tail != NULL
			&& (*(unsigned int *)(oper_list -> tail)-> content) == rra)
			|| (*oper_code == rb && oper_list -> tail != NULL
			&& (*(unsigned int *)(oper_list -> tail)-> content) == rrb))
	{
		ft_deque_del_back(oper_list, 1);
		return (0);
	}
	if ((*oper_code == ra && oper_list -> tail != NULL
			&& (*(unsigned int *)(oper_list -> tail)-> content) == rb)
			|| (*oper_code == rb && oper_list -> tail != NULL
			&& (*(unsigned int *)(oper_list -> tail)-> content) == ra))
	{
		ft_deque_del_back(oper_list, 1);
		*oper_code = rr;
	}
	return (1);
}

int	ft_ps_sort_list_node_rev_rotate_check(
		t_ps_struct_list *struct_list, int *oper_code)
{
	t_detower	*oper_list;

	oper_list = struct_list -> list;
	if ((*oper_code == rra && oper_list -> tail != NULL
			&& (*(unsigned int *)(oper_list -> tail)-> content) == rrb)
			|| (*oper_code == rrb && oper_list -> tail != NULL
			&& (*(unsigned int *)(oper_list -> tail)-> content) == rra))
	{
		ft_deque_del_back(oper_list, 1);
		*oper_code = rrr;
	}
	if ((*oper_code == rra && oper_list -> tail != NULL
			&& (*(unsigned int *)(oper_list -> tail)-> content) == ra)
			|| (*oper_code == rrb && oper_list -> tail != NULL
			&& (*(unsigned int *)(oper_list -> tail)-> content) == rb))
	{
		ft_deque_del_back(oper_list, 1);
		return (0);
	}
	return (1);
}

int	ft_ps_sort_list_node_add(t_ps_struct_list *struct_list, int oper_code)
{
	t_d_list	*oper_node;

	if (struct_list -> list == NULL)
		return (1);
	if (oper_code == ra || oper_code == rb)
	{
		if (ft_ps_sort_list_node_rotate_check(struct_list, &oper_code) != 1)
			return (1);
	}
	else if (oper_code == rra || oper_code == rrb)
	{
		if (ft_ps_sort_list_node_rev_rotate_check(struct_list, &oper_code) != 1)
			return (1);
	}
	oper_node = ft_ps_sort_list_node_init(oper_code);
	if (oper_node == NULL)
		return (0);
	ft_deque_add_back(struct_list -> list, oper_node);
	return (1);
}
