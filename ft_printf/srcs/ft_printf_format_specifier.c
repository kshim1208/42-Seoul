/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_fs.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshim <kshim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 12:35:47 by kshim             #+#    #+#             */
/*   Updated: 2022/04/25 10:10:24 by kshim            ###   ########.fr       */
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

int	check_fs_type_size(char *arg, t_fp_content *new_content)
{
	int		arg_size;

	if (new_content -> format_detail -> fs == 'c')
		arg_size = sizeof(char);
	else if (new_content -> format_detail -> fs == 's')
		arg_size = sizeof(char *);
	else if (new_content -> format_detail -> fs == 'p')
		arg_size = sizeof(uintptr_t);
	else if (new_content -> format_detail -> fs == 'd')
		arg_size = sizeof(int);
	else if (new_content -> format_detail -> fs == 'i')
		arg_size = sizeof(int);
	else if (new_content -> format_detail -> fs == 'u')
		arg_size = sizeof(unsigned int);
	else if (new_content -> format_detail -> fs == 'x')
		arg_size = sizeof(int);
	else if (new_content -> format_detail -> fs == 'X')
		arg_size = sizeof(int);
	return (arg_size);
}

void	set_va_and_fs(char *arg, va_list *ap, t_fp_content *new_cotent)
{
	va_list	cur;
	int		arg_size;

	arg_size = check_fs_type_size(arg, new_content);
	cur = va_arg(*ap, arg_size);
	new_content -> format_detail -> ap_pos = cur;
	return ;
}
