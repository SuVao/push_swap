/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pesilva- <pesilva-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 17:06:41 by pesilva-          #+#    #+#             */
/*   Updated: 2024/06/17 13:44:20 by pesilva-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	*sort_3(t_stack *stack_a)
{
	int		a;
	int		b;
	int		c;
	
	a = stack_a->nbr;
	b = stack_a->next->nbr;
	c = stack_a->next->next->nbr;
	if (a > b && b < c && a < c)
		sa(stack_a);
	else if (a > b && b > c && a > c)
	{
		sa(stack_a);
		rra(&stack_a);
	}
	else if (a > b && b < c && a > c)
		ra(&stack_a);
	else if (a < b && b > c && a < c)
	{
		sa(stack_a);
		ra(&stack_a);
	}
	else if (a < b && b > c && a > c)
		rra(&stack_a);
	return (stack_a);
}
