/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stackar.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pesilva- <pesilva-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 12:46:18 by pesilva-          #+#    #+#             */
/*   Updated: 2024/06/14 17:42:56 by pesilva-         ###   ########.fr       */
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
	t_stack *tail;
	
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
			printf("prev: %p\n", new_node->prev);
			head = new_node;
			if (i == 0)
			{
				new_node->prev = NULL;
				tail = new_node;
			}
			else
				new_node->prev = head;
			i++;
			free(*args);
			args++;
		}
	}
	return (head);
}

t_stack		*tailer(t_stack *stack)
{
	t_stack	*tail;
	
	tail = stack;
	while (stack)
		stack = stack->next;
	return (tail);
}

t_stack	*rev_list(t_stack **stack)
{
	t_stack	*tmp;
	
	tmp = *stack;
	while (tmp != NULL)
		tmp = tmp->prev;
	stack = &tmp;
	return (*stack);
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