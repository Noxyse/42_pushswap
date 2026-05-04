/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_update_pos.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgedeon <mgedeon@student.42belgium.be>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 13:41:13 by mgedeon           #+#    #+#             */
/*   Updated: 2026/05/04 14:23:34 by mgedeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	ft_update_pos(t_stack *stack)
{
	t_node	*current;
	t_data	*data;
	int		pos;

	pos = 0;
	current = stack->head;
	while (current)
	{
		data = (t_data *)current->content;
		data->pos = pos;
		pos++;
		current = current->next;
	}
}