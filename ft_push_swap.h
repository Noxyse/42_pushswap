/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgedeon <mgedeon@student.42belgium.be>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/26 14:07:38 by mgedeon           #+#    #+#             */
/*   Updated: 2026/05/03 14:26:24 by mgedeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUSH_SWAP_H
# define FT_PUSH_SWAP_H

# include <stdlib.h>

// ------- STRUCTURES ------- //

typedef struct s_node
{
	void			*content;
	struct s_node	*next;
	struct s_node	*prev;
}					t_node;

typedef struct s_data
{
	int	value;
	int	index;
}		t_data;

typedef struct s_stack
{
	t_node	*head;
	t_node	*tail;
	int		size;
}			t_stack;

// ------- LIBFT ------- //

int		ft_strcmp(char *s1, char *s2);
int		ft_printf(const char *format, ...);

// ------- RULES ------- //

// ------- SWAP ------- //
void	sa(t_stack *stack_a);
void	sb(t_stack *stack_b);
void	ss(t_stack *stack_a, t_stack *stack_b);

// ------- PUSH ------- //
void	pa(t_stack *stack_a, t_stack *stack_b);
void	pb(t_stack *stack_a, t_stack *stack_b);

// ------- ROTATE ------- //
void	ra(t_stack *stack_a);
void	rb(t_stack *stack_b);
void	rr(t_stack *stack_a, t_stack *stack_b);
void	rra(t_stack *stack_a);
void	rrb(t_stack *stack_b);
void	rrr(t_stack *stack_a, t_stack *stack_b);

// ------- STACK MANIPULATION ------- //

t_node	*ft_stacknew(void *content);
t_node	*ft_stacklast(t_node *stack);
t_node	*ft_remove_head(t_node **stack);
t_node	*ft_remove_tail(t_node **stack);
void	ft_stackdelone(t_node *stack, void (*del)(void *));
void	ft_stackclear(t_node *stack, void (*del)(void *));
void	ft_stackadd_front(t_node **stack, t_node *new);
void	ft_stackadd_back(t_node **stack, t_node *new);

// ------- INDEXATION ------- //

void	ft_value_to_index(t_stack *stack);

// ------- PARSING ------- //

int		*ft_parse_to_int(char **s_str, int size, int *error);

// ------- ALGOS ------- //

void	ft_simple_algo(t_stack *a, t_stack *b);
void	ft_medium_algo(t_stack *stack_a, t_stack *stack_b);
void	ft_complex_algo(t_stack *a, t_stack *b);

// ------- MAIN ------- //

void	*ft_push_swap(int **stack_a, int nb_param, char *flags);

#endif