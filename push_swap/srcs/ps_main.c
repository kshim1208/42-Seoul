/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshim <kshim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 14:19:28 by kshim             #+#    #+#             */
/*   Updated: 2022/07/13 13:38:34 by kshim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include "../libft/ft_printf.h"
#include "unistd.h"

static int	push_swap(t_ps_struct_list *struct_list, unsigned int num);
static void	ft_ps_free_memory(t_ps_struct_list *struct_list);
static void	exit_error(t_ps_struct_list *struct_list);

int	main(int argc, char **argv)
{
	t_ps_struct_list	*struct_list;
	unsigned int		num;

	if (argc < 2)
		return (1);
	num = 0;
	struct_list = ft_ps_set_struct_list(
			ft_dequetower(), ft_dequetower(), ft_dequetower());
	if (struct_list == NULL || struct_list -> st_a == NULL
		|| struct_list -> st_b == NULL || struct_list -> list == NULL
		|| !(ft_ps_check_argv(argv, struct_list, &num)))
		exit_error(struct_list);
	if (ft_ps_is_sorted(struct_list -> st_a, 0, num, 0) == 1)
	{
		ft_ps_free_memory(struct_list);
		return (0);
	}
	if (!(push_swap(struct_list, num)))
		exit_error(struct_list);
	ft_ps_print_oper_list(struct_list -> list);
	ft_ps_free_memory(struct_list);
	return (0);
}

int	push_swap(t_ps_struct_list *struct_list, unsigned int num)
{
	if (num <= 5)
	{
		if (ft_ps_sort_only_under_5(struct_list, num) != 1)
			return (0);
	}
	else
	{
		if (ft_ps_move_a_to_b(struct_list, num -1, num, 0) != 1)
			return (0);
	}
	return (1);
}

void	ft_ps_free_memory(t_ps_struct_list *struct_list)
{
	if (struct_list -> st_a != NULL)
		ft_free_detower(&(struct_list -> st_a));
	if (struct_list -> st_b != NULL)
		ft_free_detower(&(struct_list -> st_b));
	if (struct_list -> list != NULL)
		ft_free_detower(&(struct_list -> list));
	free(struct_list);
	return ;
}

void	exit_error(t_ps_struct_list *struct_list)
{	
	ft_ps_free_memory(struct_list);
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}
