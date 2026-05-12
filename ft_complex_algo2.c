/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_complex_algo2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: celgremy <celgremy@student.42belgium.be    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/10 16:44:35 by celgremy          #+#    #+#             */
/*   Updated: 2026/05/12 11:32:30 by celgremy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	ft_abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

void	ft_calculate_cost(t_stack *a, t_stack *b)
{
	t_node	*curr;
	t_data	*db;
	int		curr_a;
	int		curr_b;

	curr = b->head;
	while (curr)
	{
		db = (t_data *)curr->content;
		curr_b = db->pos;
		if (db->pos > b->size / 2)
			curr_b = db->pos - b->size;
		curr_a = ((t_data *)db->target->content)->pos;
		if (curr_a > a->size / 2)
			curr_a = curr_a - a->size;
		db->push_cost = ft_abs(curr_a) + ft_abs(curr_b);
		if ((curr_a > 0 && curr_b > 0) || (curr_a < 0 && curr_b < 0))
		{
			if (ft_abs(curr_a) > ft_abs(curr_b))
				db->push_cost -= ft_abs(curr_b);
			else
				db->push_cost -= ft_abs(curr_a);
		}
		curr = curr->next;
	}
}

t_node	*ft_find_best_path(t_stack *b)
{
	t_node	*curr;
	t_node	*best;
	long	min_cost;

	curr = b->head;
	best = NULL;
	min_cost = LONG_MAX;
	while (curr)
	{
		if (((t_data *)curr->content)->push_cost < min_cost)
		{
			min_cost = ((t_data *)curr->content)->push_cost;
			best = curr;
		}
		curr = curr->next;
	}
	return (best);
}