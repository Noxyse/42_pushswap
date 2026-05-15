/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_simple_algo.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgedeon <mgedeon@student.42belgium.be>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 11:13:47 by celgremy          #+#    #+#             */
/*   Updated: 2026/05/15 16:32:18 by mgedeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	ft_find_min_pos(t_stack *a)
{
	t_node	*current;
	int		min_val;
	int		min_pos;
	int		i;

	if (!a || !a->head)
		return (-1);
	current = a->head;
	min_val = ((t_data *)(current->content))->value;
	min_pos = 0;
	i = 0;
	while (current)
	{
		if (((t_data *)(current->content))->value < min_val)
		{
			min_val = ((t_data *)(current->content))->value;
			min_pos = i;
		}
		current = current->next;
		i++;
	}
	return (min_pos);
}

void	ft_sort_three_node(t_stack *a, t_bench *bench)
{
	int	first;
	int	second;
	int	third;

	if (!a || a->size != 3)
		return ;
	first = ((t_data *)(a->head->content))->value;
	second = ((t_data *)(a->head->next->content))->value;
	third = ((t_data *)(a->head->next->next->content))->value;
	if (first > second && second < third && first < third)
		sa(a, bench);
	else if (first > second && second > third && first > third)
	{
		sa(a, bench);
		rra(a, bench);
	}
	else if (first > second && second < third && first > third)
		ra(a, bench);
	else if (first < second && second > third && first < third)
	{
		sa(a, bench);
		ra(a, bench);
	}
	else if (first < second && second > third && first > third)
		rra(a, bench);
}

void	ft_simple_algo(t_stack *a, t_stack *b, t_bench *bench)
{
	int	min_pos;

	while (a->size > 3)
	{
		min_pos = ft_find_min_pos(a);
		while (min_pos != 0)
		{
			if (min_pos <= a->size / 2)
				ra(a, bench);
			else
				rra(a, bench);
			min_pos = ft_find_min_pos(a);
		}
		pb(a, b, bench);
	}
	ft_sort_three_node(a);
	while (b->size > 0)
		pa(a, b, bench);
}
