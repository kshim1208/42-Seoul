/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ps_parsing_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshim <kshim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 14:32:16 by kshim             #+#    #+#             */
/*   Updated: 2022/07/08 13:51:15 by kshim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include "../libft/libft.h"

int	ft_ps_check_argv(char **argv,
			t_ps_struct_list *struct_list, unsigned int *num)
{
	int	i;
	int	single;

	i = 1;
	while (argv[i] != NULL)
	{
		single = 1;
		if (!(ft_ps_is_valid_char(argv[i], &single))
			|| !(ft_ps_parse_argv(argv[i], struct_list, num, single)))
		{
			ft_ps_free_index_list(&(struct_list -> list));
			return (0);
		}
		i++;
	}
	ft_ps_set_val_to_index(struct_list -> list);
	ft_ps_free_index_list(&(struct_list -> list));
	return (1);
}

int	ft_ps_is_valid_char(char *str, int *single)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (i >= 0)
		{
			if (ft_isdigit(str[i]) == 0 && ft_is_sign(str[i] == 0)
				&& ft_isspace(str[i]) == 0)
				return (0);
		}
		if (i >= 1)
		{
			if ((ft_is_sign(str[i - 1]) == 1 && ft_isdigit(str[i]) == 0)
				|| (ft_isdigit(str[i - 1]) == 1 && ft_is_sign(str[i]) == 1))
				return (0);
		}
		if (ft_isspace(str[i]) == 1)
			*single = 0;
		i++;
	}	
	if ((ft_is_sign(str[i - 1]) == 1 && str[i] == '\0'))
		return (0);
	return (1);
}

int	ft_ps_parse_argv(char *str, t_ps_struct_list *struct_list,
			unsigned int *num, int single)
{
	if (single == 1)
	{
		if (!(ft_ps_set_splited_argv(str, struct_list -> st_a,
					struct_list -> list, num)))
			return (0);
	}
	else
	{
		if (!(ft_ps_parse_multi_str(str, struct_list, num)))
			return (0);
	}
	return (1);
}

int	ft_ps_parse_multi_str(char *str, t_ps_struct_list *struct_list,
			unsigned int *num)
{
	int		i;
	char	**splitted;

	splitted = ft_split(str, ' ');
	if (splitted == NULL)
		return (0);
	i = 0;
	while (splitted[i] != NULL)
	{
		if (!(ft_ps_set_splited_argv(splitted[i], struct_list -> st_a,
					struct_list -> list, num)))
		{
			ft_free_split(splitted);
			return (0);
		}
		i++;
	}
	ft_free_split(splitted);
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
