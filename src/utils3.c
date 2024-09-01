/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pesilva- <pesilva-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 14:18:39 by pesilva-          #+#    #+#             */
/*   Updated: 2024/09/01 17:49:17 by pesilva-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//this function see which number is the smaller
int	find_smallest(t_stack *stack)
{
	int		smallest;
	t_stack	*current;

	current = stack;
	smallest = current->nbr;
	while (current)
	{
		if (current->nbr < smallest)
			smallest = current->nbr;
		current = current->next;
	}
	return (smallest);
}

int	its_par(int nbr)
{
	if (nbr % 2 == 0)
		return (0);
	else
		return (1);
}

int	looking_flag(t_stack *a)
{
	t_stack	*tmp;

	tmp = a;
	while (tmp)
	{
		if (tmp->error_nbr == 1)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}
