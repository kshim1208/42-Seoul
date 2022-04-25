/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_process_output.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshim <kshim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 13:43:13 by kshim             #+#    #+#             */
/*   Updated: 2022/04/25 15:17:49 by kshim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	process_output(t_list *lst)
{
	t_fp_content	*work_content;
	t_fp_str		*str_data;
	int				ret;

	while (lst != NULL)
	{
		work_content = lst -> content;
		str_data = (t_fp_str *)malloc(sizeof(t_fp_str));
		if (str_data == NULL)
			return (-1);
		str_data -> width_pad = 0;
		str_data -> prec_pad = 0;
		str_data -> ap_len = 0;
		str_data -> output_len = 0;
		str_data -> processed_ap = NULL;
		if (work_content -> format == 1)
		{
			ret = make_fs_output(work_content, str_data);
			if (ret == -1)
				return (-1);
		}
		lst = lst -> next;
	}
	return (1);
}

int	make_fs_output(t_fp_content *content, t_fp_str *data)
{
	char			*fs_output;
	t_fp_formats	*formats;
	int				ret;

	ret = 1;
	formats = content -> format_detail;
	len_of_ap(formats, data);
	len_of_output(formats, data);
	fs_output = put_chars(formats, data);
	if (fs_output == NULL)
	{
		ft_fp_free_data(&data);
		return (-1);
	}
	content -> output = fs_output;
	ft_fp_free_data(&data);
	return (ret);
}

void	len_of_output(t_fp_formats *formats, t_fp_str *data)
{
	if (formats -> fs == 's' || formats -> fs == 'c')
		fs_chars_len(formats, data);
	if (formats -> fs == 'd' || formats -> fs == 'i'
		|| formats -> fs == 'x' || formats -> fs == 'X' || formats -> fs == 'p')
		fs_int_len(formats, data);
	fs_sign_len(formats, data);
	fs_process_ap(formats, data);
	return ;
}

char	*put_chars(t_fp_formats *formats, t_fp_str *data)
{
	char	*str;
	char	*tmp;
	size_t	i;
	size_t	j;

	tmp = NULL;
	str = (char *)malloc((data -> output_len) + 1);
	if (str == NULL)
		return (NULL);
	str[data -> output_len] = '\0';
	i = 0;
	j = 0;
	if (formats -> left_justify == 0)
	{
		while (data -> width_pad != 0)
		{
			if (formats -> zero_fill == 1 && formats -> precision == 0)
				str[i] = '0';
			else
				str[i] = ' ';
			i++;
			(data -> width_pad)--;
		}
	}
	if (formats -> plus_sign == 1)
		str[i++] = '+';
	else if (formats -> space_sign == 1)
		str[i++] = ' ';
	if (formats -> alternate == 1)
	{
		str[i++] = '0';
		if (formats -> fs == 'x')
			str[i++] = 'x';
		else if (formats -> fs == 'X')
			str[i++] = 'X';
	}
	if (formats -> precision == 1)
	{
		while (data -> prec_pad != 0)
		{
			str[i++] = '0';
			(data -> prec_pad)--;
		}
		while (data -> ap_len != 0)
		{
			str[i++] = *((data -> processed_ap) + j);
			(data -> ap_len)--;
		}
	}
	else
	{
		while (data -> ap_len != 0)
		{
			str[i++] = *((data -> processed_ap) + j);
			(data -> ap_len)--;
		}		
	}
	if (formats -> left_justify == 1)
	{
		while (data -> width_pad != 0)
		{
			if (formats -> zero_fill == 1 && formats -> precision == 0)
				str[i] = '0';
			else
				str[i] = ' ';
			i++;
			(data -> width_pad)--; 
		}
	}
	return (str);
}
