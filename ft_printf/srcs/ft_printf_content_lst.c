/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_contente_lst.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshim <kshim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 14:53:24 by kshim             #+#    #+#             */
/*   Updated: 2022/04/25 10:39:22 by kshim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

/* need to add del function to use ft_lstdelone & ft_lstclear */

/* content와 lst 생성 및 연결만 하고 내용은 다른 함수에서 채운다 */
t_lst	*make_new_content(t__lst **lst_head, int is_format)
{
	t_fp_content		new_content;
	t_fp_content_lst	new_lst;

	new_content = set_new_content(is_format);
	if (new_content == NULL)
		return (NULL);
	new_lst = ft_lstnew(new_content);
	if (new_lst == NULL)
		return (NULL);
	ft_lst_addback(lst_head, new_lst);
	return (new_lst);
}

t_fp_content	*set_new_content(int is_format)
{
	t_fp_content	*new_content;

	new_content = (t_fp_content *)malloc(sizeof(t_fp_content));
	if (new_content == NULL)
		return (NULL);
	new_content -> format = is_format;
	if (is_format == 1)
		set_format_detail(new_content);
	else
		new_content -> format_detail = NULL;
	new_content -> output = NULL;
	return (new_content);
}

void	*set_format_detail(t_fp_content *new_content)
{
	t_fp_formats	*new_formats;

	new_formats = (t_fp_formats *)malloc(sizeof(t_fp_formats));
	if (new_formats == NULL)
		return (NULL);
	new_formats -> width = 0;
	new_formats -> alternate = 0;
	new_formats -> zero_fill = 0;
	new_formats -> left_justify = 0;
	new_formats -> sign = 0;
	new_formats -> precision = 0;
	new_formats -> prec_val = 0;
	new_formats -> fs = NULL;
	new_content -> format_detatil = new_formats;
	return ;
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
		content -> format_detail -> sign = 0;
		content -> format_detail -> precision = 0;
		content -> format_detail -> prec_val = 0;
		content -> format_detail -> fs = 0;
		free(content -> format_detail);
		content -> format_detail = NULL;
	}
	content -> format = 0;
}
