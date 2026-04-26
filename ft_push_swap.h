/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgedeon <mgedeon@student.42belgium.be>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/26 14:07:38 by mgedeon           #+#    #+#             */
/*   Updated: 2026/04/26 14:57:45 by mgedeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUSH_SWAP_H	
# define FT_PUSH_SWAP_H	

typedef struct s_node
{
	void			*content;
	struct s_node	*next;
	struct s_node	*prev;
}					t_node;

typedef struct s_stack
{
	t_node	*first;
	t_node	*last;
	int		size;
}			t_stack;

#endif