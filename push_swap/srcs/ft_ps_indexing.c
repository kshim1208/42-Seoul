/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ps_indexing.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshim <kshim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 10:02:22 by kshim             #+#    #+#             */
/*   Updated: 2022/07/13 13:39:25 by kshim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_ps_indexing(t_detower *index, t_value *content, unsigned int num)
{
	unsigned int	point;
	t_d_list		*pos;
	t_d_list		*node;

	node = ft_d_lstnew(content);
	if (node == NULL)
		return (0);
	point = num;
	pos = index -> tail;
	if (point == 0)
	{
		index -> head = node;
		index -> tail = node;
	}
	else
	{
		point = point / 2;
		ft_ps_indexing_relocate(&pos, point, NULL, 0);
		if (!(ft_ps_indexing_rec(index, &pos, node, point)))
			return (0);
	}
	return (1);
}

int	ft_ps_indexing_rec(t_detower *index, t_d_list **pos,
		t_d_list *node, unsigned int point)
{
	t_node_val	*check;

	check = NULL;
	if (!(ft_ps_indexing_node_val(*pos, node, &check)))
		return (0);
	point = ft_ps_indexing_point(*pos, check, node, point);
	if (point == 0)
		return (0);
	if ((*pos)-> prev == NULL || (*pos)-> next == NULL)
	{
		ft_ps_indexing_side(index, *pos, node, check);
		return (1);
	}
	else
	{
		if (ft_ps_indexing_normal(index, *pos, node, check) == 1)
			return (1);
		if (check -> node_val < check -> prev_val)
			ft_ps_indexing_relocate(pos, point, check, 0);
		else if (check -> next_val < check -> node_val)
			ft_ps_indexing_relocate(pos, point, check, 1);
	}
	if (!(ft_ps_indexing_rec(index, pos, node, point)))
		return (0);
	return (1);
}

int	ft_ps_indexing_node_val(t_d_list *pos, t_d_list *node, t_node_val **check)
{
	(*check) = (t_node_val *)malloc(sizeof(t_node_val));
	if ((*check) == NULL)
		return (0);
	(*check)-> pos_val = ((t_value *)(pos -> content))-> value;
	(*check)-> node_val = ((t_value *)(node -> content))-> value;
	(*check)-> prev_val = 0;
	(*check)-> next_val = 0;
	if (pos -> prev != NULL)
		(*check)-> prev_val = ((t_value *)((pos -> prev)-> content))-> value;
	if (pos -> next != NULL)
		(*check)-> next_val = ((t_value *)((pos -> next)-> content))-> value;
	return (1);
}

void	ft_ps_indexing_free_check(t_node_val *check)
{
	if (check == NULL)
		return ;
	check -> pos_val = 0;
	check -> node_val = 0;
	check -> prev_val = 0;
	check -> next_val = 0;
	free(check);
	return ;
}

void	ft_ps_indexing_relocate(t_d_list **pos, unsigned int point,
		t_node_val *check, int flag)
{
	unsigned int	i;

	i = 0;
	while (i < point)
	{
		if (flag == 0)
			*pos = (*pos)-> prev;
		else if (flag == 1)
			*pos = (*pos)-> next;
		i++;
	}
	ft_ps_indexing_free_check(check);
	return ;
}
