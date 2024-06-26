/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pesilva- <pesilva-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 17:05:46 by pesilva-          #+#    #+#             */
/*   Updated: 2024/06/26 16:24:59 by pesilva-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
/* 
int	find_pivot(t_stack *stack)
{
	int		pivot;
	int		biggest;
	int		smallest;

	biggest = find_biggest(stack);
	smallest = find_smallest(stack);
	pivot = (biggest + smallest) / 2;
	return (pivot);
}

 */
/* void	*quicksort(t_stack *stack_a, t_stack *stack_b)
{
	int pivot;
	t_stack *current_a;
	t_stack *current_b;

	current_a = stack_a;
	current_b = stack_b;
	pivot = find_pivot(stack_a);
	while (current_a)
	{
		if (current_a->nbr > pivot)
			pb(&current_a, &current_b);
		else
		{
			pb(&current_a, &current_b);
			rb(&current_b);
		}
	}
	print_stack(current_a, current_b);
	pivot = (pivot + find_biggest(current_b)) / 2;
	while (stack_size(current_b) >= stack_size(current_b) / 2)
	{
		if (current_b->nbr > pivot)
		{
			pa(&current_a, &current_b);
			ra(&current_a);
		}
		else	pb(&stack_a, &stack_b);

			pa(&current_a, &current_b);
	}
	pivot = find_biggest(current_b);
	while (current_b)
	{
		if (current_b->nbr != pivot)
			rb(&current_b);
		else
			pa(&current_a, &current_b);
	}
	stack_a = current_a;
	stack_b = current_b;
	return (stack_a);
} */

//ate a stack a estiver vazia 
//se o nbr for maior que o pivot, pb
//se o nbr for menor ou igual que o pivot, pb rb

//agora arranjo um pivot para o stack b metade de cima
//ate stack b estiver a metade
//se o nbr for maior que o pivot, pa ra
//se o nbr for menor ou igual que o pivot, pa

//arranjo um pivot com o maior valor de stack b
//ate stack b estiver vazia
//enquanto for diferente de do pivot que agora representa o maior valor de stack b
//faco rb senao faco pa


void	*sort(t_stack *stack_a, t_stack *stack_b)
{
	pb(&stack_a, &stack_b);
	pb(&stack_a, &stack_b);
	while (stack_size(stack_a) > 3)
		move_a_to_b(stack_a, stack_b);
	
	print_stack(stack_a, stack_b);
	if (!is_sorted(stack_a))
		stack_a = sort(stack_a, stack_b);
	return (stack_a);
}