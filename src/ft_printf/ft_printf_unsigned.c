/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_unsigned.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlee <tlee@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 19:14:13 by tlee              #+#    #+#             */
/*   Updated: 2024/06/10 19:14:37 by tlee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/**
 * @brief Print format for %u
 *
 * This function print for %u format, convert the unsigned int to an array to
 * allow writing of the character and return the length of the parameter
 *
 * @param digit Unsigned integer parameter
 *
 * @return Length of the parameter
 */
int	ft_printf_unsigned(unsigned int digit)
{
	int	count;

	count = 0;
	if (digit >= 10)
		count += ft_printf_unsigned(digit / 10);
	ft_putchar_fd(digit % 10 + '0', 1);
	count++;
	return (count);
}
