/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_px_data_structs.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshim <kshim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 10:32:54 by kshim             #+#    #+#             */
/*   Updated: 2022/07/06 17:26:20 by kshim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

t_ft_px_data	*ft_px_init_px_data(int argc, char **envp)
{
	t_ft_px_data	*px_data;

	px_data = (t_ft_px_data *)malloc(sizeof(t_ft_px_data));
	if (px_data == NULL)
		return (NULL);
	px_data -> cmd_argv = (char ***)malloc(sizeof(char **) * (argc - 2 + 1));
	if (px_data -> cmd_argv == NULL)
		return (0);
	(px_data -> cmd_argv)[argc - 2] = NULL;
	px_data -> ac = argc;	
	if (ft_px_init_paths(envp, px_data) == 0)
		return (NULL);
	if (ft_px_init_cmd_paths(px_data) == 0)
		return (NULL);
	return (px_data);
}
