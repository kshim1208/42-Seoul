/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshim <kshim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 18:12:50 by kshim             #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2022/07/13 12:56:17 by kshim            ###   ########.fr       */
=======
/*   Updated: 2022/07/11 17:22:29 by kshim            ###   ########.fr       */
>>>>>>> 9ad55cae3be0a4e95bc561b8ca9f8a7477045b55
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

#include "../libft/ft_printf.h"

static void	free_px_data(t_ft_px_data *px_data);
static void	free_splitted(char **strs);

/* error code는 어쩔까? */
int	main(int argc, char **argv, char **envp)
{
	t_ft_px_data	*px_data;
	int				cmd_n;
	int				cmd_last;
	int				pipe_read;
	int				pipe_write;
	int				*fd;
	int				pid;

<<<<<<< HEAD
=======
	tmp = argv;
>>>>>>> 9ad55cae3be0a4e95bc561b8ca9f8a7477045b55
	if (argc < 5)
		return (1);
	cmd_n = 1;
	cmd_last = argc - 3;
	px_data = ft_px_init_px_data(argc, envp);
	if (px_data == NULL)
	{
		return (1);
	}
<<<<<<< HEAD
	fd = (int *)malloc(sizeof(int) * ((2 * cmd_last) - 2));
	if (fd == NULL)
	{
		/* 구조체 해제 */
=======
	fd = (int *)malloc(sizeof(int) * ((2 * cmd_last) - 1));
	if (fd == NULL)
	{
>>>>>>> 9ad55cae3be0a4e95bc561b8ca9f8a7477045b55
		return (1);
	}
	while (cmd_n <= cmd_last)
	{
		pipe_read = (2 * cmd_n) - 2;
		pipe_write = (2 * cmd_n) - 1;
		if (cmd_n != cmd_last)
<<<<<<< HEAD
		{
			pipe(&(fd[pipe_read]));
		}
=======
			pipe(&(fd[pipe_read]));
>>>>>>> 9ad55cae3be0a4e95bc561b8ca9f8a7477045b55
		pid = fork();
		if (pid < 0)
		{
			/* error-free func */
			return (1);
		}
<<<<<<< HEAD
		else if (pid > 0)
		{
			/* 부모 */
			if (cmd_n != cmd_last)
			{
				close(fd[pipe_write]);
			}
			if (cmd_n != 1)
			{
				close(fd[pipe_read - 2]);
=======
		else if (pid == 0)
		{
			/* 자식 */
			if (cmd_n == cmd_last)
			{
				dup2(fd[pipe_read - 2], 0);
				close(fd[pipe_read - 2]);
				if (!ft_px_output_file(argv[argc - 1]))
				{
					return (1);
				}
			}
			else if (cmd_n == 1)
			{
				close(fd[pipe_read]);
				if (!ft_px_input_file(argv[1]))
				{
					return (1);
				}
				dup2(fd[pipe_write], 1);
				close(fd[pipe_write]);
			}
			else
			{
				close(fd[pipe_read]);
				dup2(fd[pipe_read - 2], 0);
				close(fd[pipe_read - 2]);
				dup2(fd[pipe_write], 1);
				close(fd[pipe_write]);
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
>>>>>>> 9ad55cae3be0a4e95bc561b8ca9f8a7477045b55
			}
		}
		else
		{
<<<<<<< HEAD
			/* 자식 */
			if (cmd_n == cmd_last)
			{
				dup2(fd[pipe_read - 2], 0);
				close(fd[pipe_read - 2]);
				if (!ft_px_output_file(argv[argc - 1]))
				{
					return (1);
				}
			}
			else if (cmd_n == 1)
			{
				close(fd[pipe_read]);
				if (!ft_px_input_file(argv[1]))
				{
					return (1);
				}
				dup2(fd[pipe_write], 1);
				close(fd[pipe_write]);
			}
			else
			{
				close(fd[pipe_read]);
				dup2(fd[pipe_read - 2], 0);
				close(fd[pipe_read - 2]);
				dup2(fd[pipe_write], 1);
				close(fd[pipe_write]);
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
				/* free */
				return (1);
			}
		}
		if (px_data -> cmd_paths != NULL)
		{
			free(px_data -> cmd_paths);
			px_data -> cmd_paths = NULL;
			if (px_data -> cmd_argv != NULL)
				free_splitted(px_data -> cmd_argv);
			px_data -> cmd_argv = NULL;
		}
		cmd_n++;
	}
	free(fd);
	free_px_data(px_data);
	return (0);
}

void	free_px_data(t_ft_px_data *px_data)
{
	px_data -> ac = 0;
	free(px_data -> cmd_paths);
	px_data -> cmd_paths = NULL;
	if (px_data -> cmd_argv != NULL)
		free_splitted(px_data -> cmd_argv);
	px_data -> cmd_argv = NULL;
	if (px_data -> paths != NULL)	
		free_splitted(px_data -> paths);
	px_data -> paths = NULL;
	free(px_data);
	return ;
}

void	free_splitted(char **strs)
{
	int	i;
      
	i = 0;
	while (strs[i] != NULL)
	{
		free(strs[i]);
		strs[i] = NULL;
		i++;
	}
	free(strs);
	return ;
=======
			/* 부모 */
			if (cmd_n == 1)
			{
				close(fd[pipe_write]);
			}
			else if (cmd_n == cmd_last)
			{
				close(fd[pipe_read - 2]);
			}
			else
			{
				close(fd[pipe_read - 2]);
				close(fd[pipe_write]);
			}
		}
		cmd_n++;
		/* 어차피 자식은 execve하느라 끝날 것 같긴한데. */
	}
	free(fd);
	return (0);
>>>>>>> 9ad55cae3be0a4e95bc561b8ca9f8a7477045b55
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