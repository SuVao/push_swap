/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pesilva- <pesilva-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 11:24:42 by pesilva-          #+#    #+#             */
/*   Updated: 2024/06/14 17:44:09 by pesilva-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


int main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;
	t_stack	*tail;

	a = NULL;
	b = NULL;
	if (ac == 1 || (ac == 2 && !av[1][0]))
		return (-1);
	a = stackar_split(av);
	tail = tailer(a);
	print_stack(a);
	if (is_sorted(a))
		return (0);
	else if (stack_size(a) == 3)
	{
		printf("just to make sure\n");
		printf("index: %d\n", a->index);
		sort_3(a);
		printf("index: %d\n", a->index);
	}
	else if (stack_size(a) == 5)
		sort_5(a, b);
		
/* 	else
		sort_big(a, b); */
	/* printf("index: %d\n", a->index); */
	printf("other\n\n");

	while (tail)
	{
		printf("nbr: %d\n", tail->nbr);
		printf("index: %d\n", tail->index);
		tail = tail->next;
		// if (tmp->prev == NULL)
		// 	tmp = 
	}
	print_stack(a);
	return (0);
}