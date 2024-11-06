/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlee <tlee@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 19:16:19 by tlee              #+#    #+#             */
/*   Updated: 2024/06/10 19:16:49 by tlee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/**
 * @brief Set hexadecimal format
 *
 * This function set the hexadecimal format either uppercase or lowercase
 *
 * @param type	Format type
 * 
 * @return Formatted hexadecimal
 */
static char	*hex_format(const char type)
{
	if (type == 'x')
		return ("0123456789abcdef");
	else
		return ("0123456789ABCDEF");
}

/**
 * @brief Print format %x/%X
 *
 * This function print for %x/%X format of the given parameter, convert the int 
 * based on the formatted hexadecimal to an array to allow writing of the
 * character and return the length of the parameter
 *
 * @param digit Integer parameter
 * @param type	Format type
 * 
 * @return Length of the string
 *
 * @note If the value of `digit` exceeds 255, the function recursively calls
 * itself to handle higher-order bits first. Otherwise, it directly prints the
 * hexadecimal digits for both the high-order and low-order bits.
 */
int	ft_printf_hex(unsigned int digit, const char type)
{
	char	*hex;
	int		count;

	count = 0;
	hex = hex_format(type);
	if (digit > 255)
	{
		count += ft_printf_hex((digit / 16), type);
		ft_putchar_fd(hex[digit % 16], 1);
		count ++;
	}
	else
	{
		if (digit >= 16)
		{
			ft_putchar_fd(hex[digit / 16], 1);
			count++;
		}
		ft_putchar_fd(hex[digit % 16], 1);
		count++;
	}
	return (count);
}
