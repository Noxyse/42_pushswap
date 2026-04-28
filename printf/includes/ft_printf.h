/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: celgremy <celgremy@student.42belgium.be>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-04-23 14:47:12 by celgremy          #+#    #+#             */
/*   Updated: 2026-04-23 14:47:12 by celgremy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

/* ======= INCLUDES ======= */

# include "libft.h"
# include <stdarg.h>

/* ======= PROTOTYPES ======= */

int	ft_printf(const char *format, ...);
int	ft_check_txt(char c, va_list *param);
int	ft_check_baset(char c, va_list *param);
int	ft_check_hex(char c, va_list *param);

#endif