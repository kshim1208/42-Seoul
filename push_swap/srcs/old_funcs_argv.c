/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   funcs_argv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshim <kshim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 14:27:58 by kshim             #+#    #+#             */
/*   Updated: 2022/06/10 15:18:45 by kshim            ###   ########.fr       */
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

int	ft_ps_parse_argv(char **argv, t_detower **st_a, t_detower *list, unsigned int *num)
{
	int		i;
	int		j;
	char	**splitted;

	i = 1;
	while (argv[i] != NULL)
	{
		splitted = ft_split(argv[i++], ' ');
		if (splitted == NULL)
			return (0);
		j = 0;
		while (splitted[j] != NULL)
		{
			if (ft_ps_set_splited_argv(splitted[j], *st_a, list, num) != 1)
				break ;
			j++;
		}
		if (splitted[j] != NULL)
		{
			ft_free_split(splitted);
			return (0);
		}
		ft_free_split(splitted);
	}
	return (1);
}

int	ft_ps_set_splited_argv(char *str, t_detower *st_a, t_detower *list, unsigned int *num)
{
	int			value;
	t_d_list	*node;

	if (ft_atoi_push_swap(str, &value) != 1)
		return (0);
	node = st_a -> head;
	while (node != NULL)
	{
		if (((t_value *)node -> content) -> value == value)
			return (0);
		node = node -> next;
	}
	if (ft_ps_deque_init_value(&node, value) != 1)
		return (0);
	ft_deque_add_back(st_a, node);
	if (ft_ps_indexing(list, ((t_value *)(node -> content)), *num) != 1)
		return (0);
	(*num)++;
	return (1);
}

int	ft_ps_deque_init_value(t_d_list **new_list, int value)
{
	t_value	*content;

	content = (t_value *)malloc(sizeof(t_value));
	if (content == NULL)
		return (0);
	content -> value = value;
	*new_list = ft_d_lstnew(content);
	if (*new_list == NULL)
		return (0);
	return (1);
}
