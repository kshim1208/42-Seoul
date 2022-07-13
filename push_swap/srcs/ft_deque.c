/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_deque.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshim <kshim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 16:07:29 by kshim             #+#    #+#             */
/*   Updated: 2022/07/13 13:39:27 by kshim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_detower	*ft_dequetower(void)
{
	t_detower	*new_detower;

	new_detower = (t_detower *)malloc(sizeof(t_detower));
	if (new_detower == NULL)
		return (NULL);
	new_detower -> head = NULL;
	new_detower -> tail = NULL;
	return (new_detower);
}

t_d_list	*ft_d_lstnew(void *content)
{
	t_d_list	*new_list;

	new_list = (t_d_list *)malloc(sizeof(t_d_list));
	if (new_list == NULL)
		return (NULL);
	new_list -> content = content;
	new_list -> prev = NULL;
	new_list -> next = NULL;
	return (new_list);
}

void	ft_free_detower(t_detower **detower)
{
	t_d_list	*lst;

	lst = (*detower)-> head;
	if (lst != NULL)
		ft_d_lstclear(&lst, &ft_ps_content_del);
	(*detower)-> head = NULL;
	(*detower)-> tail = NULL;
	free((*detower));
	(*detower) = NULL;
	return ;
}

void	ft_ps_content_del(void *content)
{
	t_value	*content_value;

	content_value = (t_value *)content;
	content_value -> index = 0;
	free(content_value);
	content_value = NULL;
	return ;
}

void	ft_d_lstclear(t_d_list **lst, void (*del)(void *))
{
	t_d_list	*now;

	now = NULL;
	while (*lst != NULL)
	{
		now = (*lst)-> next;
		ft_d_lstdelone(*lst, del);
		*lst = now;
	}
	*lst = NULL;
	return ;
}
