/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_medium_algo2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgedeon <mgedeon@student.42belgium.be>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/03 15:19:17 by mgedeon           #+#    #+#             */
/*   Updated: 2026/05/03 15:26:51 by mgedeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	b_desc(t_stack *b, int chunk_min, int chunk_max)
{
	t_data	*data;

	while (b->head != chunk_max)
	{
		data = (t_data *)b->head->content;
		if (b->head && b->head->next)
		{
			if (data->index < ((t_data *)b->head->next->content)->index)
			{
				sb(b);
				rb(b);
			}
		}
	}
}
