/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pesilva- <pesilva-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 17:05:46 by pesilva-          #+#    #+#             */
/*   Updated: 2024/06/18 16:14:37 by pesilva-         ###   ########.fr       */
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
	/* int		biggest;
	int		smallest;
	int		index; */
	int		size;

	size = stack_size(stack_a);
	while (size > 3)
	{
		pb(&stack_a, &stack_b);
		size--;
	}
	stack_a = sort_3(stack_a);
	while (stack_b)
		move_b_to_a(&stack_a, &stack_b);
	size = stack_size(stack_a);
	while (size > 3)
	{
		pb(&stack_a, &stack_b);
		size--;
	}
	stack_a = sort_3(stack_a);
	while (stack_b)
		move_b_to_a(&stack_a, &stack_b);
	printf("stack_a\n");
	print_stack(stack_a);
	printf("stack_b\n");
	print_stack(stack_b);

	return (stack_a);
}