/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pesilva- <pesilva-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 17:01:44 by pesilva-          #+#    #+#             */
/*   Updated: 2024/06/15 17:07:51 by pesilva-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*temp;

	if (!*stack_b)
		return ;
	temp = *stack_b;
	*stack_b = (*stack_b)->next;
	temp->next = *stack_a;
	*stack_a = temp;
}

void	pa(t_stack **stack_a, t_stack **stack_b)
{
	push(stack_a, stack_b);
	update_index(*stack_a);
	update_index(*stack_b);
	printf("pa\n");
}

void	pb(t_stack **stack_a, t_stack **stack_b)
{
	push(stack_b, stack_a);
	update_index(*stack_a);
	update_index(*stack_b);
	printf("pb\n");
}
/* 
int main()
{
	t_stack	*a;
	t_stack	*b;
	t_stack	*tmpa;
	t_stack	*tmpb;

	a = NULL;
	a = malloc(sizeof(t_stack));
	a->nbr = 3;
	a->next = malloc(sizeof(t_stack));
	a->next->nbr = 5;
	a->next->next = malloc(sizeof(t_stack));
	a->next->next->nbr = 1;
	a->next->next->next = NULL;
	b = NULL;
	b = malloc(sizeof(t_stack));
	b->nbr = 4;
	b->next = malloc(sizeof(t_stack));
	b->next->nbr = 6;
	b->next->next = malloc(sizeof(t_stack));
	b->next->next->nbr = 2;
	b->next->next->next = NULL;
	tmpa = a;
	tmpb = b;
	printf("antes: a\n");
	while (tmpa)
	{
		printf("valor:%d index: %d\n", tmpa->nbr, tmpa->index);
		tmpa = tmpa->next;
	}
	printf("antes: b\n");
	while (tmpb)
	{
		printf("valor:%d index: %d\n", tmpb->nbr, tmpb->index);
		tmpb = tmpb->next;
	}
	pa(&a, &b);
	printf("depois: a\n");
	while (a)
	{
		printf("valor:%d index: %d\n", a->nbr, a->index);
		a = a->next;
	}
	printf("depois: b\n");
	while (b)
	{
		printf("valor:%d index: %d\n", b->nbr, b->index);
		b = b->next;
	}
	return (0);
} */