/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ps_sorting_node_move_bonus.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshim <kshim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 13:55:56 by kshim             #+#    #+#             */
/*   Updated: 2022/07/05 13:40:00 by kshim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/checker_bonus.h"

int	ft_ps_sort_del_b_add_f(t_ps_struct_list *struct_list, int flag)
{
	t_detower	*stack;
	t_d_list	*node;
	int			oper_code;

	if (flag == 0)
	{
		stack = struct_list -> st_a;
		oper_code = 8;
	}
	else
	{
		stack = struct_list -> st_b;
		oper_code = 9;
	}
	node = stack -> tail;
	ft_deque_del_back(stack, 0);
	ft_deque_add_front(stack, node);
	if (ft_ps_sort_list_node_add(struct_list, oper_code) != 1)
		return (0);
	return (1);
}

int	ft_ps_sort_del_f_add_f(t_ps_struct_list *struct_list, int flag)
{
	t_detower	*stack1;
	t_detower	*stack2;
	t_d_list	*tmp;
	int			oper_code;

	if (flag == 0)
	{
		oper_code = 4;
		stack1 = struct_list -> st_a;
		stack2 = struct_list -> st_b;
	}
	else
	{
		oper_code = 3;
		stack1 = struct_list -> st_b;
		stack2 = struct_list -> st_a;
	}
	tmp = stack1 -> head;
	ft_deque_del_front(stack1, 0);
	ft_deque_add_front(stack2, tmp);
	if (ft_ps_sort_list_node_add(struct_list, oper_code) != 1)
		return (0);
	return (1);
}

int	ft_ps_sort_del_f_add_b(t_ps_struct_list *struct_list, int flag)
{
	t_detower	*stack;
	t_d_list	*tmp;
	int			oper_code;

	if (flag == 0)
	{
		oper_code = 5;
		stack = struct_list -> st_a;
	}
	else
	{
		oper_code = 6;
		stack = struct_list -> st_b;
	}
	tmp = stack -> head;
	ft_deque_del_front(stack, 0);
	ft_deque_add_back(stack, tmp);
	if (ft_ps_sort_list_node_add(struct_list, oper_code) != 1)
		return (0);
	return (1);
}

int	ft_ps_sort_swap(t_ps_struct_list *struct_list, int flag)
{
	t_d_list	*old_head;
	t_d_list	*old_head_next;
	t_detower	*stack;
	int			oper_code;

	oper_code = 0;
	if (flag == 0)
		stack = struct_list -> st_a;
	else
	{
		stack = struct_list -> st_b;
		oper_code = 1;
	}
	old_head = stack -> head;
	if (old_head == NULL || old_head -> next == NULL)
		return (1);
	old_head_next = old_head -> next;
	ft_deque_del_front(stack, 0);
	ft_deque_del_front(stack, 0);
	ft_deque_add_front(stack, old_head);
	ft_deque_add_front(stack, old_head_next);
	if (ft_ps_sort_list_node_add(struct_list, oper_code) != 1)
		return (0);
	return (1);
}
