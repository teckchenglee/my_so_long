/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlee <tlee@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 19:20:42 by tlee              #+#    #+#             */
/*   Updated: 2024/05/13 19:22:33 by tlee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @brief Check whether the given character is printable character
 *
 * @param c	The character to check
 *
 * @return 16384 if the character is printable character, otherwise 0
 */
int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
		return (16384);
	return (0);
}
