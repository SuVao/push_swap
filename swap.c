/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pesilva- <pesilva-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 16:36:34 by pesilva-          #+#    #+#             */
/*   Updated: 2024/06/01 12:43:27 by pesilva-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(t_stack *stack_a)
{
	int	tmp;

	if (stack_a == NULL || stack_a->next == NULL)
		return;
	tmp = stack_a->nbr;
	stack_a->nbr = stack_a->next->nbr;
	stack_a->next->nbr = tmp;
	tmp = stack_a->index;
	stack_a->index = stack_a->next->index;
	stack_a->next->index = tmp;
}

void	sa(t_stack *stack_a)
{
	swap(stack_a);
	printf("sa\n");
}

void	sb(t_stack *stack_b)
{
	swap(stack_b);
	printf("sb\n");
}

void	ss(t_stack *stack_a, t_stack *stack_b)
{
	swap(stack_a);
	swap(stack_b);
	printf("ss\n");
}