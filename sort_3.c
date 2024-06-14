/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pesilva- <pesilva-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 17:06:41 by pesilva-          #+#    #+#             */
/*   Updated: 2024/06/14 16:00:55 by pesilva-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_3(t_stack *stack_a)
{
	int		a;
	int		b;
	int		c;
	
	a = stack_a->nbr;
	b = stack_a->next->nbr;
	c = stack_a->next->next->nbr;
	printf("a: %d\nb: %d\nc: %d\n", a, b, c);
	if (a > b && a > c && c > b)
		ra(&stack_a);
	else if (a > b && a > c && b > c)
		sa(stack_a);
	else if (b > a && b > c && a > c)
	{
		ra(&stack_a);
		sa(stack_a);
	}
	else if (b > a && b > c && c > a)
		rra(&stack_a);
	else if (c > a && c > b && a > b)
	{
		sa(stack_a);
		ra(&stack_a);
	}
	else if (c > a && c > b && b > a)
		rra(&stack_a);
}

/* int main()
{
	t_stack	*a;

	a = NULL;
	a->nbr = 3;
	a->next->nbr = 5;
	a->next->next->nbr = 1;

	while (a->next)
	{
		printf("%d\n", a->nbr);
		a = a->next;
	}
	return (0);
} */