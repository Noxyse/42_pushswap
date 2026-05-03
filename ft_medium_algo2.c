/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_medium_algo2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgedeon <mgedeon@student.42belgium.be>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/03 15:19:17 by mgedeon           #+#    #+#             */
/*   Updated: 2026/05/03 16:28:19 by mgedeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	find_max_pos(t_stack *b, int total_size)
{
	t_node	*current;
	t_data	*data;
	int		max_index;
	int		current_pos;
	int		max_index_pos;

	current = b->head;
	max_index = total_size;
	current_pos = 0;
	max_index_pos = 0;
	while (current)
	{
		data = (t_data *)current->content;
		if (data->index > max_index)
		{
			max_index = data->index;
			max_index_pos = current_pos;
		}
		current_pos++;
		current = current->next;
	}
	return (max_index_pos);
}
