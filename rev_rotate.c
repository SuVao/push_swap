/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pesilva- <pesilva-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 17:02:45 by pesilva-          #+#    #+#             */
/*   Updated: 2024/06/13 17:05:05 by pesilva-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rev_rotate(t_stack **stack)
{
	t_stack	*temp;
	t_stack	*temp2;

	if (!*stack || !(*stack)->next)
		return ;
	temp = *stack;
	temp2 = *stack;
	while (temp2->next->next)
		temp2 = temp2->next;
	temp2->next->next = temp;
	*stack = temp2->next;
	temp2->next = NULL;
}

void	rra(t_stack **stack_a)
{
	rev_rotate(stack_a);
	update_index(*stack_a);
	printf("rra\n");
}

void	rrb(t_stack **stack_b)
{
	rev_rotate(stack_b);
	update_index(*stack_b);
	printf("rrb\n");
}

void	rrr(t_stack **stack_a, t_stack **stack_b)
{
	rev_rotate(stack_a);
	update_index(*stack_a);
	rev_rotate(stack_b);
	update_index(*stack_b);
	printf("rrr\n");
}
/* 
int main()
{
	t_stack	*a;
	t_stack	*b;
	t_stack	*tmpa;
	t_stack	*tmpb;
	t_stack	*head;
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
	head = a;
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
	rra(&a);
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

