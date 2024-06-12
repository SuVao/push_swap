/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkagem.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pesilva- <pesilva-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 15:58:21 by pesilva-          #+#    #+#             */
/*   Updated: 2024/06/12 16:09:58 by pesilva-         ###   ########.fr       */
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

int	stack_size(t_stack *a)
{
	int		count;
	t_stack	*tmp;

	count = 0;
	tmp = a;
	while (tmp)
	{
		count++;
		tmp = tmp->next;
	}
	return (count);
}

void	update_index(t_stack *source)
{
	int		index;
	t_stack	*tmp;

	tmp = source;
	index = 0;
	while (tmp)
	{
		tmp->index = index;
		tmp = tmp->next;
		index++;
	}
}