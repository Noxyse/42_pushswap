/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgedeon <mgedeon@student.42belgium.be>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/26 12:23:21 by mgedeon           #+#    #+#             */
/*   Updated: 2026/04/28 13:05:08 by mgedeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	sa(t_stack *stack_a)
{
	void	*tmp;

	if (!stack_a || !stack_a->head || !stack_a->head->next)
		return ;
	tmp = stack_a->head->content;
	stack_a->head->content = stack_a->head->next->content;
	stack_a->head->next->content = tmp;
}

void	sb(t_stack *stack_b)
{
	void	*tmp;

	if (!stack_b || !stack_b->head || !stack_b->head->next)
		return ;
	tmp = stack_b->head->content;
	stack_b->head->content = stack_b->head->next->content;
	stack_b->head->next->content = tmp;
}

void	ss(t_stack *stack_a, t_stack *stack_b)
{
	sa(stack_a);
	sb(stack_b);
}

void	pa(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*tmp;


	if (!stack_a || !stack_b || !stack_a->head || !stack_b->head)
		return ;
	tmp = remove_head(&stack_b->head);
	stackadd_front(&stack_a->head, tmp);
	stack_a->size++;
	stack_b->size--;
}

void	pb(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*tmp;

	if (!stack_a || !stack_b || !stack_a->head || !stack_b->head)
		return ;
	tmp = remove_head(&stack_a->head);
	stackadd_front(&stack_b->head, tmp);
	stack_a->size--;
	stack_b->size++;
}
