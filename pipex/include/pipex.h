/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshim <student.42seoul.kr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 16:32:16 by kshim             #+#    #+#             */
/*   Updated: 2022/07/07 16:56:27 by kshim            ###   ########.fr       */
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
	int		pipe_fd[2];
	int		i_file_fd;
	int		o_file_fd;
}				t_ft_px_data;

t_ft_px_data	*ft_px_init_px_data(int argc, char **envp);

int				ft_px_init_paths(char **envp, t_ft_px_data *px_data);
int				ft_px_init_cmd_paths(t_ft_px_data *px_data);

int				ft_px_check_files(char **argv, t_ft_px_data *px_data);
int				ft_px_input_file(char *i_file, t_ft_px_data *px_data);
int				ft_px_output_file(char *o_file, t_ft_px_data *px_data);
int				ft_px_parse_commands(char **argv, t_ft_px_data *px_data);
int				ft_px_check_command(char *cmd_wth_optn, t_ft_px_data *px_data);

#endif
