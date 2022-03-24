/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshim <kshim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 17:58:08 by kshim             #+#    #+#             */
/*   Updated: 2022/01/25 09:41:18 by kshim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
int		len_valid_base(char *base);
void	put_char(char c);
void	put_number_base(int nbr, int len, char *base);

void	ft_putnbr_base(int nbr, char *base)
{
	int	len;

	len = len_valid_base(base);
	if (len == 0 || len == 1)
		return ;
	else
		put_number_base(nbr, len, base);
}

int	len_valid_base(char *base)
{
	int	i;
	int	j;

	i = 0;
	while (base[i] != '\0')
	{
		if (base[i] == '+' || base[i] == '-')
			return (0);
		j = 1;
		while (base[i + j] != '\0')
		{
			if (base[i] == base[i + j])
				return (0);
			j++;
		}
		i++;
	}
	return (i);
}

void	put_char(char c)
{
	write(1, &c, 1);
}

void	put_number_base(int nbr, int len, char *base)
{
	unsigned int	temp;

	if (nbr == -2147483648)
	{
		put_char('-');
		temp = 2147483648;
		put_number_base((int)(temp / len), len, base);
		put_char(base[(int)(temp % len)]);
		return ;
	}
	else if (nbr < 0)
	{
		put_char('-');
		nbr = nbr * -1;
	}
	if (nbr >= len)
	{
		put_number_base(nbr / len, len, base);
		put_char(base[nbr % len]);
	}
	else
		put_char(base[nbr % len]);
}	
