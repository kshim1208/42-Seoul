/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ps_indexing.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshim <kshim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 10:02:22 by kshim             #+#    #+#             */
/*   Updated: 2022/06/10 16:45:54 by kshim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_ps_indexing(t_detower *list, t_value *content, unsigned int num)
{
	unsigned int	point;
	t_d_list		*pos;
	t_d_list		*node;

	node = ft_d_lstnew(content);
	if (node == NULL)
		return (0);
	point = num;
	pos = list -> tail;
	if (point == 0)
	{
		list -> head = node;
		list -> tail = node;
	}
	else
	{
		point = point / 2;
		ft_ps_indexing_relocate(&pos, point, 0);
		ft_ps_indexing_rec(list, &pos, node, point);
	}
	return (1);
}

void	ft_ps_indexing_rec(t_detower *list, t_d_list **pos, t_d_list *node, unsigned int point)
{
	t_d_list	*prev;
	t_d_list	*next;

	if (point <= 1)
		point = 1;
	else
		point = point / 2;
	prev = (*pos)-> prev;
	next = (*pos)-> next;
	if (prev == NULL)
	{
		if (((t_value *)(node -> content))-> value
			< ((t_value *)((*pos)-> content))-> value)
			ft_deque_add_prev_node(list, *pos, node);
/* point 2에서 (세번 째 값)에서 내려올 떄 이 밑 조건문에서 의도하지 않은 동작함 */
/* 그리고 거기서 한 번 값이 잘못 할당되니 재귀적으로 전부 값이 꼬이는 것 같음 */
/* 이 부분 수정하면 정상 동작할 것 같음 */
		else if (((t_value *)((*pos)-> content))-> value
				 < ((t_value *)(node -> content)) ->value
			ft_deque_add_next_node(list, *pos, node);
		return ;
	}
	else	
	{
		if (((t_value *)(prev -> content))-> value 
			< ((t_value *)(node -> content))-> value
			< ((t_value *)((*pos)-> content))-> value)
		{
			ft_deque_add_prev_node(list, *pos, node);
			return ;
		}
		else if (((t_value *)((*pos)-> content))-> value 
			< ((t_value *)(node -> content))-> value 
			< ((t_value *)(next -> content))-> value)
		{
			ft_deque_add_next_node(list, *pos, node);
			return ;
		}
		else if (((t_value *)(node -> content))-> value
			< ((t_value *)(prev -> content))-> value)
			ft_ps_indexing_relocate(pos, point, 0);
		else if (((t_value *)(next -> content))-> value
			< ((t_value *)(node -> content))-> value)
			ft_ps_indexing_relocate(pos, point, 1);
	} 	
	ft_ps_indexing_rec(list, pos, node, point);
	return ;
}

void ft_ps_indexing_relocate(t_d_list **pos, unsigned int point, int flag)
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
	return ;
}
