/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshim <kshim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 11:20:30 by kshim             #+#    #+#             */
/*   Updated: 2022/04/25 15:27:58 by kshim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include "../libft/libft.h"
# include <stdint.h>
# include <stdlib.h>
# include <stdarg.h>

typedef struct s_printf_content{
	int							format;
	struct s_printf_formats		*format_detail;
	char						*output;
}		t_fp_content;

typedef struct s_printf_formats{
	uintptr_t	ap_pos;
	size_t		width;
	int			alternate;
	int			zero_fill;
	int			left_justify;
	int			plus_sign;
	int			space_sign;
	int			precision;
	size_t		prec_val;
	char		fs;
}		t_fp_formats;

typedef struct s_printf_str_data{
	size_t		width_pad;
	size_t		prec_pad;
	size_t		ap_len;
	size_t		output_len;
	char		*processed_ap;
}		t_fp_str;

t_list	*make_new_content(t_list **lst_head, int is_format);
t_fp_content	*set_new_content(int is_format);
t_fp_formats	*set_format_detail(t_fp_content *new_content);
void	fp_del_content(t_fp_content *content);

int	check_flags(char *arg, t_fp_content *new_content);
int	is_flags(char *arg, t_fp_formats *formats, int *check);
int	is_flags_error(t_fp_formats *formats);
int	is_width(char *arg, t_fp_formats *foramts, int *check);
int	is_precision(char *arg, t_fp_formats *formats, int *check);

int	check_fs(char *arg);
uintptr_t	check_fs_type_size(va_list *ap, t_fp_content *new_content);
void	set_va_and_fs(char *arg, va_list *ap, t_fp_content *new_content);

int	process_output(t_list *lst);
int	make_fs_output(t_fp_content *content, t_fp_str *data);
void	len_of_output(t_fp_formats *formats, t_fp_str *data);
char	*put_chars(t_fp_formats *formats, t_fp_str *data);

void	len_of_ap(t_fp_formats *formats, t_fp_str *data);
void	fs_chars_len(t_fp_formats *formats, t_fp_str *data);
void	fs_int_len(t_fp_formats *formats, t_fp_str *data);
void	fs_sign_len(t_fp_formats *formats, t_fp_str *data);
int	fs_process_ap(t_fp_formats *formats, t_fp_str *data);

size_t	ft_s_int_len(int num, int base);
size_t	ft_us_int_len(unsigned int num, int base);
size_t	ft_uintptr_len(uintptr_t addr, int base);

void	ft_fp_free_data(t_fp_str **data);

int	print_output(t_list *lst_head);	

#endif
