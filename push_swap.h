/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pesilva- <pesilva-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 11:25:07 by pesilva-          #+#    #+#             */
/*   Updated: 2024/07/03 20:23:53 by pesilva-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

#define	INT_MAX 2147483647
#define	INT_MIN -2147483648

typedef struct s_stack
{
	struct s_stack	*next;
	struct s_stack	*prev;
	long				nbr;
	int				index;
}				t_stack;

typedef struct s_data
{
	int	moves;
}	t_data;

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

long int	ft_atol(char *n);
void		update_index(t_stack *source);
void		print_stack(t_stack *stack_a, t_stack *stack_b);
int			nbr_check(char **str);

/*-------stack--------*/

t_stack	*target_(int nbr, t_stack *stack_b);
t_stack	*stackar_split(char **av);
t_stack	*ft_thelast(t_stack *lst);
t_stack	*current_bigger(t_stack *stack);
t_stack	*smaller_node(t_stack *stack);
void	ft_lstadd_back(t_stack **lst, t_stack *new);
void	move_to_b(t_stack **stack_a, t_stack **stack_b, t_stack *target);
void	move_a_to_b(t_stack **stack_a, t_stack **stack_b);
char	**ft_split(char *s);
int		stack_size(t_stack *stack);
int		find_biggest(t_stack *stack);
int		find_smallest(t_stack *stack);
int		half_stack_small(t_stack *current, t_stack *stack);
int		is_the_small(int nbr, t_stack *stack);
int		is_smaller(int nbr, t_stack *stack);
int		calcula_moves(t_stack *current, t_stack *a, t_stack *b);
int		the_lower_nbr(int a, int b);
int		its_par(int nbr);

#endif