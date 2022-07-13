/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_px_data_structs.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshim <kshim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 10:32:54 by kshim             #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2022/07/13 13:17:18 by kshim            ###   ########.fr       */
=======
/*   Updated: 2022/07/11 14:49:47 by kshim            ###   ########.fr       */
>>>>>>> 9ad55cae3be0a4e95bc561b8ca9f8a7477045b55
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

t_ft_px_data	*ft_px_init_px_data(int argc, char **envp)
{
	t_ft_px_data	*px_data;

	px_data = (t_ft_px_data *)malloc(sizeof(t_ft_px_data));
	if (px_data == NULL)
		return (NULL);
	px_data -> ac = argc;
	px_data -> cmd_paths = NULL;
	px_data -> cmd_argv = NULL;
	if (ft_px_init_paths(envp, px_data) == 0)
		return (NULL);
<<<<<<< HEAD
=======
	if (ft_px_init_cmd_paths(px_data) == 0)
		return (NULL);
>>>>>>> 9ad55cae3be0a4e95bc561b8ca9f8a7477045b55
	return (px_data);
}
