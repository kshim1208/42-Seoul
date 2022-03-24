/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshim <kshim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 20:56:06 by kshim             #+#    #+#             */
/*   Updated: 2022/01/25 13:58:57 by kshim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	unsigned int	how_many;
	unsigned int	i;

	if (min >= max)
	{
		range = NULL;
		return (0);
	}
	how_many = max - min;
	i = 0;
	*range = (int *)malloc(sizeof(int) * how_many);
	if (*range == NULL)
		return (how_many);
	while (i != how_many)
	{
		(*range)[i] = min + i;
		i++;
	}
	return (how_many);
}
