/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pesilva- <pesilva-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 16:36:34 by pesilva-          #+#    #+#             */
/*   Updated: 2024/06/12 17:05:00 by pesilva-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(t_stack *stack)
{
	int	tmp;

	if (stack == NULL)
		return;
	tmp = stack->nbr;
	stack->nbr = stack->next->nbr;
	stack->next->nbr = tmp;
}

void	sa(t_stack *stack_a)
{
	if (stack_a->next == NULL)
		return;
	swap(stack_a);
	printf("sa\n");
}

void	sb(t_stack *stack_b)
{
	if (stack_b->next == NULL)
		return;
	swap(stack_b);
	printf("sb\n");
}

void	ss(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->next == NULL || stack_b->next == NULL)
		return;
	swap(stack_a);
	swap(stack_b);
	printf("ss\n");
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
	b->nbr = 3;
	b->next = malloc(sizeof(t_stack));
	b->next->nbr = 5;
	b->next->next = malloc(sizeof(t_stack));
	b->next->next->nbr = 1;
	b->next->next->next = NULL;
	printf("Before a:\n");
	tmpa = a;
	while (tmpa)
	{
		printf("%d\n", tmpa->nbr);
		tmpa = tmpa->next;
	}
	tmpb = b;
	printf("Before b:\n");
	while (tmpb)
	{
		printf("%d\n", tmpb->nbr);
		tmpb = tmpb->next;
	}
	ss(a, b);
	printf("After a:\n");
	while (a)
	{
		printf("%d\n", a->nbr);
		a = a->next;
	}
	printf("After b:\n");
	while (b)
	{
		printf("%d\n", b->nbr);
		b = b->next;
	}
	


	return (0);
} */