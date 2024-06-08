/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pesilva- <pesilva-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 17:06:41 by pesilva-          #+#    #+#             */
/*   Updated: 2024/06/08 14:49:51 by pesilva-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_3(t_stack **stack_a)
{
	int		a;
	int		b;
	int		c;
	
	a = (*stack_a)->nbr;
	b = (*stack_a)->next->nbr;
	c = (*stack_a)->next->next->nbr;
	if (a > b && b < c && a < c)
		sa(stack_a);
	else if (a > b && b > c)
	{
		sa(stack_a);
		rra(stack_a);
	}
	else if (a > b && a > c && b < c)
		ra(stack_a);
	else if (a < b && b > c && a < c)
		sa(stack_a);
	else if (a < b && b > c && a > c)
		rra(stack_a);
}

int main()
{
	t_stack	**a;
	
	a = NULL;
	printf("a\n");
	(*a)->nbr = 2;
	(*a)->next->nbr = 5;
	(*a)->next->next->nbr = 1;
	
	sort_3(a);
	
}