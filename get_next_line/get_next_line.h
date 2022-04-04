/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshim <kshim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 12:32:27 by kshim             #+#    #+#             */
/*   Updated: 2022/04/04 10:42:32 by kshim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <sys/types.h>
# include <stdlib.h>

# ifndef OPEN_MAX
#  define OPEN_MAX = 10240
# endif

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE = 4
# endif

char	*get_next_line(int fd);
char	*get_line(int fd, char **str_next);
size_t	ft_strlen(const char *s);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strdup(const char *s1);
char	*ft_strndup(const char *s1, size_t n);

#endif
