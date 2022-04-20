/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_contente_lst.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshim <kshim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 14:53:24 by kshim             #+#    #+#             */
/*   Updated: 2022/04/20 12:04:33 by kshim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

/* need to add del function to use ft_lstdelone & ft_lstclear */

/* content와 lst 생성 및 연결만 하고 내용은 다른 함수에서 채운다 */
t_lst	*set_new_content(t_fp_content_lst **lst_head, int is_format)
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
	new_formats -> space_fill = 0;
	new_formats -> left_justify = 0;
	new_formats -> sign = 0;
	new_formats -> precision = 0;
	new_formats -> prec_val = 0;
	new_formats -> format_specifier = NULL;
	new_content -> format_detatil = new_formats;
	return ;
}
