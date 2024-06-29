/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pesilva- <pesilva-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 11:50:39 by pesilva-          #+#    #+#             */
/*   Updated: 2024/06/28 15:27:25 by pesilva-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_blanc(char c)
{
	return (c == ' ' || c == '\n' || c == '\t');
}

static int	count_words(char *s)
{
	int	i;

	i = 0;
	while (*s)
	{
		while (*s && is_blanc(*s))
			s++;
		if (*s && !is_blanc(*s))
		{
			i++;
			while (*s && !is_blanc(*s))
				s++;
		}
	}
	return (i);
}

static char	*aloc(char *s)
{
	int		i;
	char	*word;

	i = 0;
	while (s[i] && !is_blanc(s[i]))
		i++;
	word = malloc(sizeof(char) * (i + 1));
	if (!word)
		return (NULL);
	i = 0;
	while (s[i] && !is_blanc(s[i]))
	{
		word[i] = s[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

char	**ft_split(char *s)
{
	int		i;
	char	**mat;

	if (!s)
		return (NULL);
	mat = malloc(sizeof(char *) * (count_words(s) + 1));
	if (!mat)
		return (NULL);
	i = 0;
	while (*s)
	{
		while (*s && is_blanc(*s))
			s++;
		if (*s && !is_blanc(*s))
		{
			mat[i] = aloc(s);
			i++;
			while (*s && !is_blanc(*s))
				s++;
		}
	}
	mat[i] = NULL;
	return (mat);
}

int	the_lower_nbr(int a, int b)
{
	if (a < b)
		return (a);
	else if (a > b)
		return (b);
	else
		return (0);
}

void	print_stack(t_stack *stack_a, t_stack *stack_b)
{
	t_stack	*tmp1;
	t_stack	*tmp2;
	
	tmp1 = stack_a;
	tmp2 = stack_b;
	printf("\n");
	while (tmp1)
	{
		printf("%i\tindex:%i\n", tmp1->nbr, tmp1->index);
		tmp1 = tmp1->next;
	}
	printf("\nA\n\n");
	while (tmp2)
	{
		printf("%i\tindex:%i\n", tmp2->nbr, tmp2->index);
		tmp2 = tmp2->next;
	}
	printf("\nB\n\n");
}
