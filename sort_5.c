/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pesilva- <pesilva-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 15:12:03 by pesilva-          #+#    #+#             */
/*   Updated: 2024/06/15 22:30:08 by pesilva-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int maior(t_stack *stack_a)
{
	int maior;
	t_stack *aux;

	aux = stack_a;
	maior = aux->nbr;
	while (aux)
	{
		if (aux->nbr > maior)
			maior = aux->nbr;
		aux = aux->next;
	}
	return (maior);
}

void	*sort_5(t_stack *stack_a, t_stack *stack_b)
{
	// int	i;
	// int	j;
	// int	k;
	// int	l;
	// int	m;
	
	// i = stack_a->nbr;
	// j = stack_a->next->nbr;
	// k = stack_a->next->next->nbr;
	// l = stack_a->next->next->next->nbr;
	// m = stack_a->next->next->next->next->nbr;
	pb(&stack_a, &stack_b);
	pb(&stack_a, &stack_b);
	stack_a = sort_3(stack_a);
	if (stack_b->nbr > stack_b->next->nbr)
		sb(stack_b);
	pa(&stack_a, &stack_b);
	pa(&stack_a, &stack_b);
	return (stack_a);
}