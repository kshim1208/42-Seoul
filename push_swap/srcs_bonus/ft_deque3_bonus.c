/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_deque3_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshim <kshim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 11:56:25 by kshim             #+#    #+#             */
/*   Updated: 2022/07/05 13:39:49 by kshim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/checker_bonus.h"

void	ft_deque_add_prev_node(t_detower *detower,
		t_d_list *pos, t_d_list *new_elem)
{
	t_d_list	*nod;

	if (detower -> head == pos)
		ft_deque_add_front(detower, new_elem);
	else
	{
		nod = pos -> prev;
		pos -> prev = new_elem;
		new_elem -> prev = nod;
		new_elem -> next = pos;
		nod -> next = new_elem;
	}
	return ;
}

void	ft_deque_add_next_node(t_detower *detower,
		t_d_list *pos, t_d_list *new_elem)
{
	t_d_list	*nod;

	if (detower -> tail == pos)
		ft_deque_add_back(detower, new_elem);
	else
	{
		nod = pos -> next;
		pos -> next = new_elem;
		new_elem -> next = nod;
		new_elem -> prev = pos;
		nod -> prev = new_elem;
	}
	return ;
}
