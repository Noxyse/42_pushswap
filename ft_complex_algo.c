/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_complex_algo.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: celgremy <celgremy@student.42belgium.be    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/02 17:02:34 by mgedeon           #+#    #+#             */
/*   Updated: 2026/05/03 17:03:11 by celgremy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	ft_sort_three_node(t_stack *a);

void	ft_complex_algo(t_stack *a, t_stack *b)
{
	t_node	lsd;

	if (a->size > 5)
	{
		pb(a, b);
		pb(a, b);
	}
	while (a->size > 3)
	{
		ft_update_stack(a, b);
		ft_check_move(a, b);
		lsd = ft_find_best_path(a);
		ft_move_a_to_b(lsd, a, b);
	}
	ft_sort_three_node(a);
	while (b->size > 0)
	{
		ft_update_stack(a, b);
		ft_setup_a(a, b->head);
		pa(a, b);
	}
	ft_min_a_to_top(a);
}
