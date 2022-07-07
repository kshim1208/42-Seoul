/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_px_parse_argv.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshim <kshim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 14:35:45 by kshim             #+#    #+#             */
/*   Updated: 2022/07/06 17:30:29 by kshim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* 차후 조건으로 here_doc 감지 만들기 */
#include "../include/pipex.h"
#include "../libft/libft.h"

	/* access로 파일 존재 및 읽기 권한 필요 (실행은?) 
	 마지막 파일에는 파일 존재 및 쓰기 권한 필요 (실행이랑 읽기는?) */


int	ft_px_check_files(char **argv, t_ft_px_data *px_data)
{
	if (ft_px_input_file(argv[0], px_data) != 0
		|| ft_px_output_file(argv[px_data -> ac], px_data) != 0)
		return (0);
	return (1);
}

int	ft_px_input_file(char *i_file, t_ft_px_data *px_data)
{
	int	fd;

	fd = -1;
	if (access(i_file, F_OK | R_OK) == 0)
	{
		fd = open(i_file, O_RDONLY);
		if (fd == -1)
			return (0);
		px_data -> i_file_fd = fd;
	}
	else
	{
		/* stdin 없으면 그냥 없는거니까 함수 종료? */
	}
	return (1);
}

int	ft_px_output_file(char *o_file, t_ft_px_data *px_data)
{
	int	fd;

	fd = -1;
	if (access(o_file, F_OK | W_OK) == 0)
	{
		fd = open(o_file, O_WRONLY);
		if (fd == -1)
			return (0);
		px_data -> o_file_fd = fd;
	}
	else
	{
		/* 이건 문제 아닌가? */
	}
	return (1);
}


int	ft_px_parse_commands(char **argv, t_ft_px_data *px_data)
{
	int	argc_index;
	int	cmd_index;

	argc_index = 2;
	cmd_index = 0;
	while (argc_index < (px_data -> ac) - 1)
	{
		ft_px_check_command(argv[argc_index], px_data, cmd_index);
		argc_index++;
		cmd_index++;
	}
	return (1);
}

int	ft_px_check_command(char *cmd_wth_optn, t_ft_px_data *px_data, int cmd_index)
{
	char	*cmd_wth_path;
	int		i;

	(px_data -> cmd_argv)[cmd_index] = ft_split(cmd_wth_optn, ' ');
	if ((px_data -> cmd_argv)[cmd_index] == NULL)
		return (0);
	i = 0;
	while ((px_data -> paths)[i] != NULL)
	{
		cmd_wth_path = ft_strjoin((px_data -> paths)[i], (px_data -> cmd_argv)[cmd_index][0]);
		if (cmd_wth_path == NULL)
			return (0);
		if (access(cmd_wth_path, F_OK | X_OK) == 0)
		{
			(px_data -> cmd_paths)[cmd_index] = cmd_wth_path;
			break ;
		}
		free(cmd_wth_path);
		i++;
	}
	return (1);
}
