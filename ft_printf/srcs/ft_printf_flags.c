/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_flags.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshim <kshim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 16:25:48 by kshim             #+#    #+#             */
/*   Updated: 2022/04/20 13:11:56 by kshim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* check value means check_flag func is evaluating current *arg 
 * as one of followings; flags, width, or precision. */
int	check_flags(char *arg, t_fp_content *new_content)
{
	int				check;
	int				ret;
	t_fp_formats 	formats;

	check = 1;
	ret = 1;
	formats = new_content -> format_detail;
	while(*arg != '\0')
	{
		if (check == 1)
			ret = is_flags(arg, formats, &check);
		if (check == 2)
			ret = is_width(arg, formats, &check);
		if (check == 3)
			ret = is_precision(arg, formats, &check);
		if (check == 4)
			return (1);
		if (ret = -1)
			return (ret);
		arg++;
	}
	return (ret);	
}

int	is_flags(char *arg, t_fp_formats *new_formats, int *check)
{
	if (*arg == '#')
		new_formats -> alternate = 1;
	if (*arg == '0')
		new_formats -> zero_fill = 1;
	if (*arg == '+')
		new_formats -> sign = 1;
	if (*arg == ' ')
		new_formats -> sign = 2;
	if (*arg == '-')
		new_formats -> left_justify = 1;
	if (*arg >= 1 && *arg <= 9)
		*check = 2;
	if (*arg == '.')
		*check = 3;
	if (check_format_specifier(arg) == 1)
		*check = 4;
	if (is_flags_error(arg, new_formats) == -1)
		return (-1);
	return (1);
}
int 

int	is_flags_error(char *arg, t_fp_formats *new_formats)
{
	if (*arg == '0' && new_formats -> left_justify == 1)
		return (-1);
	if (*arg == '-' && new_formats -> zero_fill == 1)
		return (-1);
	if (*arg == ' ' && new_formats -> sign == 1)
		return (-1);
	if (*arg == '+' && new_formats -> sign == 2)
		return (-1);
	return (1);
}

int	is_width(char *arg, t_fp_formats *new_formats, int *check)
{
	if (*arg >= 0 && *arg <= 9)
		new_formats -> width = (new_formats -> width) * 10 + ((*arg) - '0');
	else if (*arg == '.')
		*check = 3;
	else if (check_format_specifier(arg) == 1)
		*check = 4;
	else
		return (-1);
	return (1);
}

	/* precision이 1일 때 prec_value가 0이면 둘 중 하나 -> 
	 * 0 들어왔던가 안들어왔던가. 두 경우 모두 최소치가 0이므로 출력은 없었음 */
int	is_precision(char *arg, t_fp_formats *new_formats, int *check)
{
	if (*arg == '.' && new_formats -> precision == 0)
		new_formats -> precision = 1;
	else if (*arg >= 0 && *arg <= 9)
		new_formats -> prec_val = (new_formats -> prec_val) * 10 + ((*arg) - '0');
	else if (check_format_specifier(arg) == 1)
		*check = 4;
	else 
		return (-1);
	return (1);
}
