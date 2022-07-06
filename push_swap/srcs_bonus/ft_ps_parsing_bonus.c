/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ps_parsing_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshim <kshim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 14:32:16 by kshim             #+#    #+#             */
/*   Updated: 2022/07/05 13:39:58 by kshim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/checker_bonus.h"
#include "../libft/libft.h"

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
				|| (str[i - 1] == '-' && str[i] == '-')
				|| ((str[i - 1] >= '0' && str[i - 1] <= '9') && str[i] == '+')
				|| ((str[i - 1] >= '0' && str[i - 1] <= '9') && str[i] == '-'))
				return (0);
		}
		i++;
	}	
	if ((str[i - 1] == '+' && str[i] == '\0' )
		|| (str[i - 1] == '-' && str[i] == '\0'))
		return (0);
	return (1);
}

int	ft_ps_parse_argv(char **argv, t_detower **st_a,
t_detower *list, unsigned int *num)
{
	int			i;
	int			j;
	char		**splitted;

	i = 1;
	while (argv[i] != NULL)
	{
		splitted = ft_split(argv[i++], ' ');
		if (splitted == NULL)
			return (0);
		j = 0;
		while (splitted[j] != NULL)
		{
			if (!(ft_ps_set_splited_argv(splitted[j++], *st_a, list, num)))
			{
				ft_free_split(splitted);
				ft_ps_free_index_list(&list);
				return (0);
			}
		}
		ft_free_split(splitted);
	}
	ft_ps_set_val_to_index(list);
	ft_ps_free_index_list(&list);
	return (1);
}

int	ft_ps_set_splited_argv(char *str, t_detower *st_a,
		t_detower *index, unsigned int *num)
{
	int			value;
	t_d_list	*node;

	if (!(ft_atoi_push_swap(str, &value))
		|| !(ft_ps_deque_init_value(&node, value)))
		return (0);
	ft_deque_add_back(st_a, node);
	if (!(ft_ps_indexing(index, ((t_value *)(node -> content)), *num)))
		return (0);
	(*num)++;
	return (1);
}

void	ft_ps_set_val_to_index(t_detower *index)
{
	t_d_list		*lst;
	unsigned int	i;

	lst = index -> head;
	i = 0;
	while (lst != NULL)
	{
		((t_value *)(lst -> content))-> index = i;
		lst = lst -> next;
		i++;
	}
	return ;
}
