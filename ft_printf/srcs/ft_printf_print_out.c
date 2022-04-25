/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_print_out.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshim <kshim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 14:42:22 by kshim             #+#    #+#             */
/*   Updated: 2022/04/25 15:32:47 by kshim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include "unistd.h"

int	print_output(t_list *lst_head)
{
	char			*output_to_print;
	t_fp_content 	*content_to_print;
	int				how_much;

	how_much = 0;
	while (lst_head != NULL)
	{
		content_to_print = lst_head ->(t_fp_content *)content;
		output_to_print = content_to_print -> output;
		write(1, output_to_print, ft_strlen(output_to_print));
		how_much = how_much + ft_strlen(output_to_print);
		lst_head = lst_head -> next;
	}
	return (how_much);
}
