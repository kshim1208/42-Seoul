/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshim <kshim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 14:19:28 by kshim             #+#    #+#             */
/*   Updated: 2022/06/13 15:56:58 by kshim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "../libft/ft_printf.h"
#include "unistd.h"

/*
static void	push_swap(t_detower *st_a, t_detower *st_b, t_detower *list, unsigned int num);
*/

static void	ft_ps_free_memory(t_detower *st_a, t_detower *st_b, t_detower *list);
static void	exit_error(t_detower *st_a, t_detower *st_b, t_detower *list);

int	main(int argc, char **argv)
{
	t_detower		*st_a;
	t_detower		*st_b;
	t_detower		*list;
	unsigned int	num;

	num = 0;
	st_a = ft_dequetower();
	st_b = ft_dequetower();
	list = ft_dequetower();
	if (st_a == NULL || st_b == NULL || list == NULL 
		|| argc < 2 || !(ft_ps_check_argv(argc, argv)) 
		|| !(ft_ps_parse_argv(argv, &st_a, list, &num)))
		exit_error(st_a, st_b, list);
/*
	push_swap(st_a, st_b, list, num);
		*/
	test_print_values(st_a);
	ft_printf("total : %d args\n", num);
	ft_ps_free_memory(st_a, st_b, list);
	return (1);
}

void	push_swap(t_detower *st_a, t_detower *st_b, t_detower *list, unsigned int num)
{
	
	move_a_to_b();
i

void	ft_ps_free_memory(t_detower *st_a, t_detower *st_b, t_detower *list)
{
	if (st_a != NULL)
		ft_free_detower(st_a);
	if (st_b != NULL)
		ft_free_detower(st_b);
	if (list != NULL)
		ft_free_detower(list);
	system("leaks push_swap");
	return ;
}

void	exit_error(t_detower *st_a, t_detower *st_b, t_detower *list)
{
	ft_ps_free_memory(st_a, st_b, list);
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}

void	test_print_values(t_detower *st_a)
{
	t_d_list	*tmp;

	tmp = st_a -> head;
	while (tmp != NULL)
	{
		ft_printf("%d, ", (((t_value *)(tmp -> content))-> value));
		tmp = tmp -> next;
	}
	ft_printf("\n");
	return ;
}
