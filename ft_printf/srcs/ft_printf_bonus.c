/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshim <kshim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 10:56:58 by kshim             #+#    #+#             */
/*   Updated: 2022/04/29 10:29:23 by kshim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	process_arg(char *arg, va_list *ap, t_list **lst_head);
static char	*set_node_format(char *arg, va_list *ap, t_list **lst_head);
static char	*set_node_str(char **arg, char *start, t_list **lst_head, int *per);

int	ft_printf(const char *arg, ...)
{
	va_list		ap;
	t_list		*lst_head;
	int			ret;
	void		*del;

	lst_head = NULL;
	va_start(ap, arg);
	ret = process_arg((char *)arg, &ap, &lst_head);
	va_end(ap);
	if (ret != -1)
		ret = print_output(lst_head);
	del = fp_del_content;
	ft_lstclear(&lst_head, del);
	return (ret);
}

static int	process_arg(char *arg, va_list *ap, t_list **lst_head)
{
	int		percent_char;
	char	*start;

	while (*arg != '\0')
	{
		percent_char = 0;
		if (*arg == '%' && *(arg + 1) != '%')
		{
			arg = set_node_format(arg, ap, lst_head);
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
		start = set_node_str(&arg, start, lst_head, &percent_char);
		if (start == NULL)
			return (-1);
	}
	return (1);
}

static char	*set_node_format(char *arg, va_list *ap, t_list **lst_head)
{
	char			*tmp;
	t_list			*new_lst;
	t_fp_content	*new_content;	

	tmp = arg + 1;
	if (*tmp == '\0')
		return (NULL);
	new_lst = make_new_content(lst_head, 1, ap);
	if (new_lst == NULL)
		return (NULL);
	new_content = new_lst -> content;
	if (check_flags(&tmp, new_content) == -1)
		return (NULL);
	if (is_flags_error(new_content) == -1)
		return (NULL);
	if (process_output(new_content) == -1)
		return (NULL);
	return (++tmp);
}

static char	*set_node_str(char **arg, char *start, t_list **lst_head, int *per)
{
	t_list	*new_lst;
	size_t	len;
	char	*str;

	len = (*arg) - start;
	str = (char *)malloc(len + 1);
	if (str == NULL)
		return (NULL);
	len = ft_strlcpy(str, start, len + 1);
	new_lst = make_new_content(lst_head, 0, 0);
	if (new_lst == NULL)
		return (NULL);
	((t_fp_content *)new_lst -> content)-> output = str;
	((t_fp_content *)new_lst -> content)-> output_len = ft_strlen(str);
	if (*per == 1)
		(*arg)++;
	return (str);
}