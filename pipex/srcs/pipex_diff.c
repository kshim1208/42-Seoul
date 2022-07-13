/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_diff.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshim <kshim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 18:12:50 by kshim             #+#    #+#             */
/*   Updated: 2022/07/13 10:55:05 by kshim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

#include "../libft/ft_printf.h"

/* error code는 어쩔까? */
int	main(int argc, char **argv, char **envp)
{
	t_ft_px_data	*px_data;
	int				cmd_n;
	int				cmd_last;
	int				fd[2];
	int				pid;

	if (argc < 5)
		return (1);
	cmd_n = 1;
	cmd_last = argc - 3;
	px_data = ft_px_init_px_data(argc, envp);
	if (px_data == NULL)
	{
		return (1);
	}
	while (cmd_n <= cmd_last)
	{
		pipe(fd);
		pid = fork();
		if (pid < 0)
		{
			/* error-free func */
			return (1);
		}
		else if (pid > 0)
		{
			close(fd[1]);
		}
		else
		{
			/* 자식 */
			if (cmd_n == cmd_last)
			{
				dup2(fd[1], 0);
				close(fd[1]);
				if (!ft_px_output_file(argv[argc - 1]))
				{
					return (1);
				}
			}
			else if (cmd_n == 1)
			{
				close(fd[1]);
				if (!ft_px_input_file(argv[1]))
				{
					return (1);
				}
				dup2(fd[0], 1);
				close(fd[0]);
			}
			else
			{
				dup2(fd[1], 0);
				close(fd[1]);
				dup2(fd[0], 1);
				close(fd[0]);
			}
			if (!(ft_px_check_command(argv[cmd_n + 1], px_data)))
			{
				/* error */
				return (1);
			}
			if (execve(px_data -> cmd_paths, px_data -> cmd_argv, envp) < 0)
			{
				/* 오류 리턴 상황 확인 */
				/* execve 실패 시 -1 반환하고 errno 설정함 */
			}
		}
		if (px_data -> cmd_paths != NULL)
		{
			/* 해제용 함수 분리도 가능 */
			free(px_data -> cmd_paths);
			/* px_data -> cmd_argv 이중포인터 해제 */
			px_data -> cmd_paths = NULL;
		}
		close(fd[0]);
		cmd_n++;
		/* 어차피 자식은 execve하느라 끝날 것 같긴한데. */
	}
	/* 종료 전에 fd 닫기 */
	/* free 구조체 */
	return (0);
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
		*/