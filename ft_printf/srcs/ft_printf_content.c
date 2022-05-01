/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_content.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshim <kshim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 14:53:24 by kshim             #+#    #+#             */
/*   Updated: 2022/05/01 10:50:04 by kshim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_fp_content	*set_new_content(int is_format, va_list *ap)
{
	t_fp_content	*new_content;
	t_fp_formats	*tmp;

	new_content = (t_fp_content *)malloc(sizeof(t_fp_content));
	if (new_content == NULL)
		return (NULL);
	new_content -> format = is_format;
	if (is_format == 1)
	{
		tmp = set_format_detail(new_content, ap);
		if (tmp == NULL)
			return (NULL);
	}
	else
		new_content -> format_detail = NULL;
	return (new_content);
}

t_fp_formats	*set_format_detail(t_fp_content *new_content, va_list *ap)
{
	t_fp_formats	*new_formats;

	new_formats = (t_fp_formats *)malloc(sizeof(t_fp_formats));
	if (new_formats == NULL)
		return (NULL);
	new_formats -> ap = ap;
	new_formats -> width = 0;
	new_formats -> alternate = 0;
	new_formats -> zero_fill = 0;
	new_formats -> left_justify = 0;
	new_formats -> plus_sign = 0;
	new_formats -> space_sign = 0;
	new_formats -> neg_value = 0;
	new_formats -> precision = 0;
	new_formats -> prec_val = 0;
	new_formats -> fs = 0;
	new_content -> format_detail = new_formats;
	return (new_formats);
}

void	fp_del_content(t_fp_content **content)
{
	if (((*content)-> format_detail) != NULL)
		ft_fp_free_formats(&((*content)-> format_detail));
	(*content)-> format = 0;
	(*content)-> output_len = 0;
	free((*content));
	(*content) = NULL;
	return ;
}
