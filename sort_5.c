/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pesilva- <pesilva-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 17:07:00 by pesilva-          #+#    #+#             */
/*   Updated: 2024/06/12 14:33:35 by pesilva-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_5(t_stack *stack_a, t_stack *stack_b)
{
	int		a;
	int		b;
	int		c;
	int		d;
	int		e;

	a = stack_a->nbr;
	b = stack_a->next->nbr;
	c = stack_a->next->next->nbr;
	d = stack_a->next->next->next->nbr;
	e = stack_a->next->next->next->next->nbr;
	if (a > b && b < c && a < c)
		sa(stack_a);
	else if (a > b && b > c && a > c)
	{
		sa(stack_a);
		rra(stack_a);
	}
	else if (a > b && b > c && a < c)
		ra(stack_a);
	else if (a < b && b > c && a < c)
		sa(stack_a);
	else if (a < b && b > c && a > c)
		rra(stack_a);
	pb(stack_a, stack_b);
	pb(stack_a, stack_b);
	sort_3(stack_a);
	pa(stack_a, stack_b);
	pa(stack_a, stack_b);
}
