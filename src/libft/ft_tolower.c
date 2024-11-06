/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlee <tlee@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 19:42:02 by tlee              #+#    #+#             */
/*   Updated: 2024/06/12 17:59:44 by tlee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @brief Convert an uppercase letter to lowercase
 * 
 * @param c The character to be converted to lowercase
 * 
 * @return The lowercase equivalent of `c`, if `c` is an uppercase letter;
 * otherwise, `c` is returned unchanged
 */
int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (c + 32);
	return (c);
}
