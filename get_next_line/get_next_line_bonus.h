/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshim <kshim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 11:05:46 by kshim             #+#    #+#             */
/*   Updated: 2022/04/12 16:33:50 by kshim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdlib.h>

typedef struct s_gnl_lst
{
	int					saved_fd;
	char				*str_next;
	char				*buffer;
	ssize_t				check_result;
	struct s_gnl_lst	*next;
}					t_lst;

char	*get_next_line(int fd);
ssize_t	get_buffer(int fd, t_lst *lst);
ssize_t	process_buffer(t_lst *lst, char **ret);
void	free_gnl(t_lst *lst, char **ret);
void	free_lst(t_lst **head, t_lst **lst);
size_t	ft_strlen(const char *s);
char	*ft_strchr(const char *s, int c);
char	*ft_strndup(const char *s1, size_t n);
char	*join_buffer_to_ret(char *s1, char *s2);
t_lst	*gnl_select_lst(int fd, t_lst **gnl_head);

#endif
