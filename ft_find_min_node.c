/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_min_node.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgedeon <mgedeon@student.42belgium.be>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 13:50:38 by mgedeon           #+#    #+#             */
/*   Updated: 2026/05/05 14:19:31 by mgedeon          ###   ########.fr       */
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