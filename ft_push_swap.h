/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgedeon <mgedeon@student.42belgium.be>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/26 14:07:38 by mgedeon           #+#    #+#             */
/*   Updated: 2026/05/02 16:00:12 by mgedeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUSH_SWAP_H	
# define FT_PUSH_SWAP_H	
# define NULL (void *) 0

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

static int	get_index(t_node *target_node, t_stack *stack);
void	ft_value_to_index(t_stack *stack);

// ------- PARSING ------- //

int	*ft_parse_to_int(char **s_str, int size, int *error);

// ------- SIMPLE ALGO ------- //

void	ft_simple_algo(t_stack **a, t_stack **b, int *error, int size);

// ------- MEDIUM ALGO ------- //

static int	ft_sqrt(int n);
static int	ft_ceil_sqrt(int n);
static void	sort_chunks(t_stack *a, t_stack *b, int chunk_min, int chunk_max);
void	ft_medium_algo(t_stack *stack_a, t_stack *stack_b);

// ------- MAIN ------- //

static void	ft_free_split(char **split);
static char	**ft_join_split(int size, char **tab, int *error, int *count);

#endif