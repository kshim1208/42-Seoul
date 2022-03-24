/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshim <kshim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 09:25:25 by kshim             #+#    #+#             */
/*   Updated: 2022/01/19 08:16:25 by kshim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
int	is_upper(char c);
int	is_lower(char c);
int	is_numeric(char c);

char	*ft_strcapitalize(char *str)
{
	int	i;

	if (is_lower(str[0]) == 1)
		str[0] = str[0] - 32;
	i = 1;
	while (str[i] != '\0')
	{
		if ((is_upper(str[i - 1]) == 0) && (
				is_lower(str[i - 1]) == 0) && (
				is_numeric(str[i - 1]) == 0))
		{
			if (is_lower(str[i]) == 1)
				str[i] = str[i] - 32;
		}
		if ((is_lower(str[i - 1]) == 1) || (
				is_upper(str[i - 1]) == 1) || (
				is_numeric(str[i - 1]) == 1))
		{
			if (is_upper(str[i]) == 1)
				str[i] = str[i] + 32;
		}
		i++;
	}
	return (str);
}

int	is_lower(char c)
{
	if (c >= 'a' && c <= 'z')
		return (1);
	else
		return (0);
}

int	is_upper(char c)
{
	if (c >= 'A' && c <= 'Z')
		return (1);
	else
		return (0);
}

int	is_numeric(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}
