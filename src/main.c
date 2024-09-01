/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pesilva- <pesilva-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 11:24:42 by pesilva-          #+#    #+#             */
/*   Updated: 2024/09/01 18:02:15 by pesilva-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	stack_2(t_stack **stack_a)
{
	if ((*stack_a)->nbr > (*stack_a)->next->nbr)
	{
		sa(*stack_a);
		return (1);
	}
	return (0);
}

static int	check_max(t_stack *a)
{
	t_stack	*tmp;

	tmp = a;
	while (tmp)
	{
		if (tmp->nbr > 2147483647 || tmp->nbr < -2147483648)
		{
			write(1, "Invalid number detected!\n", 26);
			return (0);
		}
		tmp = tmp->next;
	}
	return (1);
}

static int	checks(t_stack *a, char **av)
{
	if (nbr_check(av) == 1)
	{
		free_stack(a);
		return (0);
	}
	if (looking_flag(a) == 1)
	{
		write(1, "Invalid number detected!\n", 26);
		free_stack(a);
		return (0);
	}
	else if (!check_max(a))
		a->error_nbr = 1;
	else if (is_sorted(a))
		a->error_nbr = 1;
	else if (check_nbr(a) == 0)
		a->error_nbr = 1;
	if (looking_flag(a) == 1)
	{
		free_stack(a);
		return (0);
	}
	return (1);
}

//checking if it is all numbers and not repeated
//cheking the size and choosing the algoritm to follow
int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	if (ac == 1 || (ac == 2 && !av[1][0]))
		return (0);
	a = stackar_split(av);
	if (checks(a, av) == 0)
		return (0);
	if (stack_size(a) == 2)
		stack_2(&a);
	if (stack_size(a) == 3)
		sort_3(&a);
	else if (stack_size(a) == 4)
		sort_4(&a, &b);
	else
		sort(&a, &b);
	free_stack(a);
	free_stack(b);
	return (0);
}
