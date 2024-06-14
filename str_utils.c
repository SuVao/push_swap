/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pesilva- <pesilva-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 11:50:39 by pesilva-          #+#    #+#             */
/*   Updated: 2024/06/14 15:00:47 by pesilva-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_blanc(char c)
{
	return (c == ' ' || c == '\n' || c == '\t');
}

static int	count_words(char *s)
{
	int i;
	
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



void	print_stack(t_stack *stack)
{
	t_stack *tmp;
	tmp = stack;
	while (tmp)
	{
		printf("%d\n", tmp->nbr);
		tmp = tmp->next;
	}
}


void	ft_lstadd_back(t_stack **lst, t_stack *new)
{
	t_stack	*tmp;

	if (!*lst)
	{
		*lst = new;
		return ;
	}
	tmp = *lst;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
}

t_stack	*ft_lstlast(t_stack *lst)
{
	t_stack	*tmp;

	tmp = lst;
	while (tmp->next)
		tmp = tmp->next;
	return (tmp);
}


void    print_lists(t_stack **a, t_stack **b)
{
    t_stack  *temp;
    t_stack  *tmp_next;
    t_stack  *tmp_prev;
    t_stack  *tmp_index;
    temp = *a;
    tmp_next = *a;
    tmp_prev = *a;
    tmp_index = *a;
    write(1, "\nLIST A\n", 8);
    while (temp != NULL)
    {
        printf("%i\n", temp->nbr);
        temp = temp->next;
    }
    temp = *b;
    write(1, "\nLIST B\n", 8);
    while (temp != NULL)
    {
        printf("%i\n", temp->nbr);
        temp = temp->next;
    }
    write(1, "\n\nLIST A - INDEX\n", 17);
    while (tmp_index != NULL)
    {
        printf("%i\n", tmp_index->index);
        tmp_index = tmp_index->next;
    }
    tmp_index = *b;
    write(1, "\n\nLIST B - INDEX\n", 17);
    while (tmp_index != NULL)
    {
        printf("%i\n", tmp_index->index);
        tmp_index = tmp_index->next;
    }
    write(1, "\n\nLIST A - PREV\n", 16);
    while (tmp_prev != NULL)
    {
        printf("%p\n", tmp_prev->prev);
        tmp_prev = tmp_prev->next;
    }
    tmp_prev = *b;
    write(1, "\n\nLIST B - PREV\n", 16);
    while (tmp_prev != NULL)
    {
        printf("%p\n", tmp_prev->prev);
        tmp_prev = tmp_prev->next;
    }
    write(1, "\n\nLIST A - NEXT\n", 16);
    while (tmp_next != NULL)
    {
        printf("%p\n", tmp_next->next);
        tmp_next = tmp_next->next;
    }
    tmp_next = *b;
    write(1, "\n\nLIST B - NEXT\n", 16);
    while (tmp_next != NULL)
    {
        printf("%p\n", tmp_next->next);
        tmp_next = tmp_next->next;
    }
}