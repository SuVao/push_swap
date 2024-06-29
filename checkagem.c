/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkagem.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pesilva- <pesilva-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 15:58:21 by pesilva-          #+#    #+#             */
/*   Updated: 2024/06/29 15:15:22 by pesilva-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_stack *a)
{
	t_stack	*tmp;

	tmp = a;
	while (tmp && tmp->next)
	{
		if (tmp->nbr > tmp->next->nbr)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

static int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

int	nbr_check(char **str)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			if (!ft_isdigit(str[i][j]) && str[i][j] != '-' && \
				str[i][j] != '+' && str[i][j] != '"')
			{
				write(1, "Charater detected!\n", 20);
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	check_nbr(t_stack *a)
{
	t_stack	*tmp;
	t_stack	*tmp2;

	tmp = a;
	while (tmp)
	{
		tmp2 = tmp->next;
		while (tmp2)
		{
			if (tmp->nbr == tmp2->nbr)
			{
				write(1, "Numero repetido!\n", 18);
				return (0);
			}
			tmp2 = tmp2->next;
		}
		tmp = tmp->next;
	}
	return (1);
}

int	stack_size(t_stack *a)
{
	int		count;

	if (!a)
		return (0);
	count = 0;
	while (a)
	{
		count++;
		a = a->next;
	}
	return (count);
}
