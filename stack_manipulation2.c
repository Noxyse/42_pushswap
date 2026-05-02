/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_manipulation2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgedeon <mgedeon@student.42belgium.be>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 11:21:21 by mgedeon           #+#    #+#             */
/*   Updated: 2026/05/02 16:58:13 by mgedeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

t_node	*ft_remove_head(t_node **stack)
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

t_node	*ft_remove_tail(t_node **stack)
{
	t_node	*current_tail;
	t_node	*removed;

	if (!*stack)
		return (NULL);
	if (!(*stack)->next)
	{
		removed = *stack;
		*stack = NULL;
		return (removed);
	}
	current_tail = ft_stacklast(*stack);
	removed = current_tail;
	current_tail->prev->next = NULL;
	return (removed);
}

void	ft_stackclear(t_node *stack, void (*del)(void *))
{
	t_node	*tmp;

	if (!stack || !del)
		return ;
	while (stack != NULL)
	{
		tmp = (stack->next);
		ft_stackdelone(stack, del);
		stack = tmp;
	}
}
