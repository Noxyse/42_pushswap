/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_simple_algo.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: celgremy <celgremy@student.42belgium.be    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 11:13:47 by celgremy          #+#    #+#             */
/*   Updated: 2026/04/28 14:28:30 by celgremy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	ft_lstsize(t_stack *lst);

int	ft_find_min_pos(t_stack *a, int *error)
{
	t_stack	*list;
	int		index_min;
	int		i;
	int		min;

	if (!a)
	{
		*error = 1;
		return ;
	}
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

void	ft_simple_algo(t_stack **a, t_stack **b, int *error)
{
	int	min_pos;
	int	lst_size;

	while (ft_lstsize(*a) > 3)
	{
		min_pos = ft_find_min_pos(*a, error);
		lst_size = ft_lstsize(*a);
		while (min_pos != 0)
		{
			if (min_pos > list_size / 2)
				rra(a);
			else if (min_pos <= list_size / 2)
				ra(a);
			min_pos = ft_find_min_pos(*a, error);
		}
		pb(a, b);
	}
	ft_sort_three_node(a);
	while (*b)
		pa(b, a);
}
