/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pesilva- <pesilva-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 11:50:39 by pesilva-          #+#    #+#             */
/*   Updated: 2024/06/06 12:24:37 by pesilva-         ###   ########.fr       */
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

/* int main(int ac, char **av)
{
	if (ac == 2)
	{
		int i = 0;
		char **mat;
		mat = ft_split(av[1]);
		while (mat[i])
		{
			printf("%s \n", mat[i]);
			free(mat[i++]);
		}
		free(mat);
	}
	write(1, "\n", 1);
} */