/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_flags.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshim <kshim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 16:25:48 by kshim             #+#    #+#             */
/*   Updated: 2022/04/25 15:15:53 by kshim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

/* check value means check_flag func is evaluating current *arg 
 * as one of followings; flags, width, or precision. */
int	check_flags(char *arg, t_fp_content *new_content)
{
	int				check;
	t_fp_formats	*formats;

	check = 1;
	formats = new_content -> format_detail;
	while (*arg != '\0')
	{
		if (check == 1)
			is_flags(arg, formats, &check);
		if (check == 2)
			is_width(arg, formats, &check);
		if (check == 3)
			is_precision(arg, formats, &check);
		if (check == 4)
			return (1);
		if (is_flags_error(formats) == -1)
			return (-1);
		arg++;
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
	if (*arg >= 1 && *arg <= 9)
		*check = 2;
	if (*arg == '.')
		*check = 3;
	if (check_fs(arg) == 1)
		*check = 4;
	return (1);
}

int	is_flags_error(t_fp_formats *formats)
{
	if (formats -> zero_fill == 1 && formats -> left_justify == 1)
		return (-1);
	if (formats -> space_sign == 1 && formats -> plus_sign == 1)
		return (-1);
	if ((formats -> fs != 'd' && formats -> fs != 'i')
		&& (formats -> plus_sign == 1 || formats -> space_sign == 1))
		return (-1);
	if ((formats -> fs == 'c' || formats -> fs == 's' || formats -> fs == 'p')
		&& formats -> zero_fill == 1)
		return (-1);
	if ((formats -> fs != 'x' && formats -> fs == 'X')
		&& formats -> alternate == 1)
		return (-1);
	if ((formats -> fs == 'c' || formats -> fs == 'p')
		&& formats -> precision == 1)
		return (-1);
	return (1);
}

int	is_width(char *arg, t_fp_formats *formats, int *check)
{
	if (*arg >= 0 && *arg <= 9)
		formats -> width = (formats -> width) * 10 + ((*arg) - '0');
	else if (*arg == '.')
		*check = 3;
	else if (check_fs(arg) == 1)
		*check = 4;
	else
		return (-1);
	return (1);
}

	/* precision이 1일 때 prec_value가 0이면 둘 중 하나 -> 
	 * 0 들어왔던가 안들어왔던가. 두 경우 모두 최소치가 0이므로 출력은 없었음 */
int	is_precision(char *arg, t_fp_formats *formats, int *check)
{
	if (*arg == '.' && formats -> precision == 0)
		formats -> precision = 1;
	else if (*arg >= 0 && *arg <= 9)
		formats -> prec_val
			= (formats -> prec_val) * 10 + ((*arg) - '0');
	else if (check_fs(arg) == 1)
		*check = 4;
	else
		return (-1);
	return (1);
}
