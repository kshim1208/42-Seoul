/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshim <kshim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 14:25:43 by kshim             #+#    #+#             */
/*   Updated: 2022/01/18 15:05:16 by kshim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
int	do_cmp(unsigned char a, unsigned char b);

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;
	unsigned char	a;
	unsigned char	b;

	i = 0;
	while (s1[i] != '\0' && i < n)
	{
		a = s1[i];
		b = s2[i];
		if (do_cmp(a, b) != 0)
			return (do_cmp(a, b));
		i++;
	}
	i = 0;
	while (s2[i] != '\0' && i < n)
	{
		a = s1[i];
		b = s2[i];
		if (do_cmp(a, b) != 0)
			return (do_cmp(a, b));
		i++;
	}
	return (0);
}

int	do_cmp(unsigned char a, unsigned char b)
{
	if (a > b)
		return (1);
	else if (a < b)
		return (-1);
	return (0);
}
