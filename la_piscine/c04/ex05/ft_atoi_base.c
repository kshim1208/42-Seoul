/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshim <kshim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 20:02:21 by kshim             #+#    #+#             */
/*   Updated: 2022/01/24 10:46:43 by kshim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
int	char_to_int(char *base, char c);
int	len_valid_base(char *base);

int	ft_atoi_base(char *str, char *base)
{
	int	i;
	int	ret;
	int	sign;
	int	len;

	i = 0;
	sign = 1;
	ret = 0;
	len = len_valid_base(base);
	if (len == 0 || len == 1)
		return (0);
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = sign * -1;
		i++;
	}
	while (char_to_int(base, str[i]) != -1)
	{
		ret = ret * len + char_to_int(base, str[i]);
		i++;
	}
	return (ret * sign);
}

int	char_to_int(char *base, char c)
{
	int	i;

	i = 0;
	while (base[i] != '\0')
	{
		if (base[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int	len_valid_base(char *base)
{
	int	i;
	int	j;

	i = 0;
	while (base[i] != '\0')
	{
		if ((base[i] >= 9 && base[i] <= 13) || base[i] == 32
			|| base[i] == '+' || base[i] == '-')
			return (0);
		j = 1;
		while (base[i + j] != '\0')
		{
			if (base[i] == base [i + j])
				return (0);
			j++;
		}	
		i++;
	}
	return (i);
}
