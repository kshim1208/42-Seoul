/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshim <kshim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 10:56:58 by kshim             #+#    #+#             */
/*   Updated: 2022/04/19 16:27:48 by kshim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.g>
#include "libftprintf.h"

int	ft_printf(const char *arg, ...)
{
	va_list			printf_ap;
	t_fp_node_lst	lst_head;
	int				ret;

	if (*arg == "")
		return (0);
	va_start(printf_ap, sizeof(uintptr_t));
	lst_head = process_arg(arg, printf_ap);
	/* 만약 format specifier와 va 인자 개수가 다르면 예외 처리?? */
	return (ret);
}

t_fp_flags	process_arg(char *arg, va_list printf_ap)
{
	t_fp_node_lst	*lst_head;
	size_t		i;
	size_t		j;
	char	*start;

	lst_head == NULL;
	i = 0;
	j = 0;
	while (*arg != '\0')
	{
		if (*arg == '#')
		{
			arg = set_node_format(arg, &lst_head);
			if (arg == NULL)
				return (NULL);
		}
		start = arg;
		while(*arg != '#' && *arg != '\0')
			arg++;
		start = set_node_str(arg, start, &lst_head);
		if (start == NULL)
			return (NULL);
	}
	return (lst_head);
}

char	*set_node_format(char *arg, t_fp_node_lst **lst_head)
{
	char				*tmp;
	t_fp_node_lst		new_node_lst;

	tmp = arg + 1;
	if (*tmp == '\0')
		return (NULL);
	new_node_lst = set_new_node(lst_head, NULL, 1);
	if (new_node_lst == NULL)
		return (NULL);
	while (check_flags(new_node_lst, tmp))
	{
		tmp++;
	}
	if (check_flag(tmp) == -1)
		return (NULL);
	if (check_format_specifier(tmp))
	{
		new_node_lst -> content -> node -> format_specifier = *tmp;
		return (++tmp);
	}
	return (NULL);
}

char	*set_node_str(char *arg, char *start, t_fp_node_lst **lst_head)
{
	size_t	len;
	char	*str;

	len = start - arg;
	str = (char *)malloc(len + 1);
	if (str == NULL)
		return (NULL);
	len = ft_strlcpy(str, start, len);
	new_node_lst = set_new_node(lst_head, str, 0);
	if (new_node_lst == NULL)
		return (NULL);
	return (str);
}

int	check_format_specifier(char *arg)
{
	if (*arg == 'c' || *arg == 's' || *arg == 'p' || *arg == 'd' 
			|| *arg == 'i' || *arg == 'u' || *arg == 'x' || *arg == 'X'
			|| *arg == '%')
		return (1);
	return (0);
}

t_fp_format_flags	new_node_format(char *arg)
{
	t_fp_format_flags	*new_f_content;
	
	
	return (new_f_content);
}
