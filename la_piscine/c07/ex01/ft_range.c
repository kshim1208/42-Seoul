/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshim <kshim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 19:07:38 by kshim             #+#    #+#             */
/*   Updated: 2022/01/25 13:57:58 by kshim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

int	*ft_range(int min, int max)
{
	unsigned int	how_many;
	int				*range;
	unsigned int	i;

	if (min >= max)
		return (0);
	how_many = max - min;
	range = (int *)malloc(sizeof(int) * how_many);
	if (range == NULL)
		return (NULL);
	i = 0;
	while (i != how_many)
	{
		range[i] = min + i;
		i++;
	}
	return (range);
}
