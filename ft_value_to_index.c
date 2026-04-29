/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_value_to_index.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgedeon <mgedeon@student.42belgium.be>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 13:00:04 by mgedeon           #+#    #+#             */
/*   Updated: 2026/04/29 14:16:33 by mgedeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

static int	get_index(t_node *target_node, t_stack *stack)
{
	int		index;
	t_node	*node;

	index = 0;
	node = stack->head;
	while (node)
	{
		if (((t_data *)node->content)->value
			< ((t_data *)target_node->content)->value)
			index++;
		node = node->next;
	}
	return (index);
}

void	ft_value_to_index(t_stack *stack)
{
	t_node	*node;

	node = stack->head;
	while (node)
	{
		((t_data *)node->content)->index = get_index(node, stack);
		node = node->next;
	}
}
