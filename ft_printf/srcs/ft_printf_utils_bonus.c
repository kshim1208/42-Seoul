/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_print_out.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshim <kshim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 14:42:22 by kshim             #+#    #+#             */
/*   Updated: 2022/04/28 14:43:15 by kshim            ###   ########.fr       */
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
