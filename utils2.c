/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pesilva- <pesilva-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 14:16:37 by pesilva-          #+#    #+#             */
/*   Updated: 2024/06/28 14:24:46 by pesilva-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	making(t_stack *stack, t_stack *target, t_stack **a, t_stack **b)
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

void	update_index(t_stack *source)
{
	t_stack	*tmp;
	int		index;

	tmp = source;
	index = 0;
	while (tmp)
	{
		tmp->index = index;
		tmp = tmp->next;
		index++;
	}
}

void	ft_lstadd_back(t_stack **lst, t_stack *new)
{
	t_stack	*tmp;

	if (!*lst)
	{
		*lst = new;
		return ;
	}
	tmp = *lst;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
}

t_stack	*ft_lstlast(t_stack *lst)
{
	t_stack	*tmp;

	tmp = lst;
	while (tmp->next)
		tmp = tmp->next;
	return (tmp);
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
