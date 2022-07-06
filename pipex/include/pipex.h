/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshim <kshim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 16:32:16 by kshim             #+#    #+#             */
/*   Updated: 2022/07/06 14:53:29 by kshim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "stddef.h"
# include "stdlib.h"

typedef struct s_pipex_data{
	char	**commands;
	int		ac;
	char	**cmd_paths;
}				t_ft_px_data;


t_ft_px_data	*ft_px_init_px_data(int argc, char **envp);

int	ft_px_data_cmd_paths(char **envp, t_ft_px_data *px_data);

#endif
