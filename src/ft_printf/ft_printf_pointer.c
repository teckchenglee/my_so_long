/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_pointer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlee <tlee@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 19:23:37 by tlee              #+#    #+#             */
/*   Updated: 2024/06/10 19:24:01 by tlee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/**
 * @brief Convert the unsigned long to hexdecimal
 *
 * This function convert unsigned long to an array to allow writing of the
 * character of the given parameter and return the length of the address
 *
 * @param digit Unsigned long parameter
 * 
 * @return Length of the address
 */
static int	ft_printaddress(unsigned long digit)
{
	char	*hex;
	int		count;

	hex = "0123456789abcdef";
	count = 0;
	if (digit > 255)
	{
		count += ft_printaddress(digit / 16);
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

/**
 * @brief Print format %p
 *
 * This function print for %p format of the given parameter, convert the
 * unsigned int to pointer address and return the length of the parameter
 *
 * @param digit Unsigned long parameter
 * 
 * @return Length of the pointer address
 */
int	ft_printf_pointer(unsigned long digit)
{
	int	count;

	count = 0;
	if (digit == 0)
	{
		ft_putstr_fd("(nil)", 1);
		count = 5;
	}
	else
	{
		ft_putstr_fd("0x", 1);
		count += 2 + ft_printaddress(digit);
	}
	return (count);
}
