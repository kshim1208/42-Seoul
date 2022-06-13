/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_deque2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshim <kshim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 10:30:11 by kshim             #+#    #+#             */
/*   Updated: 2022/06/13 12:14:28 by kshim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_deque_add_back(t_detower *detower, t_d_list *new_elem)
{
	if (detower -> head == NULL)
		detower -> head = new_elem;
	else
	{
		detower -> tail -> next = new_elem;
		new_elem -> prev = detower -> tail;
	}
	detower -> tail = new_elem;
	return ;
}

void	ft_deque_add_front(t_detower *detower, t_d_list *new_elem)
{
	if (detower -> head == NULL)
	{
		detower -> head = new_elem;
		detower -> tail = new_elem;
	}
	else
	{
		new_elem -> next = detower -> head;
		detower -> head -> prev = new_elem;
		detower -> head = new_elem;
	}
	return ;
}

void	ft_deque_del_back(t_detower *detower)
{
	t_d_list	*tmp;

	if (detower -> tail == NULL)
		return ;
	tmp = detower -> tail;
	if (detower -> tail -> prev == NULL)
	{
		detower -> head = NULL;
		detower -> tail = NULL;
	}
	else
	{
		detower -> tail -> prev -> next = NULL;
		detower -> tail = detower -> tail -> prev;
	}
	ft_d_lstdelone(tmp, (&ft_ps_content_del));
	return ;
}

void	ft_deque_del_front(t_detower *detower)
{
	t_d_list	*tmp;

	if (detower -> head == NULL)
		return ;
	tmp = detower -> head;
	if (detower -> head -> next == NULL)
	{
		detower -> head = NULL;
		detower -> tail = NULL;
	}
	else
	{
		detower -> head -> next -> prev = NULL;
		detower -> head = detower -> head -> next;
	}
	ft_d_lstdelone(tmp, &ft_ps_content_del);
	return ;
}

void	ft_d_lstdelone(t_d_list *lst, void (*del)(void *))
{
	if (lst -> content != NULL && del != NULL)
		del(lst -> content);
	if (lst != NULL)
		free(lst);
	return ;
}
