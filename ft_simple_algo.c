/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_simple_algo.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: celgremy <celgremy@student.42belgium.be    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 11:13:47 by celgremy          #+#    #+#             */
/*   Updated: 2026/05/02 16:24:17 by celgremy         ###   ########.fr       */
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
	min_val = *(int *)(current->content);
	min_pos = 0;
	i = 0;
	while (current)
	{
		if (*(int *)(current->content) < min_val)
		{
			min_val = *(int *)(current->content);
			min_pos = i;
		}
		current = current->next;
		i++;
	}
	return (min_pos);
}

void	ft_sort_three_node(t_stack *a)
{
	int	first;
	int	second;
	int	third;

	if (!a || a->size != 3)
		return ;
	first = *(int *)(a->head->content);
	second = *(int *)(a->head->next->content);
	third = *(int *)(a->head->next->next->content);
	if (first > second && second < third && first < third)
		sa(a);
	else if (first > second && second > third && first > third)
	{
		sa(a);
		rra(a);
	}
	else if (first > second && second < third && first > third)
		ra(a);
	else if (first < second && second > third && first < third)
	{
		sa(a);
		ra(a);
	}
	else if (first < second && second > third && first > third)
		rra(a);
}

void	ft_simple_algo(t_stack *a, t_stack *b)
{
	int	min_pos;

	while (a->size > 3)
	{
		min_pos = ft_find_min_pos(a);
		while (min_pos != 0)
		{
			if (min_pos <= a->size / 2)
				ra(a);
			else
				rra(a);
			min_pos = ft_find_min_pos(a);
		}
		pb(a, b);
	}
	ft_sort_three_node(a);
	while (b->size > 0)
		pa(a, b);
}
