/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pesilva- <pesilva-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 11:25:07 by pesilva-          #+#    #+#             */
/*   Updated: 2024/09/09 17:30:45 by pesilva-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include "../libs/Libft/libft.h"

typedef struct s_stack
{
	struct s_stack	*next;
	struct s_stack	*prev;
	long			nbr;
	int				index;
	int				error_nbr;
}				t_stack;

/*-------------move fuctions----------------*/

//pushing
void	pa(t_stack **stack_a, t_stack **stack_b);
void	pb(t_stack **stack_a, t_stack **stack_b);

//reverse rotate
void	rra(t_stack **stack_a);
void	rrb(t_stack **stack_b);
void	rrr(t_stack **stack_a, t_stack **stack_b);

//rotate
void	ra(t_stack **stack_a);
void	rb(t_stack **stack_b);
void	rr(t_stack **stack_a, t_stack **stack_b);

//swap
void	sa(t_stack *stack_a);
void	sb(t_stack *stack_b);
void	ss(t_stack *stack_a, t_stack *stack_b);

/*--------sort-------*/

void	sort_3(t_stack **stack_a);
void	sort_4(t_stack **stack_a, t_stack **stack_b);
void	sort(t_stack **stack_a, t_stack **stack_b);

/*-------checks-------*/

void	free_stack(t_stack *stack_a);
int		check_nbr(t_stack *stack);
int		is_sorted(t_stack *stack);

/*-------utils--------*/

void	update_index(t_stack *source);
/* void	print_stack(t_stack *stack_a, t_stack *stack_b); */
long	ft_atol(char *n, t_stack *node);
int		nbr_check(char **str);

/*-------stack--------*/

t_stack	*target_(int nbr, t_stack *stack_b);
t_stack	*stackar_split(char **av);
t_stack	*ft_thelast(t_stack *lst);
t_stack	*current_bigger(t_stack *stack);
t_stack	*smaller_node(t_stack *stack);
void	move_to_b(t_stack **stack_a, t_stack **stack_b, t_stack *target);
void	move_a_to_b(t_stack **stack_a, t_stack **stack_b);
char	**ft_split1(char *s);
int		stack_size(t_stack *stack);
int		find_biggest(t_stack *stack);
int		find_smallest(t_stack *stack);
int		half_stack_small(t_stack *current, t_stack *stack);
int		is_smaller(int nbr, t_stack *stack);
int		calcula_moves(t_stack *current, t_stack *a, t_stack *b);
int		the_lower_nbr(int a, int b);
int		its_par(int nbr);
int		looking_flag(t_stack *a);
int		ft_isdigit(int c);
t_stack	*stackar_split2(char **av);
void	free_split(char **av);
int		check_max(t_stack *a);
int		valid_string(char *s);

#endif