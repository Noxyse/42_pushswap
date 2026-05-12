/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_complex_algo2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: celgremy <celgremy@student.42belgium.be    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/10 16:44:35 by celgremy          #+#    #+#             */
/*   Updated: 2026/05/12 11:17:26 by celgremy         ###   ########.fr       */
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
	int		current_a;
	int		current_b;

	curr = b->head;
	while (curr)
	{
		db = (t_data *)curr->content;
		current_b = db->pos;
		if (db->pos > b->size / 2)
			current_b = db->pos - b->size;
		current_a = ((t_data *)db->target->content)->pos;
		if (current_a > a->size / 2)
			current_a = current_a - a->size;
		db->push_cost = ft_abs(current_a) + ft_abs(current_b);
		if ((current_a > 0 && current_b > 0) 
			|| (current_a < 0 && current_b < 0))
		{
			if (ft_abs(current_a) > ft_abs(current_b))
				db->push_cost -= ft_abs(current_b);
			else
				db->push_cost -= ft_abs(current_a);
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