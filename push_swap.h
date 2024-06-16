/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pesilva- <pesilva-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 11:25:07 by pesilva-          #+#    #+#             */
/*   Updated: 2024/06/16 22:40:10 by pesilva-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
/* # include "../libft/libft.h" */

typedef	struct s_stack
{
	int				nbr;
	int				index;
	struct s_stack	*next;
	struct s_stack	*prev;
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
void	sa(t_stack *stack_a);
void	sb(t_stack *stack_b);
void	ss(t_stack *stack_a, t_stack *stack_b);

/*--------sort-------*/

void	*sort_3(t_stack *stack_a);
void	*sort_5(t_stack *stack_a, t_stack *stack_b);
void	sort_big(t_stack *stack_a, t_stack *stack_b);

/*-------stack--------*/

t_stack	*stackar(int ac, char **av);
int		check_nbr(t_stack *stack);
int		menor(t_stack *stack);
int		maior(t_stack *stack);

char	**ft_split(char *s);
int		is_sorted(t_stack *stack);
void	free_stack(t_stack *stack_a);
int		stack_size(t_stack *stack);
t_stack	*stackar_split(char **av);
void	update_index(t_stack *source);
void	print_list(t_stack *stack);
void	print_stack(t_stack *stack);
void	ft_lstadd_back(t_stack **lst, t_stack *new);
t_stack	*ft_lstlast(t_stack *lst);
void	print_lists(t_stack **a, t_stack **b);
void	printNodeDetail(t_stack *node);
int		ft_atoi(char *n);
void	ft_lstadd_front(t_stack **lst, t_stack *new);
int	nbr_check(char **str);
void free_split(char **split);

#endif