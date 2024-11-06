/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlee <tlee@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 17:31:50 by tlee              #+#    #+#             */
/*   Updated: 2024/05/13 18:20:33 by tlee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @brief Check whether the given character is alphabet
 *
 * @param c	The character to check
 *
 * @return 1024 if the character is alphabet, otherwise 0
 */
int	ft_isalpha(int c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
		return (1024);
	return (0);
}
