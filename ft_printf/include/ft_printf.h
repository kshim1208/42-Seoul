/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshim <kshim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 11:20:30 by kshim             #+#    #+#             */
/*   Updated: 2022/05/01 14:19:19 by kshim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft/libft.h"
# include <stdint.h>
# include <stdlib.h>
# include <stdarg.h>

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
}		t_pf_formats;

typedef struct s_printf_str_data{
	size_t		width_pad;
	size_t		prec_pad;
	size_t		ap_len;
	size_t		output_len;
	char		*processed_ap;
}		t_pf_str;

int				ft_printf(const char *arg, ...);
t_pf_formats	*set_formats(va_list *ap);
t_pf_formats	*set_format_detail(t_pf_formats *formats, va_list *ap);
void			pf_del_data(t_pf_str **data);
void			pf_del_formats(t_pf_formats **formats);
int				check_flags(char **arg, t_pf_formats *formats);
int				is_flags(char *arg, t_pf_formats *formats, int *check);
int				is_width(char *arg,
					t_pf_formats *formats, int *check);
int				is_precision(char *arg,
					t_pf_formats *formats, int *check);
int				is_flags_error(t_pf_formats *formats);
int				process_output(t_pf_formats *work_formats, int *how_many);
int				make_fs_output(t_pf_formats *formats,
					t_pf_str *data, int *how_many);
int				fs_process_char_ap(t_pf_formats *formats, t_pf_str *data);
int				fs_process_int_ap(t_pf_formats *formats, t_pf_str *data);
int				fs_process_uint_ap(t_pf_formats *formats, t_pf_str *data);
void			set_output(t_pf_formats *formats, t_pf_str *data);
void			set_sign(t_pf_formats *formats, size_t *i);
void			set_alternate(t_pf_formats *formats);
void			set_width_pad(t_pf_formats *formats, t_pf_str *data);
void			set_char(t_pf_formats *formats, t_pf_str *data,
					size_t *i);
int				len_of_output(t_pf_formats *formats, t_pf_str *data);
void			fs_chars_len(t_pf_formats *formats, t_pf_str *data);
void			fs_int_len(t_pf_formats *formats, t_pf_str *data);
void			fs_sign_len(t_pf_formats *formats, t_pf_str *data);
void			fs_alter_len(t_pf_formats *formats, t_pf_str *data);
void			pf_put_str(char *str, size_t len);
int				check_fs(char *arg);
char			*ft_set_c(t_pf_formats *formats);

#endif
