/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pesilva- <pesilva-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 11:24:42 by pesilva-          #+#    #+#             */
/*   Updated: 2024/06/12 17:19:16 by pesilva-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


int main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;
/* 	t_stack	*tmp; */

	a = NULL;
	b = NULL;
	if (ac == 1 || (ac == 2 && !av[1][0]))
		return (-1);
	a = stackar_split(av);
	/*tmp = a;
 	while (a)
	{
		printf("%d\n", a->nbr);
		a = a->next;
	} */
	if (is_sorted(a))
		return (0);
	else if (stack_size(a) <= 3)
		sort_3(a);
	else if (stack_size(a) <= 5)
		sort_5(a, b);
/* 	else
		sort_big(a, b); */
/* 	while (tmp)
	{
		printf("%d\n", tmp->nbr);
		tmp = tmp->next;
	} */
	return (0);
}