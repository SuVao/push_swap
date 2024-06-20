/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pesilva- <pesilva-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 14:09:02 by pesilva-          #+#    #+#             */
/*   Updated: 2024/06/20 18:49:42 by pesilva-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int find_biggest(t_stack *stack)
{
	int		biggest;
	t_stack	*current;

	current = stack;
	biggest = current->nbr;
	while (current)
	{
		if (current->nbr > biggest)
			biggest = current->nbr;
		current = current->next;
	}
	return (biggest);
}

int	find_smallest(t_stack *stack)
{
	int		smallest;
	t_stack	*current;

	current = stack;
	smallest = current->nbr;
	while (current)
	{
		if (current->nbr < smallest)
			smallest = current->nbr;
		current = current->next;
	}
	return (smallest);
}

int	cheapest_move(t_stack *stack_a, t_stack *stack_b)
{
	int		cheapest;
	int		ra;
	int		rra;
	int		rb;
	int		rrb;
	t_stack	*current_a;
	t_stack	*current_b;


	current_a = stack_a;
	current_b = stack_b;
	ra = 0;
	rra = 0;
	rb = 0;
	rrb = 0;
	cheapest = 0;
	while (current_a->nbr != find_smallest(current_a))
	{
		ra++;
		rra++;
		rra++;
		current_a = current_a->next;
	}
	while (current_b->nbr != find_biggest(current_b))
	{
		rb++;
		rrb++;
		rrb++;
		current_b = current_b->next;
	}
	if (ra + rb < rra + rrb)
		cheapest = ra + rb;
	else
		cheapest = rra + rrb;
	return (cheapest);
}

void	move_a_to_b(t_stack **stack_a, t_stack **stack_b)
{
	int		cheapest;
	int		i;
	t_stack	*current_a;
	t_stack	*current_b;
	
	current_a = *stack_a;
	current_b = *stack_b;
	i = 0;
	/* printf("current tail: %d\n", current_a->nbr); */
	cheapest = cheapest_move(current_a, current_b);
	if (cheapest == 0)
		return ;
	printf("=====================\n");
	printf("cheapest: %d\n", cheapest);
	while (i < cheapest)
	{
		if (current_a->nbr == find_smallest(current_a))
		{
			pb(&current_a, &current_b);
			
		}
		else
			ra(&current_a);
		i++;
	}
	printf("=========stack rodada=========\n");
	*stack_a = current_a;
	*stack_b = current_b;
	print_stack(*stack_a, *stack_b);
}

void	move_b_to_a(t_stack *stack_a, t_stack *stack_b)
{
	int		cheapest;
	int		i;

	i = 0;
	cheapest = cheapest_move(stack_b, stack_a);
	while (i < cheapest)
	{
		if (stack_b->nbr == find_biggest(stack_b))
		{
			pa(&stack_b, &stack_a);
		}
		else
			rb(&stack_b);
		i++;
	}
}

