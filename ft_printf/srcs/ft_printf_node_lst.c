/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_node_lst.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshim <kshim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 14:53:24 by kshim             #+#    #+#             */
/*   Updated: 2022/04/19 16:14:26 by kshim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

/* del function to use ft_lstdelone & ft_lstclear */

t_fp_node_lst	*set_new_node(t_fp_node_lst **lst_head,
		char *str, int is_format)
{
	t_fp_node		new_node;
	t_fp_node_union	new_union;
	t_fp_node_lst	new_node_lst;

	new_node = NULL;
	if (str == NULL)
	{
		new_node = set_new_node(void);
		if (new_node == NULL)
			return (NULL);
	}
	new_union = set_new_union(new_node, str);
	if (new_union == NULL)
		return (NULL);
	new_node_lst = set_node_to_lst(new_node, is_format);
	if (new_node_lst == NULL)
		return (NULL);
	if (*lst_head == NULL)
		*lst_head == new_node_lst;
	else
	{
		ft_lstlast(new_node_lst);
		ft_lst_addback(&lst_head, new_node_lst);
	}
	return (new_node_lst);
}

t_fp_node	*set_new_node(void)
{
	t_fp_node	*new_node;

	new_node = (t_fp_node *)malloc(sizeof(t_fp_node));
	if (new_node == NULL)
		return (NULL);
	new_node -> width = 0;
	new_node -> zero_fill = 0;
	new_node -> space_fill = 0;
	new_node -> left_justify = 0;
	new_node -> sign = 0;
	new_node -> format_specifier = NULL;
	new_node -> output = NULL;
	return (new_node);
}

t_fp_node_union	*set_new_union(t_fp_node *new_node, char *str)
{
	t_fp_node_union	*new_union;

	new_union = (t_fp_union *)malloc(sizeof(t_fp_node_union));
	if (new_union == NULL)
		return (NULL);
	if (new_node == NULL)
		new_union -> str = str;
	else if (str == NULL)
		new_union -> node = new_nod;
	return (new_union);
}

t_fp_node_lst	*set_node_to_lst(t_fp_union *new_union, int is_format)
{
	t_fp_node_lst	*new_lst;

	new_lst = (t_fp_node_lst *)malloc(sizeof(t_fp_node_lst));
	if (new_node == NULL)
		return (NULL);
	new_lst -> is_format = is_format;
	new_lst -> content = new_union;
	new_lst -> next = NULL;
	return (new_lst);
}
