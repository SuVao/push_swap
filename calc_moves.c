/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_moves.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pesilva- <pesilva-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 17:29:44 by pesilva-          #+#    #+#             */
/*   Updated: 2024/06/27 17:45:34 by pesilva-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*smaller_node(t_stack *stack)
{
	t_stack *smaller;
	int	smallest;

	smaller = stack;
	smallest = smaller->nbr;
	stack = stack->next;
	while (stack)
	{
		if (stack->nbr < smallest)
		{
			smallest = smaller->nbr;
			smaller = stack;
		}
		stack = stack->next;
	}
	return (smaller);
}


static int	a_moves(t_stack *current, t_stack *stack_a)
{
	int	moves;
	
	if (!current || !stack_a)
		return (0);
	if (half_stack_small(current, stack_a))
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

static t_stack	*find_target_on_b(int nbr ,t_stack *stack)
{
	t_stack *target;
	int init;
	int bigger;

	if (!stack)
		return (NULL);
	init = 0;
	while (stack)
	{
		if (init == 0 && stack->nbr < nbr)
		{
			bigger = stack->nbr;
			target = stack;
			init++;
		}
		if (init != 0 && stack->nbr < nbr && stack->nbr > bigger)
		{
			target = stack;
			bigger = stack->nbr;
		}
		stack = stack->next;
	}
	return (target);
}

t_stack *target_(int nbr, t_stack *stack_b)
{
	t_stack	*smaller;

	if (!stack_b)
		return (NULL);
	if (is_smaller(nbr, stack_b))
	{
		smaller = smaller_node(stack_b);
		if (smaller->next == NULL)
			return (NULL);
		else
			return (smaller->next);
	}
	return (find_target_on_b(nbr, stack_b));
}

int is_smaller(int nbr, t_stack *stack)
{
	if (!stack)
		return (0);
	while (stack)
	{
		if (stack->nbr < nbr)
			return (0);
		stack = stack->next;
	}
	return (1);
}

static int saving(t_stack *current, t_stack *target, t_stack *a, t_stack *b)
{
	int current_;
	int target_;

	if (!current || !target || !a || !b)
		return (0);
	if (half_stack_small(current, a) && half_stack_small(target, b) \
		&& current->index != 0 && target->index != 0)
	{
		if (current->index == target->index)
			return (current->index);
		else
			return (the_lower_nbr(current->index, target->index));
	}
	else if (!half_stack_small(current, a) && !half_stack_small(target, b))
	{
		current_ = ((ft_thelast(a)->index) - current->index);
		target_ = ((ft_thelast(b)->index) - target->index);
		if (current_ == target_)
			return (current_);
		else
			return (the_lower_nbr(current_, target_));
	}
	else
		return (0);
}

int	calcula_moves(t_stack *current, t_stack *a, t_stack *b)
{
	int moves;
	t_stack *target;

	if (!current || !a || !b)
		return (0);
	moves = a_moves(current, a);
	target = target_(current->nbr, b);
	if (!target)
		return (++moves);
	if (target->index == 1)
		return (moves);
	moves += b_moves(target, b);
	moves -= saving(current, target, a, b);
	return (moves);
}