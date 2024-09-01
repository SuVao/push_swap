/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stackar.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pesilva- <pesilva-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 12:46:18 by pesilva-          #+#    #+#             */
/*   Updated: 2024/09/01 17:41:06 by pesilva-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_sign(t_stack *a, char c)
{
	if (!ft_isdigit(c) && c != '\0')
	{
		a->error_nbr = 1;
		return (1);
	}
	return (0);
}

long	ft_atoi(char *n, t_stack *node)
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
		new_node->nbr = ft_atoi(*av, new_node);
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

void	ft_lstadd_front(t_stack **lst, t_stack *new)
{
	new->next = *lst;
	*lst = new;
}

t_stack	*ft_thelast(t_stack *lst)
{
	t_stack	*last;

	last = NULL;
	if (!lst)
		return (NULL);
	while (lst)
	{
		if (lst->next == NULL)
		{
			last = lst;
			return (last);
		}
		lst = lst->next;
	}
	return (last);
}
