/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pesilva- <pesilva-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 14:09:02 by pesilva-          #+#    #+#             */
/*   Updated: 2024/09/06 16:07:06 by pesilva-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

//this function sees if it is odd or pair to decide if the number of the middle
int	half_stack_small(t_stack *current, t_stack *stack)
{
	int	center;

	if (!current || !stack)
		return (0);
	if (its_par(stack_size(stack)))
		center = ((stack_size(stack) / 2) + 1);
	else
		center = stack_size(stack) / 2;
	if (current->index + 1 <= center)
		return (1);
	else
		return (0);
}

int	find_biggest(t_stack *stack)
{
	int		biggest;
	t_stack	*current;

	current = stack;
	biggest = current->nbr;
	while (current)
	{
		if (current->nbr > biggest)
			biggest = current->nbr;
		current = current->next;
	}
	return (biggest);
}

//this function makes the move from stack a to stack b with the target node 
void	move_to_b(t_stack **stack_a, t_stack **stack_b, t_stack *target)
{
	if (!stack_a || !stack_b)
		return ;
	if (!target)
	{
		pb(stack_a, stack_b);
		rb(stack_b);
		return ;
	}
	if (half_stack_small(target, *stack_b))
	{
		while (target->index != 0)
			rb(stack_b);
		pb(stack_a, stack_b);
	}
	else
	{
		while (target->index != 0)
			rrb(stack_b);
		pb(stack_a, stack_b);
	}
}
