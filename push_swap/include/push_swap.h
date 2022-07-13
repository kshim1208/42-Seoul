/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshim <kshim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 15:14:08 by kshim             #+#    #+#             */
/*   Updated: 2022/07/13 13:41:43 by kshim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>

typedef enum e_operation
{
	sa,
	sb,
	ss,
	pa,
	pb,
	ra,
	rb,
	rr,
	rra,
	rrb,
	rrr
}	t_oper;

typedef struct s_d_list
{
	void			*content;
	struct s_d_list	*prev;
	struct s_d_list	*next;
}				t_d_list;

typedef struct s_value
{
	int				value;
	unsigned int	index;
}				t_value;

typedef struct s_deque_tower
{
	t_d_list	*head;
	t_d_list	*tail;
}				t_detower;

typedef struct s_ps_struct_list
{
	t_detower	*st_a;
	t_detower	*st_b;
	t_detower	*list;
}				t_ps_struct_list;

typedef struct s_node_value_check
{
	int	pos_val;
	int	node_val;
	int	prev_val;
	int	next_val;
}				t_node_val;

typedef struct s_ps_sort_data
{
	unsigned int	pivot_a;
	unsigned int	pivot_b;
	unsigned int	pa;
	unsigned int	pb;
	unsigned int	ra;
	unsigned int	rb;
}				t_sort_data;

int					ft_ps_check_argv(char **argv,
						t_ps_struct_list *struct_list, unsigned int *num);
int					ft_ps_is_valid_char(char *str, int *single);
int					ft_ps_parse_argv(char *str, t_ps_struct_list *struct_list,
						unsigned int *num, int single);
int					ft_ps_parse_multi_str(char *str,
						t_ps_struct_list *struct_list, unsigned int *num);		
int					ft_ps_set_splited_argv(char *str, t_detower *st_a,
						t_detower *index, unsigned int *num);

int					ft_ps_indexing(
						t_detower *index, t_value *content, unsigned int num);
int					ft_ps_indexing_rec(t_detower *index, t_d_list **pos,
						t_d_list *node, unsigned int point);
int					ft_ps_indexing_node_val(t_d_list *pos,
						t_d_list *node, t_node_val **check);
void				ft_ps_indexing_relocate(t_d_list **pos, unsigned int point,
						t_node_val *check, int flag);
void				ft_ps_indexing_free_check(t_node_val *check);

void				ft_ps_indexing_side(t_detower *index, t_d_list *pos,
						t_d_list *node, t_node_val *check);
void				ft_ps_indexing_single_node(t_detower *index, t_d_list *pos,
						t_d_list *node, t_node_val *check);
int					ft_ps_indexing_point(t_d_list *pos, t_node_val *check,
						t_d_list *node, unsigned int point);
int					ft_ps_indexing_normal(t_detower *index, t_d_list *pos,
						t_d_list *node, t_node_val *check);
void				ft_ps_set_val_to_index(t_detower *list);

t_detower			*ft_dequetower(void);
t_d_list			*ft_d_lstnew(void *content);
void				ft_free_detower(t_detower **detower);
void				ft_ps_content_del(void	*content);
void				ft_d_lstclear(t_d_list **lst, void (*del)(void *));

void				ft_deque_add_back(t_detower *detower, t_d_list *new_elem);
void				ft_deque_add_front(t_detower *detower, t_d_list *new_elem);
void				ft_deque_del_back(t_detower *detower, int free_node);
void				ft_deque_del_front(t_detower *detower, int free_node);
void				ft_d_lstdelone(t_d_list *lst, void (*del)(void *));

void				ft_deque_add_prev_node(t_detower *detower, t_d_list *pos,
						t_d_list *new_elem);
void				ft_deque_add_next_node(t_detower *detower, t_d_list *pos,
						t_d_list *new_elem);

int					ft_ps_move_a_to_b(t_ps_struct_list *struct_list,
						unsigned int biggest, unsigned int num, int flag);
int					ft_ps_move_b_to_a(t_ps_struct_list *struct_list,
						unsigned int biggest, unsigned int num, int flag);
int					ft_ps_rec_sort_under_5(t_ps_struct_list *struct_list,
						unsigned int biggest, unsigned int num, int direction);
int					ft_ps_rec_sort_move_a_to_b(t_ps_struct_list *struct_list,
						unsigned int biggest, unsigned int num);
int					ft_ps_rec_sort_move_b_to_a(t_ps_struct_list *struct_list,
						unsigned int biggest, unsigned int num);

int					ft_ps_sort_a_to_b(t_ps_struct_list *struct_list,
						t_sort_data *sort_data, unsigned int num);
int					ft_ps_sort_b_to_a(t_ps_struct_list *struct_list,
						t_sort_data *sort_data, unsigned int num);
int					ft_ps_sort_a_to_b_below_piv_a(t_ps_struct_list *struct_list,
						t_sort_data *sort_data);
int					ft_ps_sort_a_to_b_more_than_piv_b(
						t_ps_struct_list *struct_list, t_sort_data *sort_data);

int					ft_ps_sort_a_to_b_reverse_rotate(
						t_ps_struct_list *struct_list, t_sort_data *sort_data);
int					ft_ps_bef_sort_rev_rotate(t_ps_struct_list *struct_list,
						unsigned int num, int flag);
int					ft_ps_sort_do_reverse_rotate(t_ps_struct_list *struct_list,
						unsigned int rrr, unsigned int r_left, int flag);

int					ft_ps_sort_del_b_add_f(
						t_ps_struct_list *struct_list, int flag);
int					ft_ps_sort_del_f_add_f(
						t_ps_struct_list *struct_list, int flag);
int					ft_ps_sort_del_f_add_b(
						t_ps_struct_list *struct_list, int flag);
int					ft_ps_sort_swap(
						t_ps_struct_list *struct_list, int flag);

int					ft_ps_sort_list_node_add(
						t_ps_struct_list *struct_list, int oper_code);
int					ft_ps_sort_list_node_rotate_check(
						t_ps_struct_list *struct_list, int *oper_code);
int					ft_ps_sort_list_node_rev_rotate_check(
						t_ps_struct_list *struct_list, int *oper_code);

int					ft_ps_sort_2(t_ps_struct_list *struct_list, int flag);
int					ft_ps_sort_3(t_ps_struct_list *struct_list,
						unsigned int biggest, int flag);
int					ft_ps_sort_3_set_a_to_b(t_ps_struct_list *struct_list,
						unsigned int biggest);
int					ft_ps_sort_3_set_b_to_a(t_ps_struct_list *struct_list,
						unsigned int biggest);

int					ft_ps_sort_4(t_ps_struct_list *struct_list,
						unsigned int biggest, int flag);
int					ft_ps_sort_4_stack_a(t_ps_struct_list *struct_list,
						unsigned int biggest);
int					ft_ps_sort_4_stack_b(t_ps_struct_list *struct_list,
						unsigned int biggest);
int					ft_ps_sort_4_is_biggest_top(t_ps_struct_list *struct_list,
						unsigned int biggest, int flag);
int					ft_ps_sort_4_call_sort_3(t_ps_struct_list *struct_list,
						unsigned int biggest, int flag);

int					ft_ps_sort_5(t_ps_struct_list *struct_list,
						unsigned int biggest, int flag);
int					ft_ps_sort_5_stack_a(t_ps_struct_list *struct_list,
						unsigned int biggest);
int					ft_ps_sort_5_stack_b(t_ps_struct_list *struct_list,
						unsigned int biggest);

t_ps_struct_list	*ft_ps_set_struct_list(t_detower *stack_a,
						t_detower *stack_b, t_detower *oper_list);
t_sort_data			*ft_ps_sorting_data_init(unsigned int pivot_big,
						unsigned int pivot_small);
t_d_list			*ft_ps_sort_list_node_init(int flag);
void				ft_ps_free_sort_data(t_sort_data **sort_data);

int					ft_ps_sort_only_under_5(t_ps_struct_list *struct_list,
						unsigned int num);
int					ft_ps_sort_only_5(t_ps_struct_list *struct_list,
						unsigned int num);
int					ft_ps_sort_only_5_distribute_nodes(
						t_ps_struct_list *struct_list, unsigned int num);

int					ft_ps_sort_only_3(t_ps_struct_list *struct_list,
						unsigned int num);
int					ft_ps_sort_only_3_other_cases(t_ps_struct_list *struct_list,
						unsigned int biggest);

int					ft_ps_sort_only_4(t_ps_struct_list *struct_list,
						unsigned int num);
int					ft_ps_sort_only_4_node_move(t_ps_struct_list *struct_list);

int					ft_atoi_push_swap(const char *str, int *value);
int					ft_is_sign(int c);
int					ft_ps_deque_init_value(t_d_list **new_list, int num);
void				ft_free_split(char **splited);
void				ft_ps_free_index_list(t_detower **index);

int					ft_isspace(int c);
int					ft_ps_is_sorted(t_detower *stack, unsigned int start,
						unsigned int num, int descend);
unsigned int		ft_ps_value_of_stack_node(t_detower *stack,
						unsigned int node);
void				ft_ps_print_oper_list(t_detower *list);
void				ft_ps_print_oper_table_set(char *[]);
int					ft_ps_print_operation(unsigned int oper_code,
						char *arr[]);

#endif
