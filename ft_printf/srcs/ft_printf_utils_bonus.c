/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_print_out.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshim <kshim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 14:42:22 by kshim             #+#    #+#             */
/*   Updated: 2022/05/01 10:49:50 by kshim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "unistd.h"

void	ft_fp_put_str(char *str, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		write(1, (str + i), 1);
		i++;
	}
	return ;
}

int	check_fs(char *arg)
{
	if (*arg == 'c' || *arg == 's' || *arg == 'p' || *arg == 'd'
		|| *arg == 'i' || *arg == 'u' || *arg == 'x' || *arg == 'X')
		return (1);
	return (0);
}

char	*ft_set_c(t_fp_formats *formats)
{
	char	*tmp;
	char	c;

	tmp = (char *)malloc(2);
	if (tmp == NULL)
		return (NULL);
	c = (char)va_arg(*formats -> ap, int);
	tmp[0] = c;
	tmp[1] = '\0';
	return (tmp);
}

void	ft_fp_free_data(t_fp_str **data)
{
	(*data)-> width_pad = 0;
	(*data)-> prec_pad = 0;
	(*data)-> ap_len = 0;
	(*data)-> output_len = 0;
	free((*data)-> processed_ap);
	(*data)-> processed_ap = NULL;
	free(*data);
	*data = NULL;
	return ;
}

void	ft_fp_free_formats(t_fp_formats **formats)
{
	(*formats)-> width = 0;
	(*formats)-> alternate = 0;
	(*formats)-> zero_fill = 0;
	(*formats)-> left_justify = 0;
	(*formats)-> plus_sign = 0;
	(*formats)-> space_sign = 0;
	(*formats)-> neg_value = 0;
	(*formats)-> precision = 0;
	(*formats)-> prec_val = 0;
	(*formats)-> fs = 0;
	free((*formats));
	(*formats) = NULL;
	return ;
}
