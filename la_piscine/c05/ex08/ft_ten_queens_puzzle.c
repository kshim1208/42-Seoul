/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshim <kshim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 19:19:05 by kshim             #+#    #+#             */
/*   Updated: 2022/01/23 20:55:39 by kshim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
int		ft_ten_queens_rec(int *ans, int check, int how_many);
int		ft_is_valid_pos(int *ans, int check, int x);
void	print_ans(int *ans);

int	ft_ten_queens_puzzle(void)
{
	int	ans[10];
	int	check;
	int	how_many;

	how_many = 0;
	check = 10;
	while (check != 0)
	{
		ans[check - 1] = 0;
		check--;
	}
	how_many = ft_ten_queens_rec(ans, check, how_many);
	return (how_many);
}

int	ft_ten_queens_rec(int *ans, int check, int how_many)
{
	int	i;

	if (check == 10)
	{
		print_ans(ans);
		return (how_many + 1);
	}
	else
	{
		i = 0;
		while (i < 10)
		{
			if (ft_is_valid_pos(ans, check, i))
			{
				ans[check] = i;
				how_many = ft_ten_queens_rec(ans, check + 1, how_many);
			}
			i++;
		}
	}
	return (how_many);
}

int	ft_is_valid_pos(int	*ans, int check, int x)
{
	int	i;

	i = check;
	if (check == 0)
		return (1);
	while (i > 0)
	{
		if (ans[i - 1] == x)
			return (0);
		i--;
	}
	while (i < check)
	{
		if ((ans[i] == x - (check - i)) || (ans[i] == x + (check - i)))
			return (0);
		i++;
	}
	return (1);
}

void	print_ans(int *ans)
{
	int		i;
	char	print;

	i = 0;
	while (i < 10)
	{
		print = ans[i] + '0';
		write(1, &print, 1);
		i++;
	}
	write(1, "\n", 1);
}
