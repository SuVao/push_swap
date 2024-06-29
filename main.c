/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pesilva- <pesilva-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 11:24:42 by pesilva-          #+#    #+#             */
/*   Updated: 2024/06/29 15:04:36 by pesilva-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	if (ac == 1 || (ac == 2 && !av[1][0]))
		return (-1);
	a = stackar_split(av);
	if (!nbr_check(av))
		return (-1);
	if (!check_nbr(a))
		return (-1);
	if (stack_size(a) == 3)
		sort_3(a);
	else if (stack_size(a) == 5)
		a = sort_5(a, b);
	else
		sort(&a, &b);
	if (is_sorted(a))
		write(1, "stack is sorted\n", 17);
	else
		write(1, "stack is not sorted\n", 21);
	// print_stack(a, b);
	free_stack(a);
	free_stack(b);
	// printf("size of A: %lu, size of B: %lu\n", sizeof(a), sizeof(b));
	// printf("size of t_stack: %lu\n", sizeof(t_stack));
	return (0);
}
