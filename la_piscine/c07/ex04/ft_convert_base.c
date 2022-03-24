/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshim <kshim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 19:03:52 by kshim             #+#    #+#             */
/*   Updated: 2022/03/24 10:51:26 by kshim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

int		len_valid_base(char *base);
int		ft_len_base_int(int nbr, int len);
char	*ft_itoa_base(int nbr, int len, char *base);
int		ft_atoi_base(char *str, char *base);
void	set_nb_base(int nbr, int len, char *base, char *ret);

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		i_nbr;	
	int		len_from;
	int		len_to;

	len_from = len_valid_base(base_from);
	len_to = len_valid_base(base_to);
	if ((len_from == 0 || len_from == 1) || (len_to == 0 || len_to == 1))
		return (NULL);
	i_nbr = ft_atoi_base(nbr, base_from);
	return (ft_itoa_base(i_nbr, len_to, base_to));
}

int	ft_len_base_int(int nb, int len)
{
	int				i;
	unsigned int	temp;

	i = 0;
	if (nb == 0)
		return (1);
	else if (nb == -2147483648)
	{
		temp = 2147483648;
		nb = (int)(temp / len);
		i = i + 2;
	}
	else if (nb < 0)
	{
		i++;
		nb = nb * -1;
	}
	while (nb >= len)
	{
		nb = nb / len;
		i++;
	}
	i++;
	return (i);
}

char	*ft_itoa_base(int nb, int len, char *base)
{
	char	*ret;
	int		i;

	i = ft_len_base_int(nb, len);
	ret = (char *)malloc(sizeof(char) * (i + 1));
	if (ret == NULL)
		return (NULL);
	ret[0] = base[0];
	ret[i] = '\0';
	set_nb_base(nb, len, base, ret);
	return (ret);
}

void	set_nb_base(int nb, int len, char *base, char *ret)
{
	int				i;
	unsigned int	temp;

	i = ft_len_base_int(nb, len);
	i--;
	if (nb == -2147483648)
	{
		temp = 2147483648;
		ret[0] = '-';
		ret[i] = base[(temp % len)];
		nb = (int)(temp / len);
		i--;
	}
	else if (nb < 0)
	{
		nb = nb * -1;
		ret[0] = '-';
	}
	while (nb >= len)
	{
		ret[i] = base[(nb % len)];
		nb = nb / len;
		i--;
	}
	ret[i] = base[(nb % len)];
}
