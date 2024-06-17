/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pesilva- <pesilva-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 17:05:46 by pesilva-          #+#    #+#             */
/*   Updated: 2024/06/17 14:18:23 by pesilva-         ###   ########.fr       */
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

int find_biggest(t_stack *stack)
{
	int		biggest;
	t_stack	*current;

	current = stack;
	biggest = current->nbr;
	while (current)
	{
		if (current->nbr > biggest)
			biggest = current->nbr;
		current = current->next;
	}
	return (biggest);
}

/* int	find_median(t_stack *stack)
{
	int		median;
	int		*array;
	int		i;
	t_stack	*current;

	current = stack;
	array = malloc(sizeof(int) * stack_size(stack));
	if (!array)
		return (0);
	i = 0;
	while (current)
	{
		array[i] = current->nbr;
		current = current->next;
		i++;
	}
	quick_sort(array, 0, stack_size(stack) - 1);
	median = array[stack_size(stack) / 2];
	free(array);
	return (median);
} */

int	find_index(t_stack *stack, int nbr)
{
	int		index;
	t_stack	*current;

	current = stack;
	index = 0;
	while (current)
	{
		if (current->nbr == nbr)
			return (index);
		current = current->next;
		index++;
	}
	return (index);
}

/* void	*sort(t_stack *stack_a, t_stack stack_b)
{
	
} */