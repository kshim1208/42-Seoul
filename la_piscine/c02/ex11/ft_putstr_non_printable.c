/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshim <kshim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 10:08:53 by kshim             #+#    #+#             */
/*   Updated: 2022/01/19 18:27:25 by kshim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
void	put_char(char c);
void	dec_to_hex(int d);

void	ft_putstr_non_printable(char *str)
{
	int				i;
	unsigned char	temp;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 32 && str[i] <= 126)
			put_char(str[i]);
		else
		{
			if (str[i] < 0)
			{
				temp = str[i] + 256;
			}
			else
				temp = str[i];
			put_char('\\');
			dec_to_hex(temp);
		}
		i++;
	}
}

void	put_char(char c)
{
	write(1, &c, 1);
}

void	dec_to_hex(int d)
{
	put_char("0123456789abcdef"[d / 16]);
	put_char("0123456789abcdef"[d % 16]);
}
