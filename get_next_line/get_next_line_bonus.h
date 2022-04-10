/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshim <kshim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 11:05:46 by kshim             #+#    #+#             */
/*   Updated: 2022/04/10 16:32:17 by kshim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <sys/types.h>
# include <stdlib.h>

# ifndef OPEN_MAX
#  define OPEN_MAX = 10240
# endif

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE = 512
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
ssize_t	get_buffer(int fd, char **str_next, char **buffer);
ssize_t	process_buffer(char **str_next, char **buffer, char **ret);
void	free_gnl(char **str_next, char **buffer, char **ret, ssize_t check_eof);
void	free_lst(t_lst **gnl_head, t_lst **work_lst);
size_t	ft_strlen(const char *s);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strndup(const char *s1, size_t n);
t_lst	*gnl_select_lst(int fd, t_lst **gnl_head);

#endif
