/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlee <tlee@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 19:34:18 by tlee              #+#    #+#             */
/*   Updated: 2024/06/12 18:00:25 by tlee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @brief Convert an lower letter to uppercase
 * 
 * @param c The character to be converted to uppercase
 * 
 * @return The uppercase equivalent of `c`, if `c` is an lowercase letter;
 * otherwise, `c` is returned unchanged
 */
int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		return (c - 32);
	return (c);
}
