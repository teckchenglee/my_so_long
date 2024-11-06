/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlee <tlee@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 17:10:43 by tlee              #+#    #+#             */
/*   Updated: 2024/06/11 19:43:02 by tlee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/**
 * @brief Print format for %d and %i
 *
 * This function print for %d/%i format of the given parameter, convert the int 
 * to an array to allow writing of the character and return the length of the
 * parameter
 *
 * @param digit Integer parameter
 *
 * @return Length of the string
 */
int	ft_printf_int(int digit)
{
	int	count;
	int	value;

	value = digit;
	count = 0;
	if (value == -2147483648)
	{
		ft_putnbr_fd(digit, 1);
		return (11);
	}
	if (value <= 0)
	{
		value *= -1;
		count++;
	}
	while (value > 0)
	{
		value /= 10;
		count++;
	}
	ft_putnbr_fd(digit, 1);
	return (count);
}
