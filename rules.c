/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgedeon <mgedeon@student.42belgium.be>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/26 12:23:21 by mgedeon           #+#    #+#             */
/*   Updated: 2026/04/28 11:04:13 by mgedeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	sa(t_stack *stack_a)
{
	void	*tmp;

	if (!stack_a || !stack_a->first || !stack_a->first->next)
		return ;
	tmp = stack_a->first->content;
	stack_a->first->content = stack_a->first->next->content;
	stack_a->first->next->content = tmp;
}

void	sb(t_stack *stack_b)
{
	void	*tmp;

	if (!stack_b || !stack_b->first || !stack_b->first->next)
		return ;
	tmp = stack_b->first->content;
	stack_b->first->content = stack_b->first->next->content;
	stack_b->first->next->content = tmp;
}

void	ss(t_stack *stack_a, t_stack *stack_b)
{
	sa(stack_a);
	sb(stack_b);
}

void	pa(t_stack *stack_a, t_stack *stack_b)
{
	void	*tmp;

	if (!stack_a || !stack_b || !stack_a->first || !stack_b->first)
		return ;
	tmp = stack_b->first->content;
	ft_lstdelone(stack_b->first);
	ft_lstadd_front(*stack_a, ft_lstnew(tmp));
}

void	pb(t_stack *stack_a, t_stack *stack_b)
{
	void	*tmp;

	if (!stack_a || !stack_b || !stack_a->first || !stack_b->first)
		return ;
	tmp = stack_a->first->content;
	ft_lstdelone(stack_a->first);
	ft_lstadd_front(*stack_b, ft_lstnew(tmp));
}
