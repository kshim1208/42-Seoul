/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_px_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshim <kshim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 12:46:21 by kshim             #+#    #+#             */
/*   Updated: 2022/07/13 13:37:50 by kshim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"
#include "../libft/libft.h"


/* path에 / 붙여줌 -> 나중에 cmd만 붙이면 탐색 가능 */
int	ft_px_init_paths(char **envp, t_ft_px_data *px_data)
{
	char	*path_pos;
	char	*tmp;
	int		i;

	i = 0;
	while (1)
	{
		if (envp[i] != NULL && ft_strncmp(envp[i], "PATH=", 5) == 0)
			break ;
		i++;
	}
	if (envp[i] == NULL)
		return (0);
	path_pos = envp[i] + 5;
	px_data -> paths = ft_split(path_pos, ':');
	if (px_data -> paths == NULL)
		return (0);
	i = 0;
	while ((px_data -> paths)[i] != NULL)
	{
		tmp = ft_strjoin((px_data -> paths)[i], "/");
		free((px_data -> paths)[i]);
		(px_data -> paths)[i++] = tmp;
	}
	return (1);
}
