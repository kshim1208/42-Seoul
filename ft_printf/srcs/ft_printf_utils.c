/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pritnf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshim <kshim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 09:02:14 by kshim             #+#    #+#             */
/*   Updated: 2022/04/23 15:41:45 by kshim            ###   ########.fr       */
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

size_t	ft_us_long_long_len(unsigned long long addr, int base)
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

/* data 구조체들 초기화 및 해제 필요 char *processed_ap랑 t_fp_str 자체 */
