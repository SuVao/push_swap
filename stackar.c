/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stackar.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pesilva- <pesilva-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 12:46:18 by pesilva-          #+#    #+#             */
/*   Updated: 2024/06/01 16:04:10 by pesilva-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int ft_atoi(char *n)
{
	int i;
	int sign;
	int res;

	res = 0;
	sign = 1;
	i = 0;
	while (n[i] != '\0' && n[i] <= 32)
		i++;
	if (n[i] == '-' || n[i] == '+')
	{
		if (n[i] == '-')
			sign *= -1;
		i++;
	}
	while (n[i] >= '0' && n[i] <= '9')
	{
		res = res * 10 + (n[i] - '0');
		i++;
	}
	return (res * sign);
}

t_stack **stackar(int ac, char **av)
{
	int i;
	t_stack **new;

	i = 0;
	new = malloc(sizeof(t_stack *) * (ac - 1));
	while (av[i] != NULL)
	{
		new[i] = malloc(sizeof(t_stack));
		new[i]->nbr = ft_atoi(av[i]);
		new[i]->index = i;
		i++;
	}
	return (new);
}

/* 
int main(int ac, char **av)
{
	t_stack	**new;
	int i = 1;static int stack_size(t_stack *stack_a)
{
	int i;

	
	if (!stack_a)
		return (0);
	i = 0;
	while (stack_a != NULL)
	{
		stack_a = stack_a->next;
		i++;
	}
	return (i);
}

	if (ac >= 2)
	{
		new = stackar(ac - 1, av);
		while (new[i])
		{
			printf("valor: %d index: %d \n", new[i]->nbr, new[i]->index);
			i++;
		}
		printf("tamanho da lista: %d \n", stack_size(new));
	}
	else
		write(1, "\n", 1);
	return (0);
} */