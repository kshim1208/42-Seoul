/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_process_output.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshim <kshim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 13:43:13 by kshim             #+#    #+#             */
/*   Updated: 2022/04/29 09:21:41 by kshim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	process_output(t_fp_content *work_content)
{
	t_fp_str		*str_data;

	str_data = (t_fp_str *)malloc(sizeof(t_fp_str));
	if (str_data == NULL)
		return (-1);
	str_data -> width_pad = 0;
	str_data -> prec_pad = 0;
	str_data -> ap_len = 0;
	str_data -> output_len = 0;
	str_data -> processed_ap = NULL;
	if (make_fs_output(work_content, str_data) == -1)
	{
		ft_fp_free_data(&str_data);
		return (-1);
	}
	ft_fp_free_data(&str_data);
	return (1);
}

int	make_fs_output(t_fp_content *content, t_fp_str *data)
{
	char			*fs_output;
	t_fp_formats	*formats;
	int				ret;

	formats = content -> format_detail;
	if (formats -> fs == 'c' || formats -> fs == 's')
		ret = fs_process_char_ap(formats, data);
	else if (formats -> fs == 'd' || formats -> fs == 'i')
		ret = fs_process_int_ap(formats, data);
	else
		ret = fs_process_uint_ap(formats, data);
	if (ret == -1)
		return (-1);
	if (len_of_output(formats, data) == -1)
		return (-1);
	content -> output_len = data -> output_len;
	fs_output = set_output(formats, data);
	if (fs_output == NULL)
		return (-1);
	content -> output = fs_output;
	return (1);
}

int	fs_process_char_ap(t_fp_formats *formats, t_fp_str *data)
{
	char	*str;

	str = NULL;
	if (formats -> fs == 's')
	{
		str = va_arg(*formats -> ap, char *);
		if (str == NULL)
			data -> processed_ap = ft_strdup("(null)");
		else
			data -> processed_ap = ft_strdup(str);
	}
	else if (formats -> fs == 'c')
		data -> processed_ap = ft_set_c(formats);
	if (data -> processed_ap == NULL)
		return (-1);
	return (1);
}

int	fs_process_int_ap(t_fp_formats *formats, t_fp_str *data)
{
	if (formats -> fs == 'd' || formats -> fs == 'i')
		data -> processed_ap = ft_itoa_base(
				va_arg(*formats -> ap, int), 10);
	if (data -> processed_ap == NULL)
		return (-1);
	if ((data -> processed_ap)[0] == '-')
		formats -> neg_value = 1;
	return (1);
}

int	fs_process_uint_ap(t_fp_formats *formats, t_fp_str *data)
{
	if (formats -> fs == 'u')
		data -> processed_ap = ft_uitoa_base(
				va_arg(*formats -> ap, unsigned int), 10, 0);
	else if (formats -> fs == 'x')
		data -> processed_ap = ft_uitoa_base(
				va_arg(*formats -> ap, unsigned int), 16, 0);
	else if (formats -> fs == 'X')
		data -> processed_ap = ft_uitoa_base(
				va_arg(*formats -> ap, unsigned int), 16, 1);
	else if (formats -> fs == 'p')
		data -> processed_ap = ft_uintptr_to_a(
				va_arg(*formats -> ap, uintptr_t), 0);
	if (data -> processed_ap == NULL)
		return (-1);
	return (1);
}
