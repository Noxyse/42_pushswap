/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_medium_algo.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgedeon <mgedeon@student.42belgium.be>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 15:08:24 by mgedeon           #+#    #+#             */
/*   Updated: 2026/05/15 16:35:13 by mgedeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

static int	ft_sqrt(int n)
{
	int	i;

	i = 1;
	if (n <= 0)
		return (0);
	while (i * i <= n)
		i++;
	return (i - 1);
}

static int	ft_ceil_sqrt(int n)
{
	int	i;

	i = ft_sqrt(n);
	if (i * i < n)
		return (i + 1);
	return (i);
}

static int	which_half(t_stack *a, int chunk_min, int chunk_max)
{
	t_node	*current;
	t_data	*data;
	int		pos;

	pos = 0;
	current = a->head;
	while (current)
	{
		data = (t_data *)current->content;
		if (data->index >= chunk_min && data->index <= chunk_max)
			return (pos < a->size / 2);
		current = current->next;
		pos++;
	}
	return (-1);
}

void	sort_chunks(t_stack *a, t_stack *b, int chunk_min, int chunk_max, t_bench *bench)
{
	int		pushed;
	t_data	*data_a;
	t_data	*data_b;

	data_a = (t_data *)a->head->content;
	pushed = 0;
	while (pushed <= (chunk_max - chunk_min))
	{
		if (!a->head)
			break ;
		data_a = (t_data *)a->head->content;
		if (data_a->index >= chunk_min && data_a->index <= chunk_max)
		{
			pb(a, b, bench);
			pushed++;
			data_b = (t_data *)b->head->content;
			if (b->head->next)
			{
				if (data_b->index < ((t_data *)b->head->next->content)->index)
					rb(b, bench);
			}
		}
		else
		{
			if (which_half(a, chunk_min, chunk_max))
				ra(a, bench);
			else
				rra(a, bench);
		}
	}
}

void	ft_medium_algo(t_stack *stack_a, t_stack *stack_b, t_bench *bench)
{
	int	chunk_size;
	int	chunk;
	int	total_size;

	total_size = stack_a->size;
	chunk_size = ft_ceil_sqrt(stack_a->size);
	chunk = 0;
	while (chunk < total_size)
	{
		sort_chunks(stack_a, stack_b, chunk, chunk + chunk_size - 1, bench);
		chunk += chunk_size;
	}
	while (stack_b->size > 0)
	{
		while (find_max_pos(stack_b) > 0)
		{
			if (find_max_pos(stack_b) <= stack_b->size / 2)
				rb(stack_b, bench);
			else
				rrb(stack_b, bench);
		}
		pa(stack_a, stack_b, bench);
	}
}
