/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pesilva- <pesilva-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 14:09:02 by pesilva-          #+#    #+#             */
/*   Updated: 2024/06/26 17:56:05 by pesilva-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int	cheapest_move(t_stack *stack_a, t_stack *stack_b)
{
	int		cheapest;
	int		ra;
	int		rra;
	int		rb;
	int		rrb;
	t_stack	*current_a;
	t_stack	*current_b;


	current_a = stack_a;
	current_b = stack_b;
	ra = 0;
	rra = 0;
	rb = 0;
	rrb = 0;
	cheapest = 0;
	while (current_a->nbr != find_smallest(current_a))
	{
		ra++;
		rra++;
		rra++;
		current_a = current_a->next;
	}
	while (current_b->nbr != find_biggest(current_b))
	{
		rb++;
		rrb++;
		rrb++;
		current_b = current_b->next;
	}
	if (ra + rb < rra + rrb)
		cheapest = ra + rb;
	else
		cheapest = rra + rrb;
	return (cheapest);
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

int half_stack_small(t_stack **stacks)
{
	int smaller;
	int size;
	t_stack *stack;
	
	stack = *stacks;
	if (stack_size(stack) % 2 == 0)
		size = stack_size(stack) / 2;
	else 
		size = stack_size(stack) / 2 + 1;
	smaller = find_smallest(stack);
	while (stack)
	{
		if (stack->nbr == smaller)
		{
			if (stack->index <= size)
				return (1);
			else 
				return (2);
		}
		stack = stack->next;
	}
	return (0);
}

int half_stack_big(t_stack *current, t_stack *stacks)
{
	int biggest;
	int size;
	t_stack *stack;
	
	stack = stacks;
	if (stack_size(stack) % 2 == 0)
		size = stack_size(stack) / 2;
	else 
		size = stack_size(stack) / 2 + 1;
	biggest = find_biggest(stack);
	while (stack)
	{
		if (stack->nbr == biggest)
		{
			if (stack->index <= size)
				return (1);
			else 
				return (2);
		}
		stack = stack->next;
	}
	return (0);
}

static int	cheapest_a_to_b(t_stack *current, t_stack *stack_a)
{
	int	moves;
	
	if (!current || !stack_a)
		return (0);
	if (half_stack_size(stack_a))
		moves = current->index + 1;
	else
		moves = ((stack_size(stack_a) - 1) - current->index + 2);
	return (moves);
}

void cheapest_b_to_a(t_stack **stack_a, t_stack **stack_b)
{
	t_stack *a;
	t_stack *b;

	a = *stack_a;
	b = *stack_b;
	while (b)
	{
		if (half_stack_big(&b) == 1)
		{
			if (b->nbr == find_biggest(b))
				pa(&b, &a);
			else
				rb(&b);
		}
		else if (half_stack_big(&b) == 2)
		{
			if (b->nbr == find_biggest(b))
				pa(&b, &a);
			else
				rrb(&b);
		}
	}
	*stack_a = a;
	*stack_b = b;
}

void	move_a_to_b(t_stack **stack_a, t_stack **stack_b)
{
	int		cheapest;
	int		moves;
	t_stack	*best;
	t_stack	*current_b;
	
	current_a = *stack_a;
	current_b = *stack_b;
	i = 1;
	printf("current tail: %d\n", current_a->nbr);
	cheapest = cheapest_move(current_a, current_b);
	if (cheapest == 0)
		return ;
	if (stack_size(current_a) - cheapest < 3)
		cheapest = stack_size(current_a) - 3;
	printf("cheapest: %d\n", cheapest);
	while (i <= cheapest + 1)
	{
		if (current_a->nbr == find_smallest(current_a))
		{
			pb(&current_a, &current_b);
		}
		else
			ra(&current_a);
		print_stack(current_a, current_b);
		i++;
	}
	*stack_a = current_a;
	*stack_b = current_b;
}

void	move_b_to_a(t_stack **stack_a, t_stack **stack_b)
{
	int		cheapest;
	int		i;
	t_stack	*current_a;
	t_stack	*current_b;

	current_a = *stack_a;
	current_b = *stack_b;
	i = 0;
	cheapest = cheapest_move(current_b, current_a);
	if (cheapest == 0)
		return ;
	if (cheapest > stack_size(current_b))
		cheapest = stack_size(current_b);
	else if (cheapest < stack_size(current_b))
		cheapest = stack_size(current_b);
	while (i < cheapest)
	{
		printf("cheapest: %d\n", cheapest);
		if (current_b->nbr > find_biggest(current_a))
		{
			pa(&current_b, &current_a);
			ra(&current_a);
		}
		else if (current_b->nbr == find_biggest(current_b))
			pa(&current_b, &current_a);
		else
			rb(&current_b);
		i++;
	}
	*stack_a = current_a;
	*stack_b = current_b;
	print_stack(*stack_a, *stack_b);
}

 */