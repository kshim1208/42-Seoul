/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_print_out.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshim <kshim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 14:42:22 by kshim             #+#    #+#             */
/*   Updated: 2022/04/29 10:45:48 by kshim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "unistd.h"

int	print_output(t_list *lst_head)
{
	t_fp_content	*content;
	int				how_much;

	how_much = 0;
	while (lst_head != NULL)
	{
		content = (t_fp_content *)(lst_head -> content);
		write(1, content -> output, content -> output_len);
		how_much = how_much + content -> output_len;
		lst_head = lst_head -> next;
	}
	return (how_much);
}

char	*ft_set_c(t_fp_formats *formats)
{
	char	*tmp;
	char	c;

	tmp = (char *)malloc(2);
	if (tmp == NULL)
		return (NULL);
	c = (char)va_arg(*(formats -> ap), int);
	tmp[0] = c;
	tmp[1] = '\0';
	return (tmp);
}

void	ft_fp_free_data(t_fp_str **data)
{
	(*data)-> width_pad = 0;
	(*data)-> prec_pad = 0;
	(*data)-> ap_len = 0;
	(*data)-> output_len = 0;
	free((*data)-> processed_ap);
	(*data)-> processed_ap = NULL;
	free(*data);
	*data = NULL;
	return ;
}

void	ft_fp_free_formats(t_fp_formats **formats)
{
	(*formats)-> width = 0;
	(*formats)-> alternate = 0;
	(*formats)-> zero_fill = 0;
	(*formats)-> left_justify = 0;
	(*formats)-> plus_sign = 0;
	(*formats)-> space_sign = 0;
	(*formats)-> neg_value = 0;
	(*formats)-> precision = 0;
	(*formats)-> prec_val = 0;
	(*formats)-> fs = 0;
	free((*formats));
	(*formats) = NULL;
	return ;
}
