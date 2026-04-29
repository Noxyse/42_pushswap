/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgedeon <mgedeon@student.42belgium.be>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 09:50:42 by mgedeon           #+#    #+#             */
/*   Updated: 2026/04/29 12:05:24 by mgedeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

t_node	*ft_stacknew(void *content)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->content = content;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}

t_node	*ft_stacklast(t_node *stack)
{
	if (stack == NULL)
		return (stack);
	while (stack->next != NULL)
		stack = stack->next;
	return (stack);
}

void	ft_stackdelone(t_node *stack, void (*del)(void *))
{
	if (!stack || !del)
		return ;
	del(stack->content);
	free(stack);
}

void	ft_stackadd_front(t_node **stack, t_node *new)
{
	if (!*stack)
	{
		*stack = new;
		new->next = NULL;
		return ;
	}
	new->next = *stack;
	new->prev = NULL;
	(*stack)->prev = new;
	*stack = new;
}

void	ft_stackadd_back(t_node **stack, t_node *new)
{
	t_node	*tmp;

	if (!new)
		return ;
	if (!*stack)
	{
		*stack = new;
		return ;
	}
	tmp = stacklast(*stack);
	tmp->next = new;
	new->prev = tmp;
	new->next = NULL;
}
