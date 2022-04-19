/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshim <kshim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 11:20:30 by kshim             #+#    #+#             */
/*   Updated: 2022/04/19 15:50:14 by kshim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdint.h>

typedef struct s_printf_node_lst{
	int							is_format;
	union  s_print_node_union	*content;
	struct s_printf_node_lst	*next;
}		t_fp_node_lst;

typedef union u_printf_node_union{
	s_printf_node	*node;
	char			*str;
}		t_fp_union;

typedef struct s_printf_node{
	int		width;
	int		zero_fill;
	int		space_fill;
	int		left_justify;
	int		sign;
	char	format_specifier;
	char	*output;
}		t_fp_node;
#endif
