/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: celgremy <celgremy@student.42belgium.be>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-04-10 09:58:10 by celgremy          #+#    #+#             */
/*   Updated: 2026-04-10 09:58:10 by celgremy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	src_len;

	src_len = ft_strlen(src);
	if (size > 0)
	{
		i = 0;
		while (i < size - 1 && src[i])
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (src_len);
}
/*
int	main(void)
{
	char	src[] = "HelloWorld";
	char	dst1[20];
	char	dst2[5];
	size_t	ret;

	ret = ft_strlcpy(dst1, src, sizeof(dst1));
	printf("Test 1:\n");
	printf("src: %s\n", src);
	printf("dst: %s\n", dst1);
	printf("ret: %zu\n\n", ret);

	ret = ft_strlcpy(dst2, src, sizeof(dst2));
	printf("Test 2:\n");
	printf("src: %s\n", src);
	printf("dst: %s\n", dst2);
	printf("ret: %zu\n\n", ret);

	return (0);
}*/
