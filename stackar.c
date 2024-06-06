/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stackar.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pesilva- <pesilva-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 12:46:18 by pesilva-          #+#    #+#             */
/*   Updated: 2024/06/06 18:04:45 by pesilva-         ###   ########.fr       */
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
	new = malloc(sizeof(t_stack *) * (ac));
	if (!new)
		return (NULL);
	while (i < ac)
	{
		new[i] = malloc(sizeof(t_stack));
		if (!new[i])
		{
			while (i > 0)
				free(new[--i]);
			free(new);
			return (NULL);
		}
		new[i]->nbr = ft_atoi(av[i + 1]);
		new[i]->index = i;
		i++;
	}
	new[i] = NULL;
	return (new);
}

int	maior(t_stack **stack)
{
	int i;
	int	maior;
	
	i = 1;
	maior = 0;
	while (stack[i] != NULL)
	{
		if (stack[i]->nbr > maior)
			maior = stack[i]->nbr;
		i++;
	}
	return (maior);
}

int	menor(t_stack **stack)
{
	int	i;
	int	menor;

	i = 1;
	menor = stack[1]->nbr;
	while (stack[i])
	{
		if (stack[i]->nbr < menor)
			menor = stack[i]->nbr;
		i++;
	}
	return (menor);
}

int	check_nbr(t_stack **stack, int ac)
{
	int i;
	int	j;
	int k;

	i = 0;
	j = 1;
	k = 0;
	while (stack[i + 1] != NULL)
	{
		j = i + 1;
		while (stack[j])
		{
			if (stack[i]->nbr == stack[j]->nbr)
			{
				while (k < ac)
					free(stack[k++]);
				free(stack);
				printf("aqui a numero repetido!\n");
				exit(EXIT_FAILURE);
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

/* int main(int ac, char **av)
{
	t_stack	**new;
	int i = 0;
	if (ac >= 2)
	{
		new = stackar(ac - 1, av);
		if (!check_nbr(new, ac))
			return (0);
		while (new[i])
		{
			printf("valor: %d index: %d \n", new[i]->nbr, new[i]->index);
			free (new[i]);
			i++;
		}
		free(new);
	}
	else
		write(1, "\n", 1);
	return (0);
} */