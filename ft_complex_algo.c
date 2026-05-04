/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_complex_algo.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: celgremy <celgremy@student.42belgium.be    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/02 17:02:34 by mgedeon           #+#    #+#             */
/*   Updated: 2026/05/04 14:56:42 by celgremy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	ft_sort_three_node(t_stack *a);

int	ft_find_best_path(t_stack *a)
{
	
}

void	ft_min_a_to_top(t_stack *a)
{
	t_node	*current;
	t_data	*data;

	current = a->head;
	while (data->index != 0)
	{
		data = (t_data *)current->content;
		if (data->index < a->size / 2)
			ra(a);
		else
			rra(a);
		current = current->next;
	}
}

void	ft_complex_algo(t_stack *a, t_stack *b)
{
	t_node	best;

	while (a->size > 3)
		pb(a, b);
	ft_sort_three_node(a);
	while (b->size > 0)
	{
		ft_update_pos(a);
		ft_update_pos(b);
		ft_calculate_cost(a, b);
		best = ft_find_best_path(a);
		ft_move_b_to_a(best, a, b);
	}
	ft_min_a_to_top(a);
}
