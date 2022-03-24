/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_reverse_alphabet.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshim <kshim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 12:30:50 by kshim             #+#    #+#             */
/*   Updated: 2022/01/11 09:58:06 by kshim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
void	ft_print_reverse_alphabet(void)
{
	char	r_alpha;

	r_alpha = 'z';
	while (r_alpha >= 'a' )
	{
		write(1, &r_alpha, 1);
		r_alpha--;
	}
}
