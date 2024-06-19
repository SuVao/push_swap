/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pesilva- <pesilva-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 17:05:46 by pesilva-          #+#    #+#             */
/*   Updated: 2024/06/19 17:54:46 by pesilva-         ###   ########.fr       */
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

int	find_pivot(t_stack *stack)
{
	int		pivot;
	int		biggest;
	int		smallest;

	biggest = find_biggest(stack);
	smallest = find_smallest(stack);
	pivot = (biggest + smallest) / 2;
	return (pivot);
}

int	rev_is_sort(t_stack *stack)
{
	t_stack	*current;

	current = stack;
	while (current->next)
	{
		if (current->nbr > current->next->nbr)
			return (0);
		current = current->next;
	}
	return (1);
}

/* void	*quicksort(t_stack *stack_a, t_stack *stack_b, int size)
{
	int pivot;
	int i;

	if (stack_size(stack_a) <= 3)
		stack_a = sort_3(stack_a);
	i = 0;
	pivot = find_pivot(stack_a);
	while (i < stack_size(stack_a))
	{
		if (stack_a->nbr < pivot)
			pb(&stack_a, &stack_b);
		else
			ra(&stack_a);
		i++;
	}
	if (rev_is_sort(stack_b))
	{
		while (stack_b)
			pa(&stack_a, &stack_b);
		return (stack_a);
	}
	while (stack_b)
		pa(&stack_a, &stack_b);
	if (is_sorted(stack_a) && stack_size(stack_a) == size)
		return (stack_a);
	else
		return (quicksort(stack_a, stack_b, size));
}
 */

void	*sort(t_stack *stack_a, t_stack *stack_b)
{
	int i;

	i = 0;
	while (stack_size(stack_a) > 3)
	{
		if (stack_a->nbr == find_smallest(stack_a))
			ra(&stack_a);
		else
			pb(&stack_a, &stack_b);
	}
	stack_b = sort_3(stack_b);
	while (stack_size(stack_a) > 3)
		move_a_to_b(&stack_a, &stack_b);
	while (stack_b)
		pa(&stack_a, &stack_b);
	return (stack_a);
}