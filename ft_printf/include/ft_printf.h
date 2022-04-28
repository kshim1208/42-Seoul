/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshim <kshim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 11:20:30 by kshim             #+#    #+#             */
/*   Updated: 2022/04/28 15:53:34 by kshim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft/libft.h"
# include <stdint.h>
# include <stdlib.h>
# include <stdarg.h>

# include <unistd.h>

typedef struct s_printf_content{
	int							format;
	struct s_printf_formats		*format_detail;
	char						*output;
	size_t						output_len;
}		t_fp_content;

typedef struct s_printf_formats{
	va_list		*ap;
	size_t		width;
	int			alternate;
	int			zero_fill;
	int			left_justify;
	int			plus_sign;
	int			space_sign;
	int			minus_sign;
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

int	ft_printf(const char *arg, ...);

t_list	*make_new_content(t_list **lst_head, int is_format, va_list *ap);
t_fp_content	*set_new_content(int is_format, va_list *ap);
t_fp_formats	*set_format_detail(t_fp_content *new_content, va_list *ap);
void	fp_del_content(t_fp_content *content);

void	ft_fp_free_data(t_fp_str **data);

int	check_flags(char **arg, t_fp_content *new_content);
int	is_flags(char *arg, t_fp_formats *formats, int *check);
int	is_width_precision(char *arg, t_fp_formats *foramts, int *check);
int	is_flags_error(t_fp_content *content);

int	check_fs(char *arg);

int	process_output(t_fp_content *work_cntent);
int	make_fs_output(t_fp_content *content, t_fp_str *data);
int	fs_process_char_ap(t_fp_formats *formats, t_fp_str *data);
int	fs_process_int_ap(t_fp_formats *formats, t_fp_str *data);
int	fs_process_uint_ap(t_fp_formats *formats, t_fp_str *data);

char	*set_output(t_fp_formats *formats, t_fp_str *data);
void	set_sign(t_fp_formats *formats, char **str);
void	set_alternate(t_fp_formats *formats, char **str);
void	set_width_pad(t_fp_formats *formats, t_fp_str *data, char **str);
void	set_char(t_fp_formats *formats, t_fp_str *data, char **str);

int	len_of_output(t_fp_formats *formats, t_fp_str *data);
void	fs_chars_len(t_fp_formats *formats, t_fp_str *data);
void	fs_int_len(t_fp_formats *formats, t_fp_str *data);
void	fs_sign_alter_len(t_fp_formats *formats, t_fp_str *data);

int	print_output(t_list *lst_head);	
char	*ft_set_c(t_fp_formats *formats);

#endif
