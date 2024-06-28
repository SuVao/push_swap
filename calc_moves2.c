/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_moves2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pesilva- <pesilva-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 14:14:23 by pesilva-          #+#    #+#             */
/*   Updated: 2024/06/28 14:23:18 by pesilva-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_smaller(int nbr, t_stack *stack)
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

static t_stack	*find_target_on_b(int nbr, t_stack *stack)
{
	t_stack	*target;
	int		init;
	int		bigger;

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

t_stack	*target_(int nbr, t_stack *stack_b)
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

t_stack	*smaller_node(t_stack *stack)
{
	t_stack	*smaller;
	int		smallest;

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
