/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgedeon <mgedeon@student.42belgium.be>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/26 14:07:38 by mgedeon           #+#    #+#             */
/*   Updated: 2026/04/29 12:06:17 by mgedeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUSH_SWAP_H	
# define FT_PUSH_SWAP_H	
# define NULL (void *) 0

// ------- STRUCT ------- //

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

// ------- HELPERS ------- //

t_node	*ft_stacknew(void *content);
t_node	*ft_stacklast(t_node *stack);
t_node	*ft_remove_head(t_node **stack);
t_node	*ft_remove_tail(t_node **stack);
void	ft_stackdelone(t_node *stack, void (*del)(void *));
void	ft_stackadd_front(t_node **stack, t_node *new);
void	ft_stackadd_back(t_node **stack, t_node *new);

#endif