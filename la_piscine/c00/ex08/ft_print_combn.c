/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshim <kshim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 18:57:28 by kshim             #+#    #+#             */
/*   Updated: 2022/01/14 16:09:35 by kshim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
void	ft_print_combn(int n);
void	check_digit(int digit[], int n, int a);
void	put_digit(int digit[], int n, int a);
void	sort_digit(int digit[], int n);

void	ft_print_combn(int n)
{
	int	i;
	int	digit[9];

	if (n < 1 || n > 9)
		return ;
	i = 0;
	digit[0] = 0;
	while (i < n - 1)
	{
		digit[i + 1] = digit[i] + 1;
		i++;
	}
	put_digit(digit, n, 0);
	check_digit(digit, n, 0);
}

void	check_digit(int digit[], int n, int a)
{
	if (a == 0 && (digit[n - 1] != 9))
	{
		digit[n - 1] = digit[n - 1] + 1;
		put_digit(digit, n, 1);
		check_digit(digit, n, 0);
	}
	else if (a == 0 && digit[n - 1] == 9)
	{
		if (n == 1)
			return ;
		sort_digit(digit, n);
		put_digit(digit, n, 1);
		check_digit(digit, n, 1);
	}
	else if (a == 1 && digit[0] == 10 - n)
		return ;
	else if (a == 1 && digit[0] != 10 - n)
		check_digit(digit, n, 0);
}

void	put_digit(int digit[], int n, int a)
{
	int	i;

	i = 0;
	if (a == 0)
	{
		while (i < n)
		{
			digit[i] = digit[i] + 48;
			write(1, &digit[i], 1);
			digit[i] = digit[i] - 48;
			i++;
		}
	}
	else if (a == 1)
	{
		write(1, ", ", 2);
		while (i < n)
		{
			digit[i] = digit[i] + 48;
			write(1, &digit[i], 1);
			digit[i] = digit[i] - 48;
			i++;
		}
	}
}

void	sort_digit(int digit[], int n)
{
	int	i;
	int	last;

	i = 1;
	last = 9;
	while (digit[n - i] == last)
	{
		last--;
		i++;
	}
	digit[n - i]++;
	while (last != 9)
	{
		digit[n - i + 1] = digit[n - i] + 1;
		i--;
		last++;
	}
}
