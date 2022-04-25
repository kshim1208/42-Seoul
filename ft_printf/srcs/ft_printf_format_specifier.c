/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_fs.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshim <kshim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 12:35:47 by kshim             #+#    #+#             */
/*   Updated: 2022/04/25 15:29:17 by kshim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	check_fs(char *arg)
{
	if (*arg == 'c' || *arg == 's' || *arg == 'p' || *arg == 'd'
			|| *arg == 'i' || *arg == 'u' || *arg == 'x' || *arg == 'X')
		return (1);
	return (0);
}

uintptr_t	check_fs_type_size(va_list *ap, t_fp_content *new_content)
{
	/* 초기화는 필요한데 예외처리 기능 굳이 필요하진 않다. 어떤 값을 넣어야 할까? */
	if (new_content -> format_detail -> fs == 'c')
		return ((uintptr_t)va_arg(*ap, sizeof(char)));
	else if (new_content -> format_detail -> fs == 's')
		return ((uintptr_t)va_arg(*ap, sizeof(char *)));
	else if (new_content -> format_detail -> fs == 'p')
		return ((uintptr_t)va_arg(*ap, sizeof(uintptr_t));
	else if (new_content -> format_detail -> fs == 'd')
		return ((uintptr_t)va_arg(*ap, sizeof(int)));
	else if (new_content -> format_detail -> fs == 'i')
		return ((uintptr_t)va_arg(*ap, sizeof(int)));
	else if (new_content -> format_detail -> fs == 'u')
		return ((uintptr_t)va_arg(*ap, sizeof(unsigned int)));
	else if (new_content -> format_detail -> fs == 'x')
		return ((uintptr_t)va_arg(*ap, sizeof(unsigned int)));
	else if (new_content -> format_detail -> fs == 'X')
		return ((uintptr_t)va_arg(*ap, sizeof(unsigned int)));
	return (0);
}

void	set_va_and_fs(char *arg, va_list *ap, t_fp_content *new_content)
{
	uintptr_t	cur;

	new_content -> format_detail -> fs = *arg;
	cur = check_fs_type_size(ap, new_content);
	new_content -> format_detail -> ap_pos = cur;
	return ;
}
