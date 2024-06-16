/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkagem.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pesilva- <pesilva-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 15:58:21 by pesilva-          #+#    #+#             */
/*   Updated: 2024/06/16 13:39:08 by pesilva-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_stack *a)
{
	t_stack	*tmp;

	tmp = a;
	while (tmp && tmp->next)
	{
		if (tmp->nbr > tmp->next->nbr)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

static int ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

int	nbr_check(char **str)
{
	int	i;
	int j;

	i = 1;
	j = 0;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			if (!ft_isdigit(str[i][j]) && str[i][j] != '-' && str[i][j] != '+')
			{
				printf("Charater detected!\n");
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	check_nbr(t_stack *a)
{
	t_stack	*tmp;
	t_stack	*tmp2;

	tmp = a;
	while (tmp)
	{
		tmp2 = tmp->next;
		while (tmp2)
		{
			if (tmp->nbr == tmp2->nbr)
			{
				printf("Numero repetido!\n");
				return (0);
			}
			tmp2 = tmp2->next;
		}
		tmp = tmp->next;
	}
	return (1);
}

int	stack_size(t_stack *a)
{
	int		count;
	t_stack	*tmp;
	
	count = 0;
	tmp = a;
	while (tmp)
	{
		count++;
		tmp = tmp->next;
	}
	return (count);
}

void printNodeDetail(t_stack *node)
{
	if(!node)
	{
		printf("The pointer is null!\n");
		return ;
	}

	printf("================ NODE ==================\n");
	printf("Number: %d\n", node->nbr);
	printf("Index: %d\n", node->index);
	printf("Next Ptr: %p\n", node->next);
	printf("Prev Ptr: %p\n", node->prev);
	
	
}

void	update_index(t_stack *source)
{
	int		index;
	t_stack	*tmp;

	tmp = source;
	index = 1;
	while (tmp)
	{
		tmp->index = index;
		tmp = tmp->next;
		index++;
	}
}
