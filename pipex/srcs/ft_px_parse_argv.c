/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_px_parse_argv.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshim <kshim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 14:35:45 by kshim             #+#    #+#             */
/*   Updated: 2022/07/06 14:19:27 by kshim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* 차후 조건으로 here_doc 감지 만들기 */
#include "../include/pipex.h"

int	ft_px_check_files(char **argv, t_ft_px_data *px_data)
{
	/* access로 파일 존재 및 읽기 권한 필요 (실행은?) */
	/* 마지막 파일에는 파일 존재 및 쓰기 권한 필요 (실행이랑 읽기는?) */
	ft_px_input_file(argv[0], px_data);
	ft_px_ouput_file(argv[px_data -> ac], px_data);
	return (1);
}

int	ft_px_input_file()
{
}

int	ft_px_output_file()
{
}

int	ft_px_parse_commands(char **argv, t_ft_px_data *px_data)
{
	int	argc_index;
	int	cmd_index;

	argc_index = 2;
	cmd_index = 0;
	px_data -> commands = (char **)malloc(sizeof(char *) * ((px_data -> ac) - 2));
	if (px_data -> commands == NULL)
		return (NULL);
	(px_data -> commands)[(px_data -> ac) - 2] = 0;
	/* px_data -> commands의 index를 표현하는 정수와
	 * argv의 index를 표현하는 정수 구분해야 가독성 높아질 것 같음 */
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
	char	**cmd_split;
	char	*cmd_wth_path;
	int		i;

	cmd_split = ft_split(cmd_wth_optn, " ");
	if (cmd_split == NULL)
		return (0);
	i = 0;
	while ((px_data -> cmd_paths)[i] != NULL)
	{
		cmd_wth_path = strjoin((pax_data -> cmd_paths)[i], cmd_split[0]);
		if (access())
		{

			break ;
		}
		free(cmd_wth_path);
		i++;
		/* access 가능하면 해당 경로에 /cmd_wth_optn 붙여서 commands에 저장 */
	}
	/* access 함수로 command 사용 가능한지 확인
	 * 만약 명령을 사용할 수 없는 경우, pipex가 그냥 종료되는가? 아니면 일단 실행은 하나?
	 * 그럴 경우 오류 있는 명령은 어떻게 되는가?*/
}
