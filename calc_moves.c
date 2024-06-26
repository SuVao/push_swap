/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_moves.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pesilva- <pesilva-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 17:29:44 by pesilva-          #+#    #+#             */
/*   Updated: 2024/06/26 14:19:49 by pesilva-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*smaller_node(t_stack *stack)
{
	t_stack *smaller;
	int	smallest;

	smaller = stack;
	smallest = smaller->nbr;
	stack = stack->next;
	while (stack)
	{
		if (stack->nbr < smallest)
		{
			smallest = smaller->nbr;
			smaller = stack;
		}
		stack = stack->next;
	}
	return (smaller);
}

int	calcula_moves()