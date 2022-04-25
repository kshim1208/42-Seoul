/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_print_out.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshim <kshim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 14:42:22 by kshim             #+#    #+#             */
/*   Updated: 2022/04/25 10:04:17 by kshim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	print_output(t_lst *lst_head)
{
	char	*output_to_print;
	int		how_much;

	how_much = 0;
	while (lst_head != NULL)
	{
		output_to_print = lst_head ->(t_fp_content *)content -> output;
		write(1, output_to_print, ft_strlen(output_to_print));
		how_much = how_much + ft_strlen(output_to_print);
		lst_head = lst_head -> next;
	}
	return (how_much);
}
