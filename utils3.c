/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pesilva- <pesilva-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 14:18:39 by pesilva-          #+#    #+#             */
/*   Updated: 2024/06/28 14:19:53 by pesilva-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int	is_the_small(int nbr, t_stack *stack)
{
	if (!stack)
		return (0);
	while (stack->next)
	{
		if (stack->nbr == find_smallest(stack))
			return (1);
		stack = stack->next;
	}
	return (0);
}
