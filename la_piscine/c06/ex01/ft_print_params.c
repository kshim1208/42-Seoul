/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshim <kshim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 17:37:51 by kshim             #+#    #+#             */
/*   Updated: 2022/01/20 17:43:39 by kshim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
void	ft_put_str(char *param);

int	main(int argc, char *argv[])
{
	int	i;

	i = 1;
	while (i < argc)
	{
		ft_put_str(argv[i]);
		write(1, "\n", 1);
		i++;
	}
	return (0);
}

void	ft_put_str(char *param)
{
	int	i;

	i = 0;
	while (param[i] != '\0')
	{
		write(1, &param[i], 1);
		i++;
	}
}
