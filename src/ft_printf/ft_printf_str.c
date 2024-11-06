/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlee <tlee@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 15:30:13 by tlee              #+#    #+#             */
/*   Updated: 2024/06/11 19:39:36 by tlee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/**
 * @brief Print format %s and return the length of the string
 *
 * This function print for %s format of the given parameter and return the
 * length of the parameter
 *
 * @param str String parameter
 *
 * @return Length of the string
 */
int	ft_printf_str(char *str)
{
	if (str == NULL)
	{
		ft_putstr_fd("(null)", 1);
		return (ft_strlen("(null)"));
	}
	ft_putstr_fd(str, 1);
	return (ft_strlen(str));
}
