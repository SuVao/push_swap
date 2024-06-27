/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pesilva- <pesilva-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 17:01:44 by pesilva-          #+#    #+#             */
/*   Updated: 2024/06/27 16:35:10 by pesilva-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*temp;

	if (!*stack_a)
		return ;
	temp = *stack_a;
	*stack_a = (*stack_a)->next;
	if (*stack_a)
		(*stack_a)->prev = NULL;
	temp->next = *stack_b;
	if (*stack_b)
		(*stack_b)->prev = temp;
	*stack_b = temp;
	update_index(*stack_a);
	update_index(*stack_b);
}

void	pa(t_stack **stack_a, t_stack **stack_b)
{

	push(stack_b, stack_a);
	printf("pa\n");
}

void	pb(t_stack **stack_a, t_stack **stack_b)
{

	push(stack_a, stack_b);
	printf("pb\n");
}
