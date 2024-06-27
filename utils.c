/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pesilva- <pesilva-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 14:09:02 by pesilva-          #+#    #+#             */
/*   Updated: 2024/06/27 17:00:56 by pesilva-         ###   ########.fr       */
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

int half_stack_small(t_stack *current, t_stack *stack)
{
	int center;

	if (!current || !stack)
		return (0);
	if (stack_size(stack) % 2 == 0)
		center = stack_size(stack) / 2;
	else
		center = stack_size(stack) / 2 + 1;
	if (current->index + 1 <= center)
		return (1);
	else
		return (0);
}
/* 
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
 */
static int	a_moves(t_stack *current, t_stack *stack_a)
{
	int	moves;
	
	if (!current || !stack_a)
		return (0);
	if (!half_stack_small(current, stack_a))
		moves = current->index + 1;
	else
		moves = ((stack_size(stack_a) - 1) - current->index + 2);
	return (moves);
}

static int	b_moves(t_stack *current, t_stack *stack_b)
{
	int	moves;
	
	if (!current || !stack_b)
		return (0);
	if (half_stack_small(current, stack_b))
		moves = current->index;
	else
		moves = ((stack_size(stack_b) - 1) - current->index + 1);
	return (moves);
}

/* void cheapest_b_to_a(t_stack **stack_a, t_stack **stack_b)
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
 */

void	move_to_b(t_stack **stack_a, t_stack **stack_b, t_stack *target)
{
	if (!stack_a || !stack_b)
		return ;
	if (!target)
	{
		pb(stack_a, stack_b);
		rb(stack_b);
		return ;
	}
	if (half_stack_small(target, *stack_b))
	{
		while (target->index != 0)
			rb(stack_b);
		pb(stack_a, stack_b);
	}
	else
	{
		while (target->index != 0)
			rrb(stack_b);
		pb(stack_a, stack_b);
	}
}

static void making(t_stack *stack, t_stack *target, t_stack **a, t_stack **b)
{
	if (!stack || !a || !b)
		return ;
	if (half_stack_small(stack, *a))
	{
		if (half_stack_small(target, *b) && (target))
		{
			while (stack->index != 0 && target->index != 0)
				rr(a, b);
		}
		while (stack->index != 0)
			ra(a);
	}
	else
	{
		if (!half_stack_small(target, *b) && target)
		{
			while (stack->index != 0 && target->index != 0)
				rrr(a, b);
		}
		while (stack->index != 0)
			rra(a);
	}
	move_to_b(a, b, target);
}

void	move_a_to_b(t_stack **stack_a, t_stack **stack_b)
{
	int		cheapest;
	int		moves;
	t_stack	*best;
	t_stack	*target;
	t_stack	*tmp;
	
	if (!*stack_a)
		return ;
	tmp = *stack_a;
	cheapest = calcula_moves(tmp, *stack_a, *stack_b);
	best = tmp;
	tmp = tmp->next;
	while (tmp)
	{
		moves = calcula_moves(tmp, *stack_a, *stack_b);
		if (moves < cheapest)
		{
			cheapest = moves;
			best = tmp;
		}
		tmp = tmp->next;
	}
	target = target_(best->nbr, *stack_b);
	making(best, target, stack_a, stack_b);
}