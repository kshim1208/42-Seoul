/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshim <kshim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 12:32:27 by kshim             #+#    #+#             */
/*   Updated: 2022/04/12 16:34:16 by kshim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

char	*get_next_line(int fd);
ssize_t	get_buffer(int fd, char **str_next, char **buffer);
ssize_t	process_buffer(char **str_next, char **buffer, char **ret);
void	free_gnl(char **str_next, char **buffer, char **ret,
			ssize_t check_result);
size_t	ft_strlen(const char *s);
char	*ft_strchr(const char *s, int c);
char	*ft_strndup(const char *s1, size_t n);
char	*join_buffer_to_ret(char const *s1, char const *s2);

#endif
