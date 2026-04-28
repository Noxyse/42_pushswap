/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_simple_algo.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: celgremy <celgremy@student.42belgium.be    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 11:13:47 by celgremy          #+#    #+#             */
/*   Updated: 2026/04/28 11:48:41 by celgremy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	ft_simple_algo(t_stack *a, int *error, int *min, int *max)
{
	t_stack	*list;
	int		val;

	if (!a)
	{
		*error = 1;
		return ;
	}
	list = a;
	*min = list->content;
	*max = list->content;
	while (list->next != NULL)
	{
		list = list->next;
		val = list->content;
		if (val > *max)
			*max = list->content;
		else if (val < *min)
			*min = list->content;
	}
}
