/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshim <kshim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 11:20:30 by kshim             #+#    #+#             */
/*   Updated: 2022/05/01 12:54:19 by kshim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft/libft.h"
# include <stdint.h>
# include <stdlib.h>
# include <stdarg.h>

typedef struct s_printf_content{
	int							format;
	struct s_printf_formats		*format_detail;
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
	int			neg_value;
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

int				ft_printf(const char *arg, ...);
t_list			*make_new_content(t_list **lst_head,
					int is_format, va_list *ap);
t_fp_content	*set_new_content(int is_format, va_list *ap);
t_fp_formats	*set_format_detail(t_fp_content *new_content, va_list *ap);
void			fp_del_content(t_fp_content **content);
int				check_flags(char **arg, t_fp_content *new_content);
int				is_flags(char *arg, t_fp_formats *formats, int *check);
int				is_width(char *arg,
					t_fp_formats *formats, int *check);
int				is_precision(char *arg,
					t_fp_formats *formats, int *check);
int				is_flags_error(t_fp_content *content);
int				process_output(t_fp_content *work_content, int *how_many);
int				make_fs_output(t_fp_content *content,
					t_fp_str *data, int *how_many);
int				fs_process_char_ap(t_fp_formats *formats, t_fp_str *data);
int				fs_process_int_ap(t_fp_formats *formats, t_fp_str *data);
int				fs_process_uint_ap(t_fp_formats *formats, t_fp_str *data);
void			set_output(t_fp_formats *formats, t_fp_str *data);
void			set_sign(t_fp_formats *formats, size_t *i);
void			set_alternate(t_fp_formats *formats);
void			set_width_pad(t_fp_formats *formats, t_fp_str *data);
void			set_char(t_fp_formats *formats, t_fp_str *data,
					size_t *i);
int				len_of_output(t_fp_formats *formats, t_fp_str *data);
void			fs_chars_len(t_fp_formats *formats, t_fp_str *data);
void			fs_int_len(t_fp_formats *formats, t_fp_str *data);
void			fs_sign_len(t_fp_formats *formats, t_fp_str *data);
void			fs_alter_len(t_fp_formats *formats, t_fp_str *data);
void			ft_fp_put_str(char *str, size_t len);
int				check_fs(char *arg);
char			*ft_set_c(t_fp_formats *formats);
void			ft_fp_free_data(t_fp_str **data);
void			ft_fp_free_formats(t_fp_formats **formats);

#endif
