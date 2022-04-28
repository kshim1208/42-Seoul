/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_output_length.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshim <kshim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 13:22:58 by kshim             #+#    #+#             */
/*   Updated: 2022/04/28 15:54:42 by kshim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	len_of_output(t_fp_formats *formats, t_fp_str *data)
{
	if (formats -> fs == 'c')
		data -> ap_len = 1;
	else
		data -> ap_len = ft_strlen(data -> processed_ap);
	if (formats -> fs == 's' || formats -> fs == 'c')
		fs_chars_len(formats, data);
	else if (formats -> fs == 'd' || formats -> fs == 'i'
		|| formats -> fs == 'u' || formats -> fs == 'x'
		|| formats -> fs == 'X' || formats -> fs == 'p')
		fs_int_len(formats, data);
	if (formats -> space_sign == 1 || formats -> plus_sign == 1
		|| formats -> alternate == 1 || formats -> fs == 'p')
		fs_sign_alter_len(formats, data);
	return (1);
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

void	fs_sign_alter_len(t_fp_formats *formats, t_fp_str *data)
{
	if (formats -> plus_sign == 1 || formats -> space_sign == 1)
	{
		if (data -> width_pad >= 1)
			(data -> width_pad)--;
		else
			(data -> output_len)++;
	}
	else if (formats -> alternate == 1 || formats -> fs == 'p')
	{
		if (data -> width_pad >= 1)
		{
			if (data -> width_pad == 1)
			{
				(data -> width_pad)--;
				(data -> output_len)++;
			}
			else if (data -> width_pad >= 2)
			{	
				data -> width_pad = (data -> width_pad) - 2;
			}
		}
		else
			data -> output_len = (data -> output_len) + 2;
	}
	return ;
}
