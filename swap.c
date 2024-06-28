/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pesilva- <pesilva-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 16:36:34 by pesilva-          #+#    #+#             */
/*   Updated: 2024/06/28 13:26:53 by pesilva-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(t_stack *stack)
{
	int	tmp;

	if (stack_size(stack) < 2)
		return ;
	tmp = stack->nbr;
	stack->nbr = stack->next->nbr;
	stack->next->nbr = tmp;
}

void	sa(t_stack *stack_a)
{
	if (stack_a->next == NULL)
		return ;
	swap(stack_a);
	write(1, "sa\n", 3);
}

void	sb(t_stack *stack_b)
{
	if (stack_b->next == NULL)
		return ;
	swap(stack_b);
	write(1, "sb\n", 3);
}

void	ss(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->next == NULL || stack_b->next == NULL)
		return ;
	swap(stack_a);
	swap(stack_b);
	write(1, "ss\n", 3);
}
