/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_flags.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshim <kshim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 16:25:48 by kshim             #+#    #+#             */
/*   Updated: 2022/04/29 11:08:20 by kshim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	check_flags(char **arg, t_fp_content *new_content)
{
	int				check;
	t_fp_formats	*formats;

	check = 1;
	formats = new_content -> format_detail;
	while (**arg != '\0')
	{
		if (check == 1)
			is_flags(*arg, formats, &check);
		if (check == 2)
			is_width_precision(*arg, formats, &check);
		if (check == 3)
			is_width_precision(*arg, formats, &check);
		if (check == 4)
		{
			formats -> fs = **arg;
			return (1);
		}
		(*arg)++;
	}
	return (1);
}

int	is_flags(char *arg, t_fp_formats *formats, int *check)
{
	if (*arg == '#')
		formats -> alternate = 1;
	if (*arg == '0')
		formats -> zero_fill = 1;
	if (*arg == '+')
		formats -> plus_sign = 1;
	if (*arg == ' ')
		formats -> space_sign = 1;
	if (*arg == '-')
		formats -> left_justify = 1;
	if (*arg >= '1' && *arg <= '9')
		*check = 2;
	if (*arg == '.')
		*check = 3;
	if (check_fs(arg) == 1)
		*check = 4;
	return (1);
}

int	is_width_precision(char *arg, t_fp_formats *formats, int *check)
{
	if (*check == 2)
	{
		if (*arg >= '0' && *arg <= '9')
			formats -> width = (formats -> width) * 10 + ((*arg) - '0');
		else if (*arg == '.')
			*check = 3;
		else if (check_fs(arg) == 1)
			*check = 4;
		else
			return (-1);
	}
	else if (*check == 3)
	{
		if (*arg == '.' && formats -> precision == 0)
			formats -> precision = 1;
		else if (*arg >= '0' && *arg <= '9')
			formats -> prec_val
				= (formats -> prec_val) * 10 + ((*arg) - '0');
		else if (check_fs(arg) == 1)
			*check = 4;
		else
			return (-1);
	}
	return (1);
}

int	is_flags_error(t_fp_content *content)
{
	t_fp_formats	*formats;

	formats = content -> format_detail;
	if (formats -> zero_fill == 1 && formats -> left_justify == 1)
		formats -> zero_fill = 0;
	if (formats -> space_sign == 1 && formats -> plus_sign == 1)
		formats -> space_sign = 0;
	if ((formats -> fs != 'd' && formats -> fs != 'i')
		&& (formats -> space_sign == 1))
		return (-1);
	if ((formats -> fs != 'd' && formats -> fs != 'i')
		&& (formats -> plus_sign == 1))
		return (-1);
	if ((formats -> fs == 'c' || formats -> fs == 's' || formats -> fs == 'p')
		&& formats -> zero_fill == 1)
		return (-1);
	if ((formats -> fs != 'x' && formats -> fs != 'X')
		&& formats -> alternate == 1)
		return (-1);
	if ((formats -> fs == 'c' || formats -> fs == 'p')
		&& formats -> precision == 1)
		return (-1);
	return (1);
}

int	check_fs(char *arg)
{
	if (*arg == 'c' || *arg == 's' || *arg == 'p' || *arg == 'd'
		|| *arg == 'i' || *arg == 'u' || *arg == 'x' || *arg == 'X')
		return (1);
	return (0);
}
