/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pesilva- <pesilva-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 17:05:46 by pesilva-          #+#    #+#             */
/*   Updated: 2024/06/17 16:53:11 by pesilva-         ###   ########.fr       */
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

void	*sort(t_stack *stack_a, t_stack *stack_b)
{
	int		menor;
	int		biggest;
	int		index;
	int		ra_count;

	menor = find_smallest(stack_a);
	biggest = find_biggest(stack_a);
	index = find_index(stack_a, menor);
	ra_count = 0;
	while (stack_a->nbr != menor)
	{
		if (index < stack_size(stack_a) / 2)
			ra(&stack_a);
		else
			rra(&stack_a);
		ra_count++;
	}
	pb(&stack_a, &stack_b);
	index = find_index(stack_a, biggest);
	while (stack_a->nbr != biggest)
	{
		if (index < stack_size(stack_a) / 2)
			ra(&stack_a);
		else
			rra(&stack_a);
	}
	pb(&stack_a, &stack_b);
	stack_a = sort_3(stack_a);
	pa(&stack_a, &stack_b);
	pa(&stack_a, &stack_b);
	while (ra_count--)
		ra(&stack_a);
	return (stack_a);
}