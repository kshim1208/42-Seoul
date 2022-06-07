/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   funcs_argv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshim <kshim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 14:27:58 by kshim             #+#    #+#             */
/*   Updated: 2022/06/07 15:35:35 by kshim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_ps_check_argv(int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (ft_ps_is_valid_char(argv[i]) != 1)
			return (0);
		i++;
	}
	return (1);
}

int	ft_ps_is_valid_char(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (i >= 0)
		{
			if ((str[i] < '0' || str[i] > '9') && str[i] != '+' && str[i] != '-'
				&& str[i] != ' ')
				return (0);
		}
		if (i >= 1)
		{
			if ((str[i - 1] == '+' && str[i] == '+' )
				|| (str[i - 1] == '-' && str[i] == '-'))
				return (0);
			if (((str[i - 1] >= '0' && str[i - 1] <= '9') && str[i] == '+')
				|| ((str[i - 1] >= '0' && str[i - 1] <= '9') && str[i] == '-'))
				return (0);
		}
		i++;
	}
	return (1);
}

int	ft_ps_parse_argv(int argc, char **argv, t_detower **st_a)
{
	int		i;
	int		j;
	char	**splited;

	i = 1;
	while (argv[i] != NULL)
	{
		splited = ft_split(argv[i++], ' ');
		if (splited == NULL)
			return (0);
		j = 0;
		while (splited[j] != NULL)
		{
			if (ft_ps_set_splited_argv(splited[j++], *st_a) != 1)
				break ;
		}
		free(splited);
	}
	if (i != argc)
	{
		ft_free_split(splited);
		ft_free_detower(*st_a);
		return (0);
	}
	return (1);
}

int	ft_ps_set_splited_argv(char *str, t_detower *st_a)
{
	int		num;
	t_list	*lst;

	if (ft_atoi_push_swap(str, &num) != 1)
		return (0);
	lst = st_a -> head;
	while (lst != NULL)
	{
		if (*(int *)(lst -> content) == num)
		{
			ft_free_detower(st_a);
			return (0);
		}
		lst = lst -> next;
	}
	if (ft_deque_add_back(st_a, num) != 1)
	{
		ft_free_detower(st_a);
		return (0);
	}
	return (1);
}
