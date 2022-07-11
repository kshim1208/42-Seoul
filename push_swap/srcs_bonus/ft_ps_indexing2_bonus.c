/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ps_indexing2_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshim <kshim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 12:32:51 by kshim             #+#    #+#             */
/*   Updated: 2022/07/08 13:51:39 by kshim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_ps_indexing_side(t_detower *index, t_d_list *pos,
		t_d_list *node, t_node_val *check)
{
	if (pos -> prev == NULL && pos -> next == NULL)
	{
		ft_ps_indexing_single_node(index, pos, node, check);
	}
	else if (pos -> prev == NULL)
	{
		if (check -> node_val < check -> pos_val)
			ft_deque_add_prev_node(index, pos, node);
		else if (check -> next_val < check -> node_val)
			ft_deque_add_next_node(index, pos -> next, node);
		else if (check -> pos_val < check -> node_val)
			ft_deque_add_next_node(index, pos, node);
	}
	else if (pos -> next == NULL)
	{
		if (check -> node_val < check -> prev_val)
			ft_deque_add_prev_node(index, pos -> prev, node);
		else if (check -> node_val < check -> pos_val)
			ft_deque_add_prev_node(index, pos, node);
		else if (check -> pos_val < check -> node_val)
			ft_deque_add_next_node(index, pos, node);
	}
	ft_ps_indexing_free_check(check);
	return ;
}

void	ft_ps_indexing_single_node(t_detower *index, t_d_list *pos,
		t_d_list *node, t_node_val *check)
{
	if (check -> node_val < check -> pos_val)
		ft_deque_add_prev_node(index, pos, node);
	else if (check -> pos_val < check -> node_val)
		ft_deque_add_next_node(index, pos, node);
	return ;
}

int	ft_ps_indexing_normal(t_detower *index, t_d_list *pos,
		t_d_list *node, t_node_val *check)
{
	if (check -> prev_val < check -> node_val
		&& check -> node_val < check -> pos_val)
	{
		ft_deque_add_prev_node(index, pos, node);
		ft_ps_indexing_free_check(check);
		return (1);
	}
	else if (check -> pos_val < check -> node_val
		&& check -> node_val < check -> next_val)
	{
		ft_deque_add_next_node(index, pos, node);
		ft_ps_indexing_free_check(check);
		return (1);
	}
	return (0);
}

int	ft_ps_indexing_point(t_d_list *pos, t_node_val *check,
		t_d_list *node, unsigned int point)
{
	if (point <= 1)
		point = 1;
	else
		point = point / 2;
	if (check -> pos_val == check -> node_val
		|| ((pos -> prev != NULL) && check -> prev_val == check -> node_val)
		|| ((pos -> next != NULL) && check -> next_val == check -> node_val))
	{
		ft_ps_indexing_free_check(check);
		ft_d_lstdelone(node, NULL);
		return (0);
	}
	return (point);
}

void	ft_ps_set_val_to_index(t_detower *index)
{
	t_d_list		*lst;
	unsigned int	i;

	lst = index -> head;
	i = 0;
	while (lst != NULL)
	{
		((t_value *)(lst -> content))-> index = i;
		lst = lst -> next;
		i++;
	}
	return ;
}
