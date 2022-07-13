/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_main_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshim <kshim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 14:46:41 by kshim             #+#    #+#             */
/*   Updated: 2022/07/13 13:38:38 by kshim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/checker_bonus.h"
#include "../libft/ft_printf.h"
#include "../include/get_next_line_bonus.h"
#include "unistd.h"

static void	ft_ps_bn_parse_operation(t_ps_struct_list *struct_list);
static void	ft_ps_free_memory(t_ps_struct_list *struct_list);
static void	exit_error(t_ps_struct_list *struct_list);

int	main(int argc, char **argv)
{
	t_ps_struct_list	*struct_list;
	unsigned int		num;
	int					sorted;

	if (argc < 2)
		return (0);
	num = 0;
	sorted = 0;
	struct_list = ft_ps_set_struct_list(
			ft_dequetower(), ft_dequetower(), ft_dequetower());
	if (struct_list == NULL || struct_list -> st_a == NULL
		|| struct_list -> st_b == NULL || struct_list -> list == NULL
		|| !(ft_ps_check_argv(argv, struct_list, &num)))
		exit_error(struct_list);
	ft_free_detower(&(struct_list -> list));
	ft_ps_bn_parse_operation(struct_list);
	sorted = ft_ps_is_sorted(struct_list -> st_a, 0, num, 0);
	ft_ps_free_memory(struct_list);
	if (sorted == 1)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	return (0);
}

void	ft_ps_bn_parse_operation(t_ps_struct_list *struct_list)
{
	char	*operation;

	while (1)
	{
		operation = NULL;
		operation = get_next_line(0);
		if (operation == NULL)
			break ;
		if (!(ft_ps_bn_checker(struct_list, operation)))
		{
			free(operation);
			exit_error(struct_list);
		}
		free(operation);
	}
	return ;
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
