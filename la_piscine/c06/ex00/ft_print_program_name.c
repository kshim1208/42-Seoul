/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_program_name.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshim <kshim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 17:32:56 by kshim             #+#    #+#             */
/*   Updated: 2022/01/20 17:37:10 by kshim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
void	ft_put_str(char *name);

int	main(int argc, char *argv[])
{
	char	*name;

	name = argv[argc - argc];
	ft_put_str(name);
	write(1, "\n", 1);
}

void	ft_put_str(char *name)
{
	int	i;

	i = 0;
	while (name[i] != '\0')
	{
		write(1, &name[i], 1);
		i++;
	}
}
