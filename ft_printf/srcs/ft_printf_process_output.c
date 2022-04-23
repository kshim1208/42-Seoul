/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_process_output.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshim <kshim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 13:43:13 by kshim             #+#    #+#             */
/*   Updated: 2022/04/23 15:52:29 by kshim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	process_output(t_lst *lst)
{
	t_fp_content	*work_content;
	t_ft_str		*str_data;
	int				ret;

	while (lst != NULL)
	{
		work_content = lst ->(t_fp_content *)content;
		str_data = (t_fp_str *)malloc(sizeof(t_fp_str));
		if (str_data == NULL)
			return (-1);
		str_data -> width_pad == 0;
		str_data -> prec_pad == 0;
		str_data -> ap_len == 0;
		str_data -> output_len == 0;
		str_data -> processed_ap == NULL;
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
	t_fp_formats	formats;
	t_fp_str		*str_data;
	size_t			*ret;

	ret = 1;
	formats = content -> format_detail;
	len_of_ap(content, str_data);
	len_of_output(content, str_data);
	fs_output = put_chars(formats, str_data);
	if (fs_output == NULL)
	{
		free_data(str_data);
		return (-1);
	}
	content -> output = fs_output;
	free_data(str_data); /* data 구조체 해제 */
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
	/* s와 c, 정수들과 p, 서로 구분할 필요가 있을까? */
	return ;
}

char	*put_chars(t_fp_formats *formats, t_fp_str *data)
{
	char	*str;
	char	*tmp;
	size_t	i;

	/* data -> processed_ap 설정하기. 실패하면 반환해서 문제 생겼다고 알림 */
	tmp = NULL;
	str = (char *)malloc(len + 1);
	if (str == NULL)
		return (NULL);
	str[len] = '\0';
	i = 0;
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
	if (formats -> sign == 1)
		str[i++] = '+';
	else if (formats -> sign == 2)
		str[i++] = ' ';
	if (formats -> alternate == 1)
	{
		str[i++] = '0';
		if (formats -> fs == 'x')
			str[i++] = 'x';
		else if (formats -> fs = 'X')
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
			str[i++] = /* ap_pos의 값 문자로 변환하여 차례대로 -> 함수로 새 문자열 만들 필요성이 있음. 사용한 뒤에 여기서 해제. 아니면 data에 보관했다가 data 해제할 때 같이 해제하면 될 것 같다. 반드시 fs로 인해 조절된 문자열을 사용하게 되니까 후자가 나을 듯. -> ap_len만큼의 길이를 가지는 문자열로 할당 후 저장*/  ;
			(data -> ap_len)--;
		}
	}
	else
	{
		while (data -> ap_len != 0)
		{
			str[i++] = /* */;
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
