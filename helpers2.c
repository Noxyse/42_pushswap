/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgedeon <mgedeon@student.42belgium.be>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 11:21:21 by mgedeon           #+#    #+#             */
/*   Updated: 2026/04/28 11:32:09 by mgedeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

t_node	remove_head(t_stack **stack)
{
	t_node	*tail;
	t_node	*new_head;

	new_head = 
	tail = stacklast(*stack);
	(*stack)->prev = tail;
}