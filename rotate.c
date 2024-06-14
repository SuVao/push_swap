/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pesilva- <pesilva-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 16:58:18 by pesilva-          #+#    #+#             */
/*   Updated: 2024/06/14 17:21:25 by pesilva-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_stack *rotate(t_stack **stack)
{
    t_stack  *last;
    t_stack  *tmp;
    if (!stack)
        return (NULL);
    tmp = (*stack);
    last = ft_lstlast((*stack));
    (*stack) = (*stack)->next;
    (*stack)->prev = NULL;
    last->next = tmp;
    tmp->prev = last;
    tmp->next = NULL;
    update_index(*stack);
	printf("\nafter rotate\n");
	print_stack(*stack);
	return (*stack);
}

void	ra(t_stack **stack_a)
{
	rotate(stack_a);
	printf("ra\n");
	// print_lists(stack_a, stack_a);
}

void	rb(t_stack **stack_b)
{
	rotate(stack_b);
	printf("rb\n");
}

void	rr(t_stack **stack_a, t_stack **stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
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