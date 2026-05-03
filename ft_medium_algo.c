/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_medium_algo.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgedeon <mgedeon@student.42belgium.be>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 15:08:24 by mgedeon           #+#    #+#             */
/*   Updated: 2026/05/03 14:25:35 by mgedeon          ###   ########.fr       */
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

static void	sort_chunks(t_stack *a, t_stack *b, int chunk_min, int chunk_max)
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
			pb(a, b);
			pushed++;
			data_b = (t_data *)b->head->content;
			if (b->head->next)
			{
				if (data_b->index < ((t_data *)b->head->next->content)->index && data_b->index > ((t_data *)b->head->next->next->content)->index)
					sb(b);
				if (data_b->index < ((t_data *)b->head->next->content)->index)
					rb(b);
			}
		}
		else
		{
			if (which_half(a, chunk_min, chunk_max))
				ra(a);
			else
				rra(a);
		}
	}
}

void	ft_medium_algo(t_stack *stack_a, t_stack *stack_b)
{
	int	chunk_size;
	int	chunk;
	int	total_size;

	total_size = stack_a->size;
	chunk_size = ft_ceil_sqrt(stack_a->size);
	chunk = 0;
	while (chunk < total_size)
	{
		sort_chunks(stack_a, stack_b, chunk, chunk + chunk_size - 1);
		chunk += chunk_size;
	}
	while (stack_b->size > 0)
		pa(stack_a, stack_b);
}
