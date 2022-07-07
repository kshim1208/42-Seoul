/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshim <kshim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 18:12:50 by kshim             #+#    #+#             */
/*   Updated: 2022/07/06 17:25:48 by kshim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

#include "../libft/ft_printf.h"

/*

static int	pipex(t_ft_px_data	*px_data);

*/

int	main(int argc, char **argv, char **envp)
{
	t_ft_px_data	*px_data;

	px_data = ft_px_init_px_data(argc, envp);
	if (px_data == NULL)
		return (0);

	ft_px_parse_commands(argv, px_data);

	/*
	pipex(px_data);
*/

	int i;
	int j;

	i = 0;
	while ((px_data -> cmd_argv)[i] != NULL)
	{
		j = 0;
		while (px_data -> cmd_argv[i][j] != NULL)
		{
			ft_printf("%s\n", (px_data -> cmd_argv)[i][j]);
			j++;
		}
		i++;
	}
	i = 0;
	while ((px_data -> cmd_paths)[i] != NULL)
	{
		ft_printf("%s\n", (px_data -> cmd_paths)[i]);
		i++;
	}


	/*
	ft_px_check_files(argv, px_data);
*/
	/* 	
		보너스를 할 예정. 따라서 파이프가 몇 개 들어올지 알 수 없으므로 argc 체크는 일단 생략
		
		<프로그램 1[argv[0]], 프로그램 2(argv[argc])>
		주어진 프로그램 1을 읽을 수 있어야 하고, 프로그램 2에 쓰는게 가능해야 pipex를 수행할 수 있으니 반드시 access로 검사해야함.
		here_doc일 경우, 다른 방식 채택 필요 -> here_doc 공부하기
		access의 첫번째 인자가 경로이므로 주어진 프로그램의 경로가 반드시 필요함.
		
		<자식 프로세스 성성 및 대기>
		fork로 명령어 1을 수행하기 위한 (터미널과 명령어가 프로세스를 만드는 것으로 확인함. 재확인해보자.) 자식 프로세스 만들고
		부모는 wait로 대기 (자식에서는 wait 동작 안함)
		*/
	return (1);
}
/*

int	pipex(t_ft_px_data *px_data)
{
}

*/

