/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshim <kshim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 17:48:27 by kshim             #+#    #+#             */
/*   Updated: 2022/01/22 21:04:49 by kshim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
int		ft_argu_cmp(char *p1, char *p2);
void	ft_put_params(int argc, char **argv);

int	main(int argc, char **argv)
{
	int		i;
	int		j;
	char	*temp;

	i = 1;
	if (argc == 1)
		return (0);
	while (i < argc - 1)
	{	
		j = 1;
		while (i + j < argc)
		{
			if (ft_argu_cmp(argv[i], argv[i + j]) == 1)
			{
				temp = argv[i];
				argv[i] = argv[i + j];
				argv[i + j] = temp;
			}
			j++;
		}
		i++;
	}
	ft_put_params(argc, argv);
	return (0);
}

int	ft_argu_cmp(char *p1, char *p2)
{
	int	i;

	i = 0;
	while (p1[i] != '\0' && p2[i] != '\0')
	{
		if ((unsigned char)p1[i] != (unsigned char)p2[i])
			break ;
		i++;
	}
	if ((unsigned char)p1[i] - (unsigned char)p2[i] > 0)
		return (1);
	return (0);
}

void	ft_put_params(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j] != '\0')
		{
			write(1, &argv[i][j], 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}
