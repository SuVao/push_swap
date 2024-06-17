/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pesilva- <pesilva-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 17:01:44 by pesilva-          #+#    #+#             */
/*   Updated: 2024/06/17 13:46:37 by pesilva-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*temp;

	if (!*stack_b)
		return ;
	temp = *stack_b;
	*stack_b = (*stack_b)->next;
	temp->next = *stack_a;
	*stack_a = temp;
	update_index(*stack_a);
	update_index(*stack_b);
}

void	pa(t_stack **stack_a, t_stack **stack_b)
{

	push(stack_a, stack_b);
	printf("pa\n");
}

void	pb(t_stack **stack_a, t_stack **stack_b)
{

	push(stack_b, stack_a);
	printf("pb\n");
}
