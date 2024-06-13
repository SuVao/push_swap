/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pesilva- <pesilva-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 16:58:18 by pesilva-          #+#    #+#             */
/*   Updated: 2024/06/13 16:32:58 by pesilva-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate(t_stack **stack)
{
	t_stack	*temp;
	t_stack	*current;

	current = (*stack);
	temp = (*stack);
	(*stack) = (*stack)->next;
	if ((*stack)->next == NULL)
		(*stack)->next = temp;
	else
	{
		while (current->next != NULL)
			current = current->next;
		current->next = temp;
	}
	temp->next = NULL;
}

void	ra(t_stack **stack_a)
{
	rotate(stack_a);
	update_index(*stack_a);
	printf("ra\n");
}

void	rb(t_stack **stack_b)
{
	rotate(stack_b);
	update_index(*stack_b);
	printf("rb\n");
}

void	rr(t_stack **stack_a, t_stack **stack_b)
{
	rotate(stack_a);
	update_index(*stack_a);
	rotate(stack_b);
	update_index(*stack_b);
	printf("rr\n");
}

/* int main()
{
	t_stack	*a;
	t_stack	*b;
	t_stack	*tmpa;
	t_stack	*tmpb;

	a = NULL;
	a = malloc(sizeof(t_stack));
	a->nbr = 2;
	a->next = malloc(sizeof(t_stack));
	a->next->nbr = 1;
	a->next->next = malloc(sizeof(t_stack));
	a->next->next->nbr = 3;
	a->next->next->next = NULL;
	b = NULL;
	b = malloc(sizeof(t_stack));
	b->nbr = 3;
	b->next = malloc(sizeof(t_stack));
	b->next->nbr = 5;	
	b->next->next = malloc(sizeof(t_stack));
	b->next->next->nbr = 1;
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
	ra(&a);
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
/* 
int	main()
{
	t_stack	*a;
	t_stack	*tmp;
	
	a = NULL;
	a = malloc(sizeof(t_stack));
	a->nbr = 2;
	a->next = malloc(sizeof(t_stack));
	a->next->nbr = 1;
	a->next->next = malloc(sizeof(t_stack));
	a->next->next->nbr = 3;
	a->next->next->next = NULL;
	printf("antes:\n");
	while (a)
	{
		printf("%d\n", a->nbr);
		a = a->next;
	}
	tmp = a;
	ra(&a);
	printf("depois:\n");
	while (tmp)
	{
		printf("%d\n", tmp->nbr);
		tmp = tmp->next;
	}
} */