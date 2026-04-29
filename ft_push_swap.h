/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgedeon <mgedeon@student.42belgium.be>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/26 14:07:38 by mgedeon           #+#    #+#             */
/*   Updated: 2026/04/29 10:00:19 by mgedeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUSH_SWAP_H	
# define FT_PUSH_SWAP_H	

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

t_node	*stacknew(void *content);
t_node	*stacklast(t_node *stack);
t_node	*remove_head(t_node **stack);
t_node	*remove_tail(t_node **stack);
void	stackdelone(t_node *stack, void (*del)(void *));
void	stackadd_front(t_node **stack, t_node *new);
void	stackadd_back(t_node **stack, t_node *new);

#endif