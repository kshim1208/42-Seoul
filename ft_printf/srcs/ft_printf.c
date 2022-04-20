/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshim <kshim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 10:56:58 by kshim             #+#    #+#             */
/*   Updated: 2022/04/20 13:44:59 by kshim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "libftprintf.h"

int	ft_printf(const char *arg, ...)
{
	va_list			ap;
	t_lst			*lst_head;
	int				ret;

	if (*arg == "")
		return (0);
	va_start(ap, sizeof(uintptr_t));
	ret = process_arg(arg, &ap, *lst_head);
	if (ret == -1)
		ft_lstclear();
	/* 만약 format specifier와 va 인자 개수가 다르면 예외 처리?? */
	ret = process_output(lst_head);
	if (ret == -1)
		ft_lstclear();
	va_end(ap);
	return (ret);
}

int	process_arg(char *arg, va_list *ap, t_lst *lst_head)
{
	int		percent_char;
	char	*start;

	lst_head == NULL;
	i = 0;
	while (*arg != '\0')
	{
		percent_char = 0;
		if (*arg == '%' && *(arg + 1) != '%')
		{
			arg = set_node_format(arg, ap, &lst_head);
			if (arg == NULL)
				return (-1);
		}
		start = arg;
		while (*arg != '%' && *arg != '\0')
			arg++;
		if (*arg != '\0' && *arg == '%' && *(arg + 1) == '%')
		{
			arg++;
			percent_char = 1;
		}
		start = set_node_str(arg, start, &lst_head);
		if (start == NULL)
			return (-1);
		if (percent_char == 1)
			arg++;
	}
	return (1);
}

char	*set_node_format(char *arg, va_list *ap, t_lst **lst_head)
{
	char			*tmp;
	t_lst			new_node_lst;
	t_fp_content	new_content;	

	tmp = arg + 1;
	if (*tmp == '\0')
		return (NULL);
	new_lst = set_new_content(lst_head, 1);
	if (new_lst == NULL)
		return (NULL);
	new_content = new_lst ->(t_fp_content *)content;
	check_flags(&tmp, new_content);
	if (check_flag(&tmp, new_content) == -1)
		return (NULL);
	if (check_format_specifier(tmp))
	{
		new_content -> format_detail -> format_specifier = *tmp;
		set_va_and_fs(arg, ap, new_content);
		return (++tmp);
	}
	return (NULL);
}

char	*set_node_str(char *arg, char *start, t_lst **lst_head)
{
	t_lst	new_lst;
	size_t	len;
	char	*str;

	len = arg - start;
	str = (char *)malloc(len + 1);
	if (str == NULL)
		return (NULL);
	len = ft_strlcpy(str, start, len);
	new_lst = set_new_content(lst_head, 0);
	if (new_lst == NULL)
		return (NULL);
	return (str);
}
