/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshim <kshim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 14:19:28 by kshim             #+#    #+#             */
/*   Updated: 2022/06/14 12:53:09 by kshim            ###   ########.fr       */
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
	/* argc 분리 필요 */
	if (st_a == NULL || st_b == NULL || list == NULL 
		|| argc < 2 || !(ft_ps_check_argv(argc, argv)) 
		|| !(ft_ps_parse_argv(argv, &st_a, list, &num)))
		exit_error(st_a, st_b, list);
/*	
 *	if (sorted == 1)
 *		exit_error_without_text;
 *
 *	if (push_swap(st_a, st_b, list, num) != 1)
		exit_error(st_a, st_b, list);
		*/
	test_print_values(st_a);
	ft_printf("total : %d args\n", num);
	ft_ps_free_memory(st_a, st_b, list);
	return (1);
}

/*

int	push_swap(t_detower *st_a, t_detower *st_b, t_detower *list, unsigned int num)
{
	t_ps_struct_list	*struct_list;

	struct_list = ft_ps_set_struct_list(st_a, st_b, list);
	if (struct_list == NULL)
		return (0);
	move_a_to_b(struct_list, num, num);
	return (1);
}

*/

void	move_a_to_b(t_ps_struct_list * struct_list, unsigned int biggest, unsigned int num)
{
	unsigned int	pivot_a;
	unsigned int	pivot_b;
	/* 중간 연산 담는 구조체? 필요한가? pb, ra, rb등 */

	/*구조체 생성 */
	if (num <= 5)
		/* sorting func */
	else
	{
		pivot_a = (biggest - (num * 0.34));
		pivot_b = (biggest - (num * 0.66));
		move_a_to_b(struct_list, /* ra 개수만큼 st_a 아래에서 검색하여 최대값 구함 */, ra);	
		move
		move	
	}
	/* 구조체 해제 */

}

t_ps_struct_list	*ft_ps_set_struct_list(t_detower *stack_a,
		t_detower *stack_b, t_detower *oper_list)
{
	t_ps_struct_list	*new_list;

	new_list = (t_ps_struct_list *)malloc(sizeof(t_ps_struct_list));
	if (new_list == NULL)
		return (NULL);
	new_list -> st_a = stack_a;
	new_list -> st_b = stack_b;
	new_list -> list = oper_list;
	return (new_list);
}

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
