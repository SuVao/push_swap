/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pesilva- <pesilva-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 14:00:18 by pesilva-          #+#    #+#             */
/*   Updated: 2024/06/08 13:14:27 by pesilva-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void free_stack(t_stack **stack_a)
{
	t_stack	*tmp;

	while (*stack_a)
	{
		tmp = (*stack_a);
		(*stack_a) = (*stack_a)->next;
		free (tmp);
	}
}