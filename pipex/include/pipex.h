/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshim <kshim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 16:32:16 by kshim             #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2022/07/12 16:44:13 by kshim            ###   ########.fr       */
=======
/*   Updated: 2022/07/11 16:32:16 by kshim            ###   ########.fr       */
>>>>>>> 9ad55cae3be0a4e95bc561b8ca9f8a7477045b55
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "stddef.h"
# include "stdlib.h"
# include "fcntl.h"
# include "unistd.h"

typedef struct s_pipex_data{
	int		ac;
	char	**paths;
	char	*cmd_paths;
	char	**cmd_argv;
}				t_ft_px_data;

t_ft_px_data	*ft_px_init_px_data(int argc, char **envp);

int				ft_px_init_paths(char **envp, t_ft_px_data *px_data);
int				ft_px_init_cmd_paths(t_ft_px_data *px_data);

<<<<<<< HEAD
=======
int				ft_px_check_files(char **argv, t_ft_px_data *px_data);
>>>>>>> 9ad55cae3be0a4e95bc561b8ca9f8a7477045b55
int				ft_px_input_file(char *i_file);
int				ft_px_output_file(char *o_file);
int				ft_px_check_command(char *cmd_wth_optn, t_ft_px_data *px_data);

#endif
