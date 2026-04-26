/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_disorder.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: celgremy <celgremy@student.42belgium.be    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/26 12:33:31 by celgremy          #+#    #+#             */
/*   Updated: 2026/04/26 14:37:33 by celgremy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	compute_disorder(int *a, int nb_arg)
{
	int	mistakes;
	int	total_pairs;
	int	i;
	int	j;

	mistakes = 0;
	total_pairs = 0;
	i = 0;
	while (i < nb_arg - 1)
	{
		j = i + 1;
		while (j < nb_arg - 1)
		{
			total_pairs += 1;
			if (a[i] > a[j])
				mistakes += 1;
			j++;
		}
		i++;
	}
	if (mistakes < (total_pairs / 5) || total_pairs == 0)
		return (1);
	else if ((mistakes >= (total_pairs / 2)))
		return (3);
	return (2);
}
