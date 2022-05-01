/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshim <kshim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 10:56:58 by kshim             #+#    #+#             */
/*   Updated: 2022/05/01 11:29:01 by kshim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "unistd.h"

static int	process_arg(char *arg, va_list *ap);
static void	put_percent(char **arg, int *how_many);
static void	put_format(char **arg, va_list *ap, int *how_many);
static void	put_str(char **arg, char *start, int *how_many);

int	ft_printf(const char *arg, ...)
{
	va_list		ap;
	int			ret;

	va_start(ap, arg);
	ret = process_arg((char *)arg, &ap);
	va_end(ap);
	return (ret);
}

static int	process_arg(char *arg, va_list *ap)
{
	char	*start;
	int		how_many;

	how_many = 0;
	while (*arg != '\0')
	{
		if (*arg == '%')
		{
			if (*(arg + 1) == '%')
				put_percent(&arg, &how_many);
			else
				put_format(&arg, ap, &how_many);
		}
		start = arg;
		while (how_many != -1 && *arg != '%' && *arg != '\0')
			arg++;
		if (arg - start != 0)
			put_str(&arg, start, &how_many);
		if (how_many == -1)
			return (how_many);
	}
	return (how_many);
}

static void	put_percent(char **arg, int *how_many)
{
	size_t	pf_ret;

	pf_ret = *how_many;
	if (pf_ret + 1 > 2147483647)
		*how_many = -1;
	else
	{
		write(1, "%", 1);
		(*how_many)++;
	}
	*arg = *arg + 2;
	return ;
}

static void	put_format(char **arg, va_list *ap, int *how_many)
{
	t_fp_content	*new_content;	

	(*arg)++;
	if (**arg == '\0')
		return ;
	new_content = set_new_content(1, ap);
	if (new_content == NULL)
		*how_many = -1;
	if (*how_many != -1 && check_flags(arg, new_content) == -1)
		*how_many = -1;
	if (*how_many != -1 && is_flags_error(new_content) == -1)
		*how_many = -1;
	if (*how_many != -1 && process_output(new_content, how_many) == -1)
		*how_many = -1;
	if (new_content != NULL)
		fp_del_content(&new_content);
	if (*how_many == -1)
		return ;
	return ;
}

static void	put_str(char **arg, char *start, int *how_many)
{
	size_t			len;
	char			*str;

	len = (*arg) - start;
	str = ft_strndup(start, len);
	if (str == NULL)
		*how_many = -1;
	if (*how_many != -1 && ((len + (size_t)(*how_many)) > 2147483647))
		*how_many = -1;
	else
	{
		ft_fp_put_str(str, len);
		*how_many = *how_many + len;
	}
	if (str != NULL)
		free(str);
	return ;
}
