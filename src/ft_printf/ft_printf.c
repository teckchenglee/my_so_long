/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlee <tlee@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 10:27:42 by tlee              #+#    #+#             */
/*   Updated: 2024/08/15 16:37:42 by tlee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/**
 * @brief Check format flags
 *
 * This function check for format flags and print out the parameter and return
 * the length of the parameter
 *
 * @param args 	Hold the list of arguments passed to the function
 * @param c 	Format type
 *
 * @return The length of the parameter
 */
static int	ft_checkformat(va_list args, char c)
{
	int	bytes;

	bytes = 0;
	if (c == '%')
		bytes += ft_printf_percent();
	else if (c == 'c')
		bytes += ft_printf_char(va_arg(args, int));
	else if (c == 's')
		bytes += ft_printf_str(va_arg(args, char *));
	else if (c == 'd' || c == 'i')
		bytes += ft_printf_int(va_arg(args, int));
	else if (c == 'u')
		bytes += ft_printf_unsigned(va_arg(args, unsigned int));
	else if (c == 'x' || c == 'X')
		bytes += ft_printf_hex(va_arg(args, unsigned int), c);
	else if (c == 'p')
		bytes = ft_printf_pointer(va_arg(args, unsigned long));
	return (bytes);
}

/**
 * @brief Print string
 *
 * This function print out the string along with the format of each parameter
 * and return the length of the string
 *
 * @param format 	string with format of each parameter
 * @param ... 		list of parameters
 *
 * @return The length of the string
 */
int	ft_printf(const char *format, ...)
{
	va_list			args;
	unsigned int	count;
	int				bytes;

	bytes = 0;
	count = 0;
	va_start(args, format);
	while (format[count])
	{
		if (format[count] == '%' && ft_strchr("cspdiuxX%", format[count + 1]))
			bytes += ft_checkformat(args, format[++count]);
		else
		{
			ft_putchar_fd(format[count], 1);
			bytes++;
		}
		count++;
	}
	va_end(args);
	return (bytes);
}
