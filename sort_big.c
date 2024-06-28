/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pesilva- <pesilva-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 17:05:46 by pesilva-          #+#    #+#             */
/*   Updated: 2024/06/28 14:12:27 by pesilva-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*current_bigger(t_stack *stack)
{
	t_stack	*bigger;
	int		biggest;

	bigger = stack;
	biggest = bigger->nbr;
	stack = stack->next;
	while (stack)
	{
		if (stack->nbr > biggest)
		{
			bigger = stack;
			biggest = bigger->nbr;
		}
		stack = stack->next;
	}
	return (bigger);
}

void	resorting_b(t_stack **stack_b)
{
	t_stack	*bigger;

	bigger = current_bigger(*stack_b);
	if (half_stack_small(bigger, *stack_b))
	{
		while ((*stack_b)->nbr != bigger->nbr)
			rb(stack_b);
	}
	else
	{
		while ((*stack_b)->nbr != bigger->nbr)
			rrb(stack_b);
	}
}

void	sort(t_stack **stack_a, t_stack **stack_b)
{
	int	regroup;

	if (!stack_a)
		return ;
	regroup = 3;
	pb(stack_a, stack_b);
	pb(stack_a, stack_b);
	while (stack_size(*stack_a) > 3)
		move_a_to_b(stack_a, stack_b);
	sort_3(*stack_a);
	resorting_b(stack_b);
	while (stack_size(*stack_b) > 0)
	{
		if (ft_thelast(*stack_a)->nbr > ((*stack_b)->nbr) && regroup > 0)
		{
			rra(stack_a);
			regroup--;
		}
		else
			pa(stack_a, stack_b);
	}
	while (regroup-- > 0)
		rra(stack_a);
}
