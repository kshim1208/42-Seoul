/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshim <kshim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 12:32:27 by kshim             #+#    #+#             */
/*   Updated: 2022/03/25 09:13:47 by kshim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifdef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <sys/types.h>

#ifndef OPEN_MAX
# define OPEN_MAX = 10240
#endif

#ifndef BUFFER_SIZE
# define BUFFER_SIZE = 4
#endif

char	*get_next_line(int fd);

#endif
