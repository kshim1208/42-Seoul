/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshim <kshim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 15:14:08 by kshim             #+#    #+#             */
/*   Updated: 2022/06/07 13:33:00 by kshim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <stdlib.h>

typedef struct	s_deque_tower{
	t_list	*head;
	t_list	*tail;
}	t_detower;

int	ft_ps_check_argv(int argc, char **argv);
int	ft_ps_is_valid_char(char *str);
int	ft_ps_parse_argv(int argc, char **argv, t_detower **st_a);
int	ft_ps_set_splited_argv(char *str, t_detower *st_a);

t_detower	*ft_dequetower(void);
int	ft_deque_add_back(t_detower *detower, int num);
int ft_deque_add_front(t_detower *detower, int num);
void	ft_free_detower(t_detower *detower);
void	ft_ps_content_del(void	*content);

int	ft_atoi_push_swap(const char *str, int *num);
void	ft_free_split(char **splited);

#endif
