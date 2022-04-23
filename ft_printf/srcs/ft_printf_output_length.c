/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_output_length.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshim <kshim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 13:22:58 by kshim             #+#    #+#             */
/*   Updated: 2022/04/23 15:52:26 by kshim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	len_of_ap(t_fp_content *content, t_fp_str *data)
{
	t_fp_formats	formats;

	formats = content -> format_detail;
	if (formats -> fs == c)
		data -> ap_len = 1;
	if (formats -> fs == s)
		data -> ap_len = ft_strlen(formats -> ap_pos);
	if (formats -> fs == p)
		dara -> ap_len = ft_us_long_long_len(
				(unsigned long long)*(formats -> ap_pos), 16);
	if (formats -> fs == d)
		data -> ap_len = ft_s_int_len(*(formats -> ap_pos), 10);
	if (formats -> fs == i)
		data -> ap_len = ft_s_int_len(*(formats -> ap_pos), 10);
	if (formats -> fs == u)
		data -> ap_len = ft_us_int_len(*(formats -> ap_pos), 10);
	if (formats -> fs == x)
		data -> ap_len = ft_us_int_len(*(formats -> ap_pos), 16);
	if (formats -> fs == X)
		data -> ap_len = ft_us_int_len(*(formats -> ap_pos), 16);
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
	if (formats -> width > data -> len)
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
			data -> output_len = prec_val;
			*prec_pad = (data -> output_len) - (data -> ap_len);
		}
		else if (data -> ap_len >= formats -> prec_val)
			data -> output_len = data -> ap_len;
	}
	else
		data -> output_len = data -> ap_len;
	if ((formats -> width) > (data -> output_len))
	{
		*width_pad = (formats -> width) - (data -> output_len);
		data -> output_len = formats -> width;
	}
	return ;
}

size_t	fs_sign_len(t_fp_formats *formats, t_fp_str *data)
{
	if (data -> width_pad >= 1)
	{
		if (formats -> sign != 0)
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
	size_t	i;
	
	i = 0;
	if (formats -> fs == 's')
		data -> processed_ap = formats -> ap_pos;
	else if (formats -> fs == 'c')
	{
		data -> processed_ap = (char *)malloc((data -> ap_len) + 1);
		if (data -> processed_ap == NULL)
			return (-1);
	}	
	else if (formats -> fs == 'd' || formats -> fs == 'i'
			|| formats -> fs == 'x' || formats -> fs == 'X' || foramts -> fs == 'p')
		data -> processed_ap = ft_itoa_base();
	return (-1);
}
