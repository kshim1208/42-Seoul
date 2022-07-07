/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ps_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshim <student.42seoul.kr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 14:32:16 by kshim             #+#    #+#             */
/*   Updated: 2022/07/07 17:25:10 by kshim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include "../libft/libft.h"

int	ft_ps_check_argv(int argc, char **argv,
			t_ps_struct_list *struct_list, unsigned int *num)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (ft_ps_is_valid_char(argv[i]) != 1)
			return (0);
		ft_ps_parse_argv(argv[i], struct_list, num);
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
			if (ft_isdigit(str[i]) == 0 && ft_is_sign(str[i] == 0)
				&& ft_isspace(str[i]) == 0)
				return (0);
		}
		if (i >= 1)
		{
			if ((ft_is_sign(str[i - 1]) == 1
					&& (ft_isdigit(str[i]) == 0 && ft_isspace(str[i]) == 0))
				|| (ft_isdigit(str[i - 1]) == 1 && ft_is_sign(str[i]) == 1))
				return (0);
		}
		i++;
	}	
	if ((ft_is_sign(str[i - 1]) == 1 && str[i] == '\0' ))
		return (0);
	return (1);
}

int	ft_ps_parse_argv(char *str, t_ps_struct_list *struct_list, unsigned int *num)
{
	int			i;
	int			j;
	char		**splitted;

	i = 1;
	while (str[i] != NULL)
	{
		if ()
		splitted = ft_split(str, ' ');
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
