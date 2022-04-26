/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pritnf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshim <kshim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 09:02:14 by kshim             #+#    #+#             */
/*   Updated: 2022/04/26 14:25:50 by kshim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

size_t	ft_s_int_len(int num, int base)
{
	int	i;

	i = 0;
	if (num == 0)
		i++;
	if (num == -2147483648)
	{
		i++;
		num = -214748364;
	}
	if (num < 0)
		num = -1 * num;
	while (num > 0)
	{
		num = num / base;
		i++;
	}
	return (i);
}

size_t	ft_us_int_len(unsigned int num, int base)
{
	int	i;

	i = 0;
	if (num == 0)
		i++;
	while (num > 0)
	{
		num = num / base;
		i++;
	}
	return (i);
}

size_t	ft_uintptr_len(uintptr_t addr, int base)
{
	int	i;

	i = 0;
	if (addr > 0)
	{
		addr = addr / base;
		i++;
	}
	return (i);
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
