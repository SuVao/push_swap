/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pesilva- <pesilva-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 17:05:46 by pesilva-          #+#    #+#             */
/*   Updated: 2024/06/01 16:13:59 by pesilva-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int stack_size(t_stack **stack_a)
{
	int i;
	
	if (!stack_a)
		return (0);
	i = 0;
	while (stack_a[i] != NULL)
	{
		stack_a[i] = stack_a[i]->next;
		i++;
	}
	return (i - 1);
}

/* void	sort_big(t_stack **stack_a, t_stack **stack_b)
{
	int		*array;
	int		i;
	int		size;

	size = stack_size(*stack_a);
	array = malloc(sizeof(int) * size);
	if (!array)
		return ;
	i = 0;
	while (i < size)
	{
		array[i] = (*stack_a)->nbr;
		ra(stack_a);
		i++;
	}
	i = 0;
	while (i < size)
	{
		pb(stack_a, stack_b);
		i++;
	}
	free(array);
} */

void	big_sort(int ac, char **av)
{
	int	i;
	t_stack	**stack_a;
	t_stack	**stack_b;
	
	i = 0;
	stack_a = stackar(ac, av);
	
}