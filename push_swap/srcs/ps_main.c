/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshim <kshim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 14:19:28 by kshim             #+#    #+#             */
/*   Updated: 2022/06/07 15:31:14 by kshim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "../libft/ft_printf.h"

void	test_print_values(t_detower *st_a);

int	main(int argc, char **argv)
{
	t_detower	*st_a;
	/*t_deque	*answer 명령어들 출력 전에 리스트에 저장하고, rr, rrr, ss 최적화 가능할 경우 수행*/
	if (argc < 2)
		return (0); /* exit 함수로 stderr에 출력하도록 해야하나? exit 함수 기능 및 stderr에 출력하는 법 파악 */
	if (ft_ps_check_argv(argc, argv) != 1)
		return (0);
	st_a = ft_dequetower();
	if (st_a == NULL)
		return (0);
	if (ft_ps_parse_argv(argc, argv, &st_a) != 1)
		return (0);
	test_print_values(st_a);
	return (1);
}

void	test_print_values(t_detower *st_a)
{
	t_list	*tmp;

	tmp = st_a -> head;
	while (tmp != NULL)
	{
		ft_printf("%d\n", *((int *)(tmp -> content)));
		tmp = tmp -> next;
	}
	ft_free_detower(st_a);
	return ;
}
