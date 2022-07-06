/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ps_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshim <kshim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 14:01:55 by kshim             #+#    #+#             */
/*   Updated: 2022/07/05 13:40:07 by kshim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/checker_bonus.h"

int	ft_atoi_push_swap(const char *str, int *num)
{
	long long	ret;
	int			sign;

	ret = 0;
	sign = 1;
	sign = 1 - ((*str == '-') << 1);
	str += (*str == '+' || *str == '-');
	while (*str >= '0' && *str <= '9')
	{
		ret = ret * 10 + (*str - '0');
		if ((ret * sign) > 2147483647 || (ret * sign) < -2147483648)
			return (0);
		str++;
	}
	if (*str == '\0' && ((*str - 1) != '+' || (*str - 1) != '-'))
		*num = (int)(ret * sign);
	else
		return (0);
	return (1);
}

int	ft_ps_deque_init_value(t_d_list **new_list, int value)
{
	t_value	*content;

	content = (t_value *)malloc(sizeof(t_value));
	if (content == NULL)
		return (0);
	content -> value = value;
	*new_list = ft_d_lstnew(content);
	if (*new_list == NULL)
		return (0);
	return (1);
}

void	ft_free_split(char **splited)
{
	int	i;

	i = 0;
	while (splited[i] != NULL)
	{
		free(splited[i]);
		splited[i] = NULL;
		i++;
	}
	free(splited);
	splited = NULL;
	return ;
}

void	ft_ps_free_index_list(t_detower **index)
{
	t_d_list	*lst;

	lst = (*index)-> head;
	if (lst != NULL)
		ft_d_lstclear(&lst, NULL);
	(*index)-> head = NULL;
	(*index)-> tail = NULL;
	return ;
}
