/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pesilva- <pesilva-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 15:12:03 by pesilva-          #+#    #+#             */
/*   Updated: 2024/06/14 15:00:07 by pesilva-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_min(t_stack *stack)
{
	int		min;
	t_stack	*tmp;

	tmp = stack;
	min = tmp->nbr;
	while (tmp)
	{
		if (tmp->nbr < min)
			min = tmp->nbr;
		tmp = tmp->next;
	}
	return (min);
}

int	find_max(t_stack *stack)
{
	int		max;
	t_stack	*tmp;

	tmp = stack;
	max = tmp->nbr;
	while (tmp)
	{
		if (tmp->nbr > max)
			max = tmp->nbr;
		tmp = tmp->next;
	}
	return (max);
}

void	sort_5(t_stack *stack_a, t_stack *stack_b)
{
	int		i;
	int		min;
	int		max;

	i = 0;
	min = find_min(stack_a);
	max = find_max(stack_a);
	while (i < 2)
	{
		if (stack_a->nbr == min || stack_a->nbr == max)
			ra(&stack_a);
		else
			pb(&stack_a, &stack_b);
		i++;
	}
	sort_3(stack_a);
	pa(&stack_a, &stack_b);
	pa(&stack_a, &stack_b);

}