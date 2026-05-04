/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_target_node.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgedeon <mgedeon@student.42belgium.be>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 14:32:53 by mgedeon           #+#    #+#             */
/*   Updated: 2026/05/04 15:06:24 by mgedeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

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
		current_b = current_b->next;
	}
	// MISSING EDGE CASE WHEN CURRENT_B IS BIGGER THAN EVERY NODE IN A
}
