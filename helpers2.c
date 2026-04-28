/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgedeon <mgedeon@student.42belgium.be>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 11:21:21 by mgedeon           #+#    #+#             */
/*   Updated: 2026/04/28 12:51:22 by mgedeon          ###   ########.fr       */
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