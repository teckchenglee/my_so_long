/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlee <tlee@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 20:42:46 by tlee              #+#    #+#             */
/*   Updated: 2024/06/08 17:11:51 by tlee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft/libft.h"
# include <stdarg.h>

int	ft_printf(const char *format, ...);
int	ft_printf_percent(void);
int	ft_printf_char(char c);
int	ft_printf_str(char *str);
int	ft_printf_int(int digit);
int	ft_printf_unsigned(unsigned int digit);
int	ft_printf_hex(unsigned int digit, const char type);
int	ft_printf_pointer(unsigned long digit);

#endif
