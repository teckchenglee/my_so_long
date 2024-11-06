/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_percent.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlee <tlee@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 15:24:36 by tlee              #+#    #+#             */
/*   Updated: 2024/06/11 19:53:54 by tlee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/**
 * @brief Print percentage symbol
 *
 * This function print '%' sybmbol and return the length
 *
 * @return Length of the parameter
 */
int	ft_printf_percent(void)
{
	ft_putchar_fd('%', 1);
	return (1);
}
