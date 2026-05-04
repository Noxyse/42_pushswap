/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_complex_algo.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: celgremy <celgremy@student.42belgium.be    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/02 17:02:34 by mgedeon           #+#    #+#             */
/*   Updated: 2026/05/04 13:34:44 by celgremy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	ft_sort_three_node(t_stack *a);

void	ft_complex_algo(t_stack *a, t_stack *b)
{
	t_node	best;

	while (a->size > 3)
		pb(a, b);
	ft_sort_three_node(a);
	while (b->size > 0)
	{
		ft_update_stack(a, b);
		ft_check_move(a, b);
		best = ft_find_best_path(a);
		ft_move_b_to_a(best, a, b);
	}
	ft_min_a_to_top(a);
}
