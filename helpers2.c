/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgedeon <mgedeon@student.42belgium.be>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 11:21:21 by mgedeon           #+#    #+#             */
/*   Updated: 2026/04/28 13:53:39 by mgedeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

t_node	*remove_head(t_node **stack)
{
	t_node	*new_head;
	t_node	*removed;

	if (!*stack)
		return (NULL);
	if (!(*stack)->next)
	{
		removed = *stack;
		*stack = NULL;
		return (removed);
	}
	removed = *stack;
	new_head = (*stack)->next;
	*stack = new_head;
	(*stack)->prev = NULL;
	return (removed);
}

t_node	*remove_tail(t_node **stack)
{
	t_node	*current_tail;
	t_node	*new_tail;
	t_node	*removed;

	if (!*stack)
		return (NULL);
	if (!(*stack)->next)
	{
		removed = *stack;
		*stack = NULL;
		return (removed);
	}
	current_tail = stacklast(*stack);
	removed = current_tail;
	new_tail = current_tail->prev;
	new_tail->next = NULL;
	return (removed);
}
