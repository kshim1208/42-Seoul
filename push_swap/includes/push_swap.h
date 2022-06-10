/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshim <kshim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 15:14:08 by kshim             #+#    #+#             */
/*   Updated: 2022/06/10 15:18:35 by kshim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <stdlib.h>

typedef struct	s_d_list
{
	void			*content;
	struct s_d_list	*prev;
	struct s_d_list	*next;
}				t_d_list;

typedef union	u_value_to_sort{
	int				value;
	unsigned int	index;
}				t_value;

typedef struct	s_deque_tower{
	t_d_list	*head;
	t_d_list	*tail;
}				t_detower;

int	ft_ps_check_argv(int argc, char **argv);
int	ft_ps_is_valid_char(char *str);
int	ft_ps_parse_argv(char **argv, t_detower **st_a, t_detower *list, unsigned int *num);
int	ft_ps_set_splited_argv(char *str, t_detower *st_a, t_detower *list, unsigned int *num);
int	ft_ps_deque_init_value(t_d_list **new_list, int num);

int	ft_ps_indexing(t_detower *list, t_value *content, unsigned int num);
void	ft_ps_indexing_rec(t_detower *list, t_d_list **pos, t_d_list *node, unsigned int point);
void	ft_ps_indexing_relocate(t_d_list **pos, unsigned int point, int flag);

t_detower	*ft_dequetower(void);
t_d_list	*ft_d_lstnew(void *content);
void	ft_free_detower(t_detower *detower);
void	ft_ps_content_del(void	*content);
void	ft_d_lstclear(t_d_list **lst, void (*del)(void *));

void	ft_deque_add_back(t_detower *detower, t_d_list *new_elem);
void	ft_deque_add_front(t_detower *detower, t_d_list *new_elem);
void	ft_deque_del_back(t_detower *detower);
void	ft_deque_del_front(t_detower *detower);
void	ft_d_lstdelone(t_d_list *lst, void (*del)(void *));

void	ft_deque_add_prev_node(t_detower *detower, t_d_list *pos, t_d_list *new_elem);
void	ft_deque_add_next_node(t_detower *detower, t_d_list *pos, t_d_list *new_elem);

int	ft_atoi_push_swap(const char *str, int *value);
void	ft_free_split(char **splited);

#endif
