/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pesilva- <pesilva-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 15:12:03 by pesilva-          #+#    #+#             */
/*   Updated: 2024/06/27 16:32:18 by pesilva-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	*sort_5(t_stack *stack_a, t_stack *stack_b)
{
	int		menor;

	menor = find_smallest(stack_a);
	while (stack_a->nbr != menor)
		ra(&stack_a);
	pb(&stack_a, &stack_b);
	menor = find_smallest(stack_a);
	while (stack_a->nbr != menor)
		ra(&stack_a);
	pb(&stack_a, &stack_b);
	sort_3(stack_a);
	pa(&stack_a, &stack_b);
	pa(&stack_a, &stack_b);
	return (stack_a);
}