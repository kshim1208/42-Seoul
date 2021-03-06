/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshim <kshim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 11:05:46 by kshim             #+#    #+#             */
/*   Updated: 2022/04/14 09:03:06 by kshim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 512
# endif

typedef struct s_gnl_lst
{
	int					saved_fd;
	char				*str_next;
	char				*buffer;
	ssize_t				check_result;
	struct s_gnl_lst	*next;
}					t_lst;

char	*get_next_line(int fd);
size_t	ft_strlen(const char *s);
char	*ft_strchr(const char *s, int c);
char	*ft_strndup(const char *s1, size_t n);
void	ft_free_elements_gnl(t_lst *lst, char **ret);
void	ft_free_lst_gnl(t_lst **gnl_head, t_lst **lst);

#endif
