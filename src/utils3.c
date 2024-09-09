/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pesilva- <pesilva-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 14:18:39 by pesilva-          #+#    #+#             */
/*   Updated: 2024/09/09 18:28:36 by pesilva-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

//this function see which number is the smaller
int	find_smallest(t_stack *stack)
{
	int		smallest;
	t_stack	*current;

	current = stack;
	smallest = current->nbr;
	while (current)
	{
		if (current->nbr < smallest)
			smallest = current->nbr;
		current = current->next;
	}
	return (smallest);
}

int	its_par(int nbr)
{
	if (nbr % 2 == 0)
		return (0);
	else
		return (1);
}

int	looking_flag(t_stack *a)
{
	t_stack	*tmp;

	tmp = a;
	while (tmp)
	{
		if (tmp->error_nbr == 1)
			return (1);
		tmp = tmp->next;
	}
	return (0);
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

int	check_max(t_stack *a)
{
	t_stack	*tmp;

	tmp = a;
	while (tmp)
	{
		if (tmp->nbr > 2147483647 || tmp->nbr < -2147483648)
		{
			write(2, "Error\n", 7);
			return (0);
		}
		tmp = tmp->next;
	}
	return (1);
}
