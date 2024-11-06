/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlee <tlee@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 18:24:11 by tlee              #+#    #+#             */
/*   Updated: 2024/05/13 18:25:58 by tlee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @brief Check whether the given character is digit
 *
 * @param c	The character to check
 *
 * @return 2048 if the character is digit, otherwise 0
 */
int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (2048);
	return (0);
}
