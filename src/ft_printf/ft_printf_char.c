/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlee <tlee@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 15:27:41 by tlee              #+#    #+#             */
/*   Updated: 2024/06/07 15:28:07 by tlee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/**
 * @brief Print format for %c
 *
 * This function print for %c format of the given parameter return the length 
 * of the parameter
 *
 * @param c Character parameter
 *
 * @return Length of the parameter
 */
int	ft_printf_char(char c)
{
	ft_putchar_fd(c, 1);
	return (1);
}
