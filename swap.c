/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pesilva- <pesilva-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 16:36:34 by pesilva-          #+#    #+#             */
/*   Updated: 2024/06/08 13:22:08 by pesilva-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(t_stack **stack)
{
	int	tmp;

	if ((*stack) == NULL || (*stack)->next == NULL)
		return;
	tmp = (*stack)->nbr;
	(*stack)->nbr = (*stack)->next->nbr;
	(*stack)->next->nbr = tmp;
	tmp = (*stack)->index;
	(*stack)->index = (*stack)->next->index;
	(*stack)->next->index = tmp;
}

void	sa(t_stack **stack_a)
{
	swap(stack_a);
	printf("sa\n");
}

void	sb(t_stack **stack_b)
{
	swap(stack_b);
	printf("sb\n");
}

void	ss(t_stack **stack_a, t_stack **stack_b)
{
	swap(stack_a);
	swap(stack_b);
	printf("ss\n");
}