/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pesilva- <pesilva-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 17:02:45 by pesilva-          #+#    #+#             */
/*   Updated: 2024/05/31 17:03:00 by pesilva-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rev_rotate(t_stack **stack)
{
	t_stack	*temp;
	t_stack	*temp2;

	if (!*stack || !(*stack)->next)
		return ;
	temp = *stack;
	temp2 = *stack;
	while (temp2->next->next)
		temp2 = temp2->next;
	temp2->next->next = temp;
	*stack = temp2->next;
	temp2->next = NULL;
}

void	rra(t_stack **stack_a)
{
	rev_rotate(stack_a);
	printf("rra\n");
}

void	rrb(t_stack **stack_b)
{
	rev_rotate(stack_b);
	printf("rrb\n");
}

void	rrr(t_stack **stack_a, t_stack **stack_b)
{
	rev_rotate(stack_a);
	rev_rotate(stack_b);
	printf("rrr\n");
}