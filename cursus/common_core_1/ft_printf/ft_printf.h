/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blvilarn <blvilarn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 19:33:01 by blvilarn          #+#    #+#             */
/*   Updated: 2023/01/12 20:09:18 by blvilarn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>

int	ft_printf(const char *str, ...);
int	print_content(const char *str, va_list ptr, int *i, int *len);
int	ft_putchar(char c, int *i, int *len);
int	ft_putstr(char *s, int *i, int *len);
int	ft_putnumber(long long n, int *i, int *len);
int	ft_strlen(char *str);
int	pnbr_b(char *base_array, unsigned long n, int *len, int *i);

#endif
