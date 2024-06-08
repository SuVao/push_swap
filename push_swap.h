/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pesilva- <pesilva-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 11:25:07 by pesilva-          #+#    #+#             */
/*   Updated: 2024/06/08 14:17:21 by pesilva-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

typedef	struct s_stack
{
	int				nbr;
	int				index;
	struct s_stack	*next;
}				t_stack;

/*--------acoes-------*/

void	pa(t_stack **stack_a, t_stack **stack_b);
void	pb(t_stack **stack_a, t_stack **stack_b);
void	rra(t_stack **stack_a);
void	rrb(t_stack **stack_b);
void	rrr(t_stack **stack_a, t_stack **stack_b);
void	ra(t_stack **stack_a);
void	rb(t_stack **stack_b);
void	rr(t_stack **stack_a, t_stack **stack_b);
void	sa(t_stack **stack_a);
void	sb(t_stack **stack_b);
void	ss(t_stack **stack_a, t_stack **stack_b);

/*--------sort-------*/

void	sort_3(t_stack **stack_a);
void	sort_5(t_stack **stack_a, t_stack **stack_b);
void	sort_big(t_stack **stack_a, t_stack **stack_b);

/*-------stack--------*/

t_stack	**stackar(int ac, char **av);
int		check_nbr(t_stack **stack, int ac);
int		menor(t_stack **stack);
int		maior(t_stack **stack);

char	**ft_split(char *s);
int	s_sorted(t_stack **stack);
void free_stack(t_stack **stack_a);
int	stack_size(t_stack **stack);
t_stack	**stackar_normal(int ac, char **av);
t_stack	**stackar_split(int ac, char **av);

#endif