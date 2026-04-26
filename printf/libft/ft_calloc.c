/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: celgremy <celgremy@student.42belgium.be>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-04-13 09:50:42 by celgremy          #+#    #+#             */
/*   Updated: 2026-04-13 09:50:42 by celgremy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;

	if (nmemb != 0 && size > SIZE_MAX / nmemb)
		return (NULL);
	ptr = malloc(nmemb * size);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, nmemb * size);
	return (ptr);
}
/*
int	main(void)
{
	int	*tab;
	int	i;

	tab = ft_calloc(5, sizeof(int));
	while (i < 5)
	{
		printf("%d ", tab[i]);
		i++;
	}
	printf("\n");

	free(tab);

	char *str = ft_calloc(10, sizeof(char));
	printf("'%s'\n", str);

	free(str);

	return (0);
}*/
