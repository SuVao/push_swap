/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pesilva- <pesilva-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 11:24:42 by pesilva-          #+#    #+#             */
/*   Updated: 2024/06/08 14:44:34 by pesilva-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* int main(int ac, char **av)
{
	if (ac == 4)
		return (sort_3);
	else if (ac == 6)
		return (sort_5);
	else if (ac >= 7)
		return (sort_big);
	else
		return (0);
} */

int main(int ac, char **av)
{
	t_stack	**a;
	t_stack	**b;

	a = NULL;
	b = NULL;
	if (ac == 1 || (ac == 2 && !av[1][0]))
		return (-1);
	else if (ac == 2)
		a = stackar_split(ac, ft_split(av[1]));
	else
		a = stackar_normal(ac - 1, av);
	/* int i = 0;
	while (a[i])
	{
		printf("%d\n", a[i]->nbr);
		free (a[i++]);
	}
	free (a); */
/* 	check(a) */
	if (s_sorted(a))
	{
		if (stack_size(a) == 2)
			sa(a);
		else if (stack_size(a) == 3)
			sort_3(a);
		else if (stack_size(a) == 5)
			sort_5(a, b);
/* 		else
			sort_big(a, b); */
	}
	else
		printf("ja esta sorted");
/* 	free_stack(a); */
	return (0);
}