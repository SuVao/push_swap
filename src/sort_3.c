/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pesilva- <pesilva-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 16:23:29 by pesilva-          #+#    #+#             */
/*   Updated: 2024/09/06 16:07:51 by pesilva-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_3(t_stack **stack_a)
{
	int	a;
	int	b;
	int	c;

	a = (*stack_a)->nbr;
	b = (*stack_a)->next->nbr;
	c = (*stack_a)->next->next->nbr;
	if (a < b && b > c)
	{
		rra(stack_a);
		if (c > a)
			sa(*stack_a);
	}
	else if (a > b && b < c)
	{
		if (a < c)
			sa(*stack_a);
		else if (a > c)
			ra(stack_a);
	}
	else if (a > b && b > c)
	{
		sa(*stack_a);
		rra(stack_a);
	}
}
