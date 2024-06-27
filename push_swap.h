/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pesilva- <pesilva-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 11:25:07 by pesilva-          #+#    #+#             */
/*   Updated: 2024/06/27 16:30:34 by pesilva-         ###   ########.fr       */
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

typedef struct s_data
{
	int	moves;
}	t_data;


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

void	sort_3(t_stack *stack_a);
void	*sort_5(t_stack *stack_a, t_stack *stack_b);
void	sort(t_stack **stack_a, t_stack **stack_b);

/*-------stack--------*/

t_stack	*stackar(int ac, char **av);
int		check_nbr(t_stack *stack);

char	**ft_split(char *s);
int		is_sorted(t_stack *stack);
void	free_stack(t_stack *stack_a);
int		stack_size(t_stack *stack);
t_stack	*stackar_split(char **av);
void	update_index(t_stack *source);
void	print_list(t_stack *stack);
void	print_stack(t_stack *stack_a, t_stack *stack_b);
void	ft_lstadd_back(t_stack **lst, t_stack *new);
void	print_lists(t_stack **a, t_stack **b);
void	printNodeDetail(t_stack *node);
int		ft_atoi(char *n);
int	nbr_check(char **str);
void free_split(char **split);
int find_biggest(t_stack *stack);
int	find_smallest(t_stack *stack);
int half_stack_small(t_stack *current, t_stack *stack);
int	is_the_small(int nbr, t_stack *stack);
int half_stack_big(t_stack **stacks);
void 		cheapest_b_to_a(t_stack **stack_a, t_stack **stack_b);
t_stack		*ft_thelast(t_stack *lst);
static void	making(t_stack *stack, t_stack *target, t_stack **a, t_stack **b);
t_stack *target_(int nbr, t_stack *stack_b);
int is_smaller(int nbr, t_stack *stack);

void	move_to_b(t_stack **stack_a, t_stack **stack_b, t_stack *target);
void	move_to_a(t_stack **stack_a, t_stack **stack_b, t_stack *target);
void	cheapest_b_to_a(t_stack **stack_a, t_stack **stack_b);
t_stack	*current_bigger(t_stack *stack);
int	calcula_moves(t_stack *current, t_stack *a, t_stack *b);
void	move_a_to_b(t_stack **stack_a, t_stack **stack_b);
t_stack	*smaller_node(t_stack *stack);
int the_lower_nbr(int a, int b);

#endif