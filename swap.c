/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pesilva- <pesilva-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 16:36:34 by pesilva-          #+#    #+#             */
/*   Updated: 2024/05/31 16:58:13 by pesilva-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(t_stack *pilha_a)
{
	int	tmp;

	if (pilha_a == NULL || pilha_a->next == NULL)
		return;
	tmp = pilha_a->nbr;
	pilha_a->nbr = pilha_a->next->nbr;
	pilha_a->next->nbr = tmp;
	tmp = pilha_a->index;
	pilha_a->index = pilha_a->next->index;
	pilha_a->next->index = tmp;
}

void	sa(t_stack *pilha_a)
{
	swap(pilha_a);
	printf("sa\n");
}

void	sb(t_stack *pilha_b)
{
	swap(pilha_b);
	printf("sb\n");
}

void	ss(t_stack *pilha_a, t_stack *pilha_b)
{
	swap(pilha_a);
	swap(pilha_b);
	printf("ss\n");
}