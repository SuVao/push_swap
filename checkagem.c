/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkagem.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pesilva- <pesilva-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 15:58:21 by pesilva-          #+#    #+#             */
/*   Updated: 2024/06/08 13:12:23 by pesilva-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* int	check(t_stack **stack_a)
{
	
} */

int	s_sorted(t_stack **stack)
{
	int	i;

	i = (*stack)->nbr;
	while ((*stack)->next != NULL)
	{
		if ((*stack)->nbr < (*stack)->next->nbr)
			return (0);
		(*stack) = (*stack)->next;
	}
	return (1);
}