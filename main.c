/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pesilva- <pesilva-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 11:24:42 by pesilva-          #+#    #+#             */
/*   Updated: 2024/06/16 23:12:16 by pesilva-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*create_stack(int ac)
{
	t_stack	*new_node;
	
	while (ac)
	{
		new_node = malloc(sizeof(t_stack));
		if (!new_node)
			return (NULL);
		new_node->nbr = 0;
		new_node->index = 0;
		new_node->next = NULL;
		new_node->prev = NULL;
		ac--;
	}
	return (new_node);
}

t_stack	*add_nbr(t_stack *stack, int nbr, int index)
{
	t_stack	*new_node;

	new_node = malloc(sizeof(t_stack));
	if (!new_node)
		return (NULL);
	new_node->nbr = nbr;
	new_node->index = index;
	new_node->next = NULL;
	new_node->prev = stack;
	stack->next = new_node;
	return (stack);
}

t_stack	*fill_stack(t_stack *stack, char **av)
{
	int	i;
	int	nbr;
	
	i = 1;
	while (av[i])
	{
		nbr = ft_atoi(av[i]);
		stack = add_nbr(stack, nbr, i);
		i++;
	}
	return (stack);
}

/* int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;
	
	a = NULL;
	b = NULL;
	if (ac == 1 || (ac == 2 && !av[1][0]))
		return (-1);
	a = create_stack(ac - 1);
	if (!a)
		return (-1);
	a = fill_stack(a, av);
	print_stack(a);
	free_stack(a);
	free_stack(b);
	return (0);
} 
 */
 
int main(int ac, char **av)
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
	/* printf("============= Before ============ \n"); */
	print_stack(a);
	/* printf("========================== \n"); */
	if (!is_sorted(a))
		printf("stack is not sorted\n");
	else
		printf("stack is sorted\n");
	if (stack_size(a) == 3)
		a = sort_3(a);
	else if (stack_size(a) == 5)
		a = sort_5(a, b);
/* 	printf("+++++++++++++++++++++++ AFTER ================= \n\n"); */
	/* print_stack(a); */
	if (!is_sorted(a))
		printf("stack is not sorted\n");
	else
		printf("stack is sorted\n");
	free_stack(a);
	free_stack(b);
	return (0);
}