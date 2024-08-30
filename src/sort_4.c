/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pesilva- <pesilva-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 15:12:03 by pesilva-          #+#    #+#             */
/*   Updated: 2024/06/30 15:30:55 by pesilva-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_4(t_stack **stack_a, t_stack **stack_b)
{
	int	rep;

	rep = 3;
	pb(stack_a, stack_b);
	sort_3(stack_a);
	while (stack_size(*stack_b) > 0)
	{
		if (ft_thelast(*stack_a)->nbr > ((*stack_b)->nbr) && rep > 0)
		{
			rra(stack_a);
			rep--;
		}
		else
			pa(stack_a, stack_b);
	}
	while (rep-- > 0)
		rra(stack_a);
}
