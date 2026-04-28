/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: celgremy <celgremy@student.42belgium.be>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-04-23 14:59:35 by celgremy          #+#    #+#             */
/*   Updated: 2026-04-23 14:59:35 by celgremy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int	main(void)
{
	int	ft_len;
	int	real_len;

	printf("===== MIX TESTS =====\n\n");
	ft_len = ft_printf("Hello %s %d %x %% %c\n", "world", 42, 255, 'A');
	real_len = printf("Hello %s %d %x %% %c\n", "world", 42, 255, 'A');
	printf("ft: %d | real: %d\n\n", ft_len, real_len);
	ft_len = ft_printf("%d %d %d %d\n", 0, -1, 42, -2147483647 - 1);
	real_len = printf("%d %d %d %d\n", 0, -1, 42, -2147483647 - 1);
	printf("ft: %d | real: %d\n\n", ft_len, real_len);
	ft_len = ft_printf("%x %X %u\n", 4294967295U, 4294967295U, 4294967295U);
	real_len = printf("%x %X %u\n", 4294967295U, 4294967295U, 4294967295U);
	printf("ft: %d | real: %d\n\n", ft_len, real_len);
	printf("===== NULL & EDGE =====\n\n");
	ft_len = ft_printf("%s %s\n", NULL, "test");
	real_len = printf("%s %s\n", (char *)(NULL), "test");
	printf("ft: %d | real: %d\n\n", ft_len, real_len);
	ft_len = ft_printf("%p %p\n", NULL, (void *)0);
	real_len = printf("%p %p\n", NULL, (void *)0);
	printf("ft: %d | real: %d\n\n", ft_len, real_len);
	return (0);
}
