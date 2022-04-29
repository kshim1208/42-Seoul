/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_process_output2.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshim <kshim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 11:20:23 by kshim             #+#    #+#             */
/*   Updated: 2022/04/29 11:46:52 by kshim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*set_output(t_fp_formats *formats, t_fp_str *data)
{
	char	*str;
	char	*tmp;
	size_t	i;

	i = 0;
	str = (char *)malloc((data -> output_len) + 1);
	if (str == NULL)
		return (NULL);
	str[data -> output_len] = '\0';
	tmp = str;
	if (formats -> left_justify == 0 && formats -> precision == 1)
		set_width_pad(formats, data, &tmp);
	set_sign(formats, &tmp, &i);
	if (formats -> left_justify == 0 && formats -> precision == 0)
		set_width_pad(formats, data, &tmp);
	set_alternate(formats, &tmp);
	set_char(formats, data, &tmp, &i);
	if (formats -> left_justify == 1)
		set_width_pad(formats, data, &tmp);
	return (str);
}

void	set_sign(t_fp_formats *formats, char **str, size_t *i)
{
	{
		if (formats -> neg_value == 1)
		{
			**str = '-';
			(*str)++;
			(*i)++;
		}
		else if (formats -> plus_sign == 1 || formats -> space_sign == 1)
		{
			if (formats -> plus_sign == 1)
				**str = '+';
			else if (formats -> space_sign == 1)
				**str = ' ';
		(*str)++;
		}
	}
	return ;
}

void	set_alternate(t_fp_formats *formats, char **str)
{
	if (formats -> alternate == 1 || formats -> fs == 'p')
	{
		**str = '0';
		(*str)++;
		if (formats -> fs == 'x' || formats -> fs == 'p')
			**str = 'x';
		else if (formats -> fs == 'X')
			**str = 'X';
		(*str)++;
	}
	return ;
}

void	set_width_pad(t_fp_formats *formats, t_fp_str *data, char **str)
{
	while (data -> width_pad != 0)
	{
		if (formats -> zero_fill == 1 && formats -> precision == 0)
			**str = '0';
		else
			**str = ' ';
		(*str)++;
		(data -> width_pad)--;
	}
	return ;
}

void	set_char(t_fp_formats *formats, t_fp_str *data, char **str, size_t *i)
{
	if (formats -> precision == 1)
	{
		while (data -> prec_pad != 0)
		{
			**str = '0';
			(*str)++;
			(data -> prec_pad)--;
		}
	}
	while (data -> ap_len != 0)
	{
		**str = *((data -> processed_ap) + *i);
		(*i)++;
		(*str)++;
		(data -> ap_len)--;
	}
	return ;
}
