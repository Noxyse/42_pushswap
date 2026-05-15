/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_complex_algo3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgedeon <mgedeon@student.42belgium.be>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/12 13:28:15 by celgremy          #+#    #+#             */
/*   Updated: 2026/05/15 16:37:18 by mgedeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	ft_ra_rb(t_stack *a, t_stack *b, int cost_a, int cost_b, t_bench *bench)
{
	while (cost_a > 0)
	{
		ra(a, bench);
		cost_a--;
	}
	while (cost_a < 0)
	{
		rra(a, bench);
		cost_a++;
	}
	while (cost_b > 0)
	{
		rb(b, bench);
		cost_b--;
	}
	while (cost_b < 0)
	{
		rrb(b, bench);
		cost_b++;
	}
}

void	ft_move_b_to_a(t_node *best, t_stack *a, t_stack *b, t_bench *bench)
{
	int	cost_a;
	int	cost_b;

	cost_b = ((t_data *)best->content)->pos;
	if (cost_b > (b->size + 1) / 2)
		cost_b -= b->size;
	cost_a = ((t_data *)((t_data *)best->content)->target->content)->pos;
	if (cost_a > (a->size + 1) / 2)
		cost_a -= a->size;
	while (cost_a > 0 && cost_b > 0)
	{
		rr(a, b, bench);
		cost_a--;
		cost_b--;
	}
	while (cost_a < 0 && cost_b < 0)
	{
		rrr(a, b, bench);
		cost_a++;
		cost_b++;
	}
	ft_ra_rb(a, b, cost_a, cost_b);
	pa(a, b, bench);
}
