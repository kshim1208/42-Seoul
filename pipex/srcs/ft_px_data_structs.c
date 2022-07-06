/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_px_data_structs.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshim <kshim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 10:32:54 by kshim             #+#    #+#             */
/*   Updated: 2022/07/06 14:29:03 by kshim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

t_ft_px_data	*ft_px_init_px_data(int argc, char **envp)
{
	t_ft_px_data	*px_data;

	px_data = (t_ft_px_data *)malloc(sizeof(t_ft_px_data));
	if (px_data == NULL)
		return (NULL);
	px_data -> commands = NULL;
	px_data -> ac = argc;	
	if (ft_px_data_cmd_paths(envp, px_data) == 0)
		return (NULL);
	return (px_data);
}
