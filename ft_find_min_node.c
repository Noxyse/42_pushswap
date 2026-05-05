/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_min_node.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgedeon <mgedeon@student.42belgium.be>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 13:50:38 by mgedeon           #+#    #+#             */
/*   Updated: 2026/05/05 14:00:03 by mgedeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void    ft_find_min_node(t_stack *stack)
{
    t_node  *current;
    t_data  *data;
	t_data	*min_index;

    current = stack->head;
    while (current)
    {
    	data = (t_data *)current->content;
		min_index = data->index;
		if (data->index > ((t_data *)current->next->content)->index)
			min_index = (t_data *)current->next->content)->index;
		current = current->next;
    }
}