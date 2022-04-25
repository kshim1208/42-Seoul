/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_contente_lst.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshim <kshim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 14:53:24 by kshim             #+#    #+#             */
/*   Updated: 2022/04/25 15:17:30 by kshim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

t_list	*make_new_content(t_list **lst_head, int is_format)
{
	t_fp_content		*new_content;
	t_list				*new_lst;

	new_content = set_new_content(is_format);
	if (new_content == NULL)
		return (NULL);
	new_lst = ft_lstnew(new_content);
	if (new_lst == NULL)
		return (NULL);
	ft_lstadd_back(lst_head, new_lst);
	return (new_lst);
}

t_fp_content	*set_new_content(int is_format)
{
	t_fp_content	*new_content;
	t_fp_formats	*tmp;

	new_content = (t_fp_content *)malloc(sizeof(t_fp_content));
	if (new_content == NULL)
		return (NULL);
	new_content -> format = is_format;
	if (is_format == 1)
	{
		tmp = set_format_detail(new_content);
		if (tmp == NULL)
			return (NULL);
	}
	else
		new_content -> format_detail = NULL;
	new_content -> output = NULL;
	return (new_content);
}

t_fp_formats	*set_format_detail(t_fp_content *new_content)
{
	t_fp_formats	*new_formats;

	new_formats = (t_fp_formats *)malloc(sizeof(t_fp_formats));
	if (new_formats == NULL)
		return (NULL);
	new_formats -> width = 0;
	new_formats -> alternate = 0;
	new_formats -> zero_fill = 0;
	new_formats -> left_justify = 0;
	new_formats -> plus_sign = 0;
	new_formats -> space_sign = 0;
	new_formats -> precision = 0;
	new_formats -> prec_val = 0;
	new_formats -> fs = 0;
	new_content -> format_detail = new_formats;
	return (new_formats);
}

void	fp_del_content(t_fp_content *content)
{
	if (content -> output != NULL)
	{
		free(content -> output);
		content -> output = NULL;
	}
	if (content -> format_detail != NULL)
	{
		content -> format_detail -> width = 0;
		content -> format_detail -> alternate = 0;
		content -> format_detail -> zero_fill = 0;
		content -> format_detail -> left_justify = 0;
		content -> format_detail -> plus_sign = 0;
		content -> format_detail -> space_sign = 0;
		content -> format_detail -> precision = 0;
		content -> format_detail -> prec_val = 0;
		content -> format_detail -> fs = 0;
		free(content -> format_detail);
		content -> format_detail = NULL;
	}
	content -> format = 0;
}
