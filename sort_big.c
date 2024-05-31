/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pesilva- <pesilva-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 17:05:46 by pesilva-          #+#    #+#             */
/*   Updated: 2024/05/31 17:06:08 by pesilva-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_big(t_stack **stack_a, t_stack **stack_b)
{
	int		*array;
	int		i;
	int		size;

	size = stack_size(*stack_a);
	array = malloc(sizeof(int) * size);
	if (!array)
		return ;
	i = 0;
	while (i < size)
	{
		array[i] = (*stack_a)->nbr;
		ra(stack_a);
		i++;
	}
	i = 0;
	while (i < size)
	{
		pb(stack_a, stack_b);
		i++;
	}
	free(array);
}
