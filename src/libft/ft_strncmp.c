/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlee <tlee@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 21:03:02 by tlee              #+#    #+#             */
/*   Updated: 2024/06/12 17:42:54 by tlee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Compare two null-terminated strings up to a specified number of
 * characters
 * 
 * @param s1 Pointer to the first null-terminated string to be compared
 * 
 * @param s2 Pointer to the second null-terminated string to be compared
 * 
 * @param n Maximum number of characters to compare
 * 
 * @return An integer less than, equal to, or greater than zero if the string
 * `s1` is found, respectively to the string 's2'
 * 
 * @note By casting the characters to unsigned char, the function ensures
 * correct comparison of characters without any sign extension issues
 */
int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	if (n == 0)
		return (0);
	while (*s1 && *s2 && *s1 == *s2 && --n)
	{
		s1++;
		s2++;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}
