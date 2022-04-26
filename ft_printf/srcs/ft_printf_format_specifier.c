/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_format_specifier.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshim <kshim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 12:35:47 by kshim             #+#    #+#             */
/*   Updated: 2022/04/26 12:39:02 by kshim            ###   ########.fr       */
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

uintptr_t	check_fs_type_size(va_list *ap, t_fp_formats *format)
{
	/* 초기화는 필요한데 예외처리 기능 굳이 필요하진 않다. 어떤 값을 넣어야 할까? */
	if (format -> fs == 'c')
		return ((uintptr_t)va_arg(*ap, int));
	else if (format -> fs == 's')
		return ((uintptr_t)va_arg(*ap, uintptr_t));
	else if (format -> fs == 'p')
		return ((uintptr_t)va_arg(*ap, uintptr_t));
	else if (format -> fs == 'd')
		return ((uintptr_t)va_arg(*ap, int));
	else if (format -> fs == 'i')
		return ((uintptr_t)va_arg(*ap, int));
	else if (format -> fs == 'u')
		return ((uintptr_t)va_arg(*ap, unsigned int));
	else if (format -> fs == 'x')
		return ((uintptr_t)va_arg(*ap, unsigned int));
	else if (format -> fs == 'X')
		return ((uintptr_t)va_arg(*ap, unsigned int));
	return (0);
}

void	set_va_and_fs(char *arg, va_list *ap, t_fp_content *new_content)
{
	uintptr_t		cur;
	t_fp_formats	*format;

	format = new_content -> format_detail;
	format -> fs = *arg;
	cur = check_fs_type_size(ap, format);
	format -> ap_pos = cur;
	return ;
}
