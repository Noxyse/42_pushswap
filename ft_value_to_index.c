/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_value_to_index.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgedeon <mgedeon@student.42belgium.be>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 13:00:04 by mgedeon           #+#    #+#             */
/*   Updated: 2026/04/29 14:22:06 by mgedeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

static int	get_index(t_node *target_node, t_stack *stack)
{
	int		index;
	t_node	*node;
	t_data	*data;

	index = 0;
	node = stack->head;
	while (node)
	{
		data = (t_data *)node->content;
		if (data->value < ((t_data *)target_node->content)->value)
			index++;
		node = node->next;
	}
	return (index);
}

void	ft_value_to_index(t_stack *stack)
{
	t_node	*node;
	t_data	*data;

	node = stack->head;
	while (node)
	{
		data = (t_data *)node->content;
		data->index = get_index(node, stack);
		node = node->next;
	}
}
