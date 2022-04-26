/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_output_length.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshim <kshim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 13:22:58 by kshim             #+#    #+#             */
/*   Updated: 2022/04/26 14:18:05 by kshim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	len_of_ap(t_fp_formats *formats, t_fp_str *data)
{
	if (formats -> fs == 'c')
		data -> ap_len = 1;
	if (formats -> fs == 's')
		data -> ap_len = ft_strlen(((const char *)(formats -> ap_pos)));
	if (formats -> fs == 'p')
		data -> ap_len = ft_uintptr_len(
				(uintptr_t)(formats -> ap_pos), 16);
	if (formats -> fs == 'd')
		data -> ap_len = ft_s_int_len(formats -> ap_pos, 10);
	if (formats -> fs == 'i')
		data -> ap_len = ft_s_int_len(formats -> ap_pos, 10);
	if (formats -> fs == 'u')
		data -> ap_len = ft_us_int_len(formats -> ap_pos, 10);
	if (formats -> fs == 'x')
		data -> ap_len = ft_us_int_len(formats -> ap_pos, 16);
	if (formats -> fs == 'X')
		data -> ap_len = ft_us_int_len(formats -> ap_pos, 16);
	return ;
}

void	fs_chars_len(t_fp_formats *formats, t_fp_str *data)
{
	if (formats -> precision == 1)
	{
		if (data -> ap_len < formats -> prec_val)
			data -> output_len = data -> ap_len;
		else if (data -> ap_len >= formats -> prec_val)
		{
			data -> output_len = formats -> prec_val;
			data -> ap_len = formats -> prec_val;
		}	
	}
	else
		data -> output_len = data -> ap_len;
	if (formats -> width > data -> ap_len)
	{
		data -> width_pad = (formats -> width) - (data -> output_len);
		data -> output_len = formats -> width;
	}
	return ;
}

void	fs_int_len(t_fp_formats *formats, t_fp_str *data)
{
	if (formats -> precision == 1)
	{
		if (data -> ap_len < formats -> prec_val)
		{
			data -> output_len = formats -> prec_val;
			data -> prec_pad = (data -> output_len) - (data -> ap_len);
		}
		else if (data -> ap_len >= formats -> prec_val)
			data -> output_len = data -> ap_len;
	}
	else
		data -> output_len = data -> ap_len;
	if ((formats -> width) > (data -> output_len))
	{
		data -> width_pad = (formats -> width) - (data -> output_len);
		data -> output_len = formats -> width;
	}
	return ;
}

void	fs_sign_len(t_fp_formats *formats, t_fp_str *data)
{
	if (data -> width_pad >= 1)
	{
		if (formats -> space_sign != 0 || formats -> plus_sign != 0)
			data -> width_pad--;
	}
	else
		(data -> output_len)++;
	if (data -> width_pad >= 1)
	{
		if (data -> width_pad == 1)
		{
			if (formats -> alternate != 0)
				data -> width_pad = (data -> width_pad) - 1;
			(data -> output_len)++;
		}
		else
		{
			if (formats -> alternate != 0)
				data -> width_pad = (data -> width_pad) - 2;
		}
	}
	else
		data -> output_len = (data -> output_len) + 2;
	return ;
}

int	fs_process_ap(t_fp_formats *formats, t_fp_str *data)
{
	char	*ch;

	ch = NULL;
	if (formats -> fs == 's')
		data -> processed_ap = ft_strndup(
				(char *)formats -> ap_pos, data -> ap_len);
	else if (formats -> fs == 'c')
	{
		ch = (char *)malloc((data -> ap_len) + 1);
		if (ch == NULL)
			return (-1);
		*ch = formats -> ap_pos;
		ch[(data -> ap_len)] = '\0';
		data -> processed_ap = ch;
	}
	else if (formats -> fs == 'd' || formats -> fs == 'i')
		data -> processed_ap = ft_itoa_base(formats -> ap_pos, 10);
	else if (formats -> fs == 'u')
		data -> processed_ap = ft_uitoa_base(formats -> ap_pos, 10);
	else if (formats -> fs == 'x' || formats -> fs == 'X')
		data -> processed_ap = ft_uitoa_base(formats -> ap_pos, 16);
	else if (formats -> fs == 'p')
		data -> processed_ap = ft_uintptr_to_a(formats -> ap_pos);
	return (1);
}
