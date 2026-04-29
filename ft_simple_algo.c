/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_simple_algo.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: celgremy <celgremy@student.42belgium.be    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 11:13:47 by celgremy          #+#    #+#             */
/*   Updated: 2026/04/29 11:12:21 by celgremy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	ft_find_min_pos(t_stack *a)
{
	t_stack	*list;
	int		index_min;
	int		i;
	int		min;

	list = a;
	index_min = 0;
	i = 0;
	min = list->content;
	while (list)
	{
		if (list->content < min)
		{
			min = list->content;
			index_min = i;
		}
		list = list->next;
		i++;
	}
	return (index_min);
}

void	ft_sort_three_node(t_stack **a)
{
	int	first;
	int	second;
	int	third;

	if (ft_lstsize(*a) != 3)
		return ;
	first = (*a)->content;
	second = (*a)->next->content;
	third = (*a)->next->next->content;
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

void	ft_simple_algo(t_stack **a, t_stack **b, int *error, int size)
{
	int	min_pos;

	if (!*a)
	{
		*error = 1;
		return ;
	}
	while (size > 3)
	{
		min_pos = ft_find_min_pos(*a);
		while (min_pos != 0)
		{
			if (min_pos > size / 2)
				rra(a);
			else if (min_pos <= size / 2)
				ra(a);
			min_pos = ft_find_min_pos(*a);
		}
		pb(a, b);
		size--;
	}
	ft_sort_three_node(a);
	while (*b)
		pa(a, b);
}
