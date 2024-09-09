/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stackar.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pesilva- <pesilva-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 12:46:18 by pesilva-          #+#    #+#             */
/*   Updated: 2024/09/07 18:02:04 by pesilva-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	check_sign(t_stack *a, char c)
{
	if (!ft_isdigit(c) && c != '\0')
	{
		a->error_nbr = 1;
		return (1);
	}
	return (0);
}

long	ft_atol(char *n, t_stack *node)
{
	int		i;
	int		sign;
	long	res;

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
	if (check_sign(node, n[i]) == 1)
		return (0);
	while (n[i] >= '0' && n[i] <= '9')
		res = res * 10 + (n[i++] - '0');
	if (check_sign(node, n[i]) == 1)
		return (0);
	return (res * sign);
}

t_stack	*stackar_split(char **av)
{
	t_stack	*head;
	t_stack	*new_node;
	t_stack	*tail;
	int		i;

	head = NULL;
	tail = NULL;
	i = 0;
	while (*++av)
	{
		new_node = malloc(sizeof(t_stack));
		if (!new_node)
			return (NULL);
		new_node->error_nbr = 0;
		new_node->nbr = ft_atol(*av, new_node);
		new_node->index = i++;
		new_node->next = NULL;
		new_node->prev = tail;
		if (!head)
			head = new_node;
		if (tail)
			tail->next = new_node;
		tail = new_node;
	}
	return (head);
}

t_stack	*fullfill(char *av, t_stack *new_node, t_stack *tail)
{
	new_node->error_nbr = 0;
	new_node->nbr = ft_atol(av, new_node);
	new_node->next = NULL;
	new_node->prev = tail;
	return (new_node);
}

t_stack	*stackar_split2(char **av)
{
	t_stack	*head;
	t_stack	*new_node;
	t_stack	*tail;
	int		i;

	head = NULL;
	tail = NULL;
	i = 0;
	while (*av)
	{
		new_node = malloc(sizeof(t_stack));
		if (!new_node)
			return (NULL);
		new_node = fullfill(*av, new_node, tail);
		new_node->index = i++;
		if (!head)
			head = new_node;
		if (tail)
			tail->next = new_node;
		tail = new_node;
		av++;
	}
	return (head);
}
