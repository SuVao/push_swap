/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pesilva- <pesilva-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 14:09:02 by pesilva-          #+#    #+#             */
/*   Updated: 2024/06/19 17:39:54 by pesilva-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	cheapest_move(t_stack *stack_a, t_stack *stack_b)
{
	int		cheapest;
	int		ra;
	int		rra;
	int		rb;
	int		rrb;

	ra = 0;
	rra = 0;
	rb = 0;
	rrb = 0;
	cheapest = 0;
	while (stack_a->nbr != find_smallest(stack_a))
	{
		ra++;
		rra++;
		rra++;
		stack_a = stack_a->next;
	}
	while (stack_b->nbr != find_biggest(stack_b))
	{
		rb++;
		rrb++;
		rrb++;
		stack_b = stack_b->next;
	}
	if (ra + rb < rra + rrb)
		cheapest = ra + rb;
	else
		cheapest = rra + rrb;
	return (cheapest);
}

void	move_a_to_b(t_stack **stack_a, t_stack **stack_b)
{
	int		cheapest;
	int		i;

	i = 0;
	cheapest = cheapest_move(*stack_a, *stack_b);
	while (i < cheapest)
	{
		if ((*stack_a)->nbr == find_smallest(*stack_a))
			pb(stack_a, stack_b);
		else
			ra(stack_a);
		i++;
	}
}

void	move_b_to_a(t_stack **stack_a, t_stack **stack_b)
{
	int		cheapest;
	int		i;

	i = 0;
	cheapest = cheapest_move(*stack_b, *stack_a);
	while (i < cheapest)
	{
		if ((*stack_b)->nbr == find_biggest(*stack_b))
			pa(stack_a, stack_b);
		else
			rb(stack_b);
		i++;
	}
}