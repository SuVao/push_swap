/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stackar.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pesilva- <pesilva-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 12:46:18 by pesilva-          #+#    #+#             */
/*   Updated: 2024/06/12 14:29:45 by pesilva-         ###   ########.fr       */
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
	while (n[i] != '\0' && n[i] == ' ' && n[i] == '\n' && n[i] == '\t')
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

t_stack *stackar_split(char **av)
{
	int i;
	char **args;
	t_stack *head;
	t_stack *new_node;
	
	i = 0;
	head = NULL;
	while (*++av)
	{
		args = ft_split(*av);
		while (*args)
		{
			new_node = malloc(sizeof(t_stack));
			if (!new_node)
				return (NULL);
			new_node->nbr = ft_atoi(*args);
			new_node->index = i;
			new_node->next = head;
			head = new_node;
			i++;
			free(*args);
			args++;
		}
	}
	return (head);
}

/* int main(int ac, char **av)
{
	t_stack	*new;
	t_stack	*tmp;
	if (ac >=2)
	{
		new = stackar_split(av);
		while (new)
		{
			printf("%d\n", new->nbr);
			tmp = new;
			new = new->next;
			free(tmp);
		}
		free(new);
	}
} */