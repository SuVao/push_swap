/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pesilva- <pesilva-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 11:24:42 by pesilva-          #+#    #+#             */
/*   Updated: 2024/09/09 18:24:17 by pesilva-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	stack_2(t_stack **stack_a)
{
	if ((*stack_a)->nbr > (*stack_a)->next->nbr)
		sa(*stack_a);
	else
		return ;
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
		write(2, "Error\n", 26);
		free_stack(a);
		return (0);
	}
	else if (!check_max(a))
		a->error_nbr = 1;
	else if (check_nbr(a) == 0)
		a->error_nbr = 1;
	else if (is_sorted(a))
		a->error_nbr = 1;
	if (looking_flag(a) == 1)
	{
		free_stack(a);
		return (0);
	}
	return (1);
}

static int	split_checks(char **av, t_stack **a)
{
	av = ft_split1(av[0]);
	*a = stackar_split2(av);
	if (checks(*a, av) == 0)
	{
		free_split(av);
		return (0);
	}
	free_split(av);
	return (1);
}

static void	sort_stack(t_stack **a, t_stack **b)
{
	if (stack_size(*a) == 2)
		stack_2(a);
	else if (stack_size(*a) == 3)
		sort_3(a);
	else if (stack_size(*a) == 4)
		sort_4(a, b);
	else
		sort(a, b);
}

//checking if it is all numbers and not repeated
//cheking the size and choosing the algoritm to follow
int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	if (ac == 1 || (ac == 2 && !valid_string(av[1])))
		return (0);
	if (ac == 2)
	{
		if (split_checks(&av[1], &a) == 0)
			return (0);
		sort_stack(&a, &b);
	}
	if (ac > 2)
	{
		a = stackar_split(av);
		if (checks(a, av) == 0)
			return (0);
		sort_stack(&a, &b);
	}
	free_stack(a);
	free_stack(b);
	return (0);
}
