/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_complex_algo.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgedeon <mgedeon@student.42belgium.be>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/10 16:17:39 by celgremy          #+#    #+#             */
/*   Updated: 2026/05/15 16:42:52 by mgedeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

t_node	*ft_find_min_node(t_stack *stack)
{
	t_node	*current;
	t_node	*min_node;
	t_data	*data;
	int		min_index;

	min_node = NULL;
	min_index = INT_MAX;
	current = stack->head;
	while (current)
	{
		data = (t_data *)current->content;
		if (data->index < min_index)
		{
			min_node = current;
			min_index = data->index;
		}
		current = current->next;
	}
	return (min_node);
}

void	ft_find_target_node(t_stack *a, t_stack *b)
{
	t_node	*current_a;
	t_node	*current_b;
	t_data	*data_a;
	t_data	*data_b;

	current_b = b->head;
	while (current_b)
	{
		data_b = (t_data *)current_b->content;
		data_b->target = NULL;
		current_a = a->head;
		while (current_a)
		{
			data_a = (t_data *)current_a->content;
			if (data_a->index > data_b->index)
			{
				if (data_b->target == NULL || data_a->index
					< ((t_data *)data_b->target->content)->index)
					data_b->target = current_a;
			}
			current_a = current_a->next;
		}
		if (data_b->target == NULL)
			data_b->target = ft_find_min_node(a);
		current_b = current_b->next;
	}
}

void	ft_update_pos(t_stack *stack)
{
	t_node	*current;
	t_data	*data;
	int		pos;

	pos = 0;
	current = stack->head;
	while (current)
	{
		data = (t_data *)current->content;
		data->pos = pos;
		pos++;
		current = current->next;
	}
}

void	ft_min_a_to_top(t_stack *a, t_bench *bench)
{
	t_node	*min;

	min = ft_find_min_node(a);
	while (a->head != min)
	{
		if (((t_data *)min->content)->pos <= a->size / 2)
			ra(a, bench);
		else
			rra(a, bench);
		ft_update_pos(a);
	}
}

void	ft_complex_algo(t_stack *a, t_stack *b, t_bench *bench)
{
	t_node	*best;

	while (a->size > 3)
		pb(a, b, bench);
	ft_sort_three_node(a, bench);
	while (b->size > 0)
	{
		ft_update_pos(a);
		ft_update_pos(b);
		ft_find_target_node(a, b);
		ft_calculate_cost(a, b);
		best = ft_find_best_path(b);
		ft_move_b_to_a(best, a, b);
	}
	ft_min_a_to_top(a, bench);
}
