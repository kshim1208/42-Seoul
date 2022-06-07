/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_deque.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshim <kshim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 16:07:29 by kshim             #+#    #+#             */
/*   Updated: 2022/06/07 15:35:18 by kshim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#include "../libft/ft_printf.h"

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

int	ft_deque_add_back(t_detower *detower, int num)
{
	t_list	*new_lst;
	int		*value;

	value = (int *)malloc(sizeof(int));
	if (value == NULL)
		return (0);
	*value = num;
	new_lst = ft_lstnew(value);
	if (new_lst == NULL)
		return (0);
	ft_lstadd_back(&(detower -> head), new_lst);
	detower -> tail = new_lst;
	return (1);
}

int	ft_deque_add_front(t_detower *detower, int num)
{
	t_list	*new_lst;
	int		*value;

	value = (int *)malloc(sizeof(int));
	if (value == NULL)
		return (0);
	*value = num;
	new_lst = ft_lstnew(value);
	if (new_lst == NULL)
		return (0);
	ft_lstadd_front(&(detower -> head), new_lst);
	return (1);
}

void	ft_free_detower(t_detower *detower)
{
	t_list	*lst;
	void	(*del)(void *);

	lst = detower -> head;
	del = ft_ps_content_del;
	if (lst != NULL)
		ft_lstclear(&lst, del);
	detower -> head = NULL;
	detower -> tail = NULL;
	ft_printf("%p\n", detower);
	free(detower);
	detower = NULL;
	ft_printf("%p\n", detower);
	return ;
}

void	ft_ps_content_del(void *content)
{
	int	*value;

	value = (int *)content;
	ft_printf("%p\n", value);
	*value = 0;
	free(value);
	value = NULL;
	ft_printf("%p\n", value);
	return ;
}
