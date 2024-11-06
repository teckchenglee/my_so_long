/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlee <tlee@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 15:11:27 by tlee              #+#    #+#             */
/*   Updated: 2024/06/12 15:27:36 by tlee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Compare two memory blocks
 * This function compares the first n bytes of memory areas s1 and s2
 * The return value depends on the difference found
 * return 0 - both string are same
 * return negative - character in s2 is greater than s1
 * return positive - character in s2 is lesser than s1
 * 
 * @param s1 Pointer to the first memory area to be compared
 * 
 * @param s2 Pointer to the second memory area to be compared
 * 
 * @param n Number of bytes to be compared
 * 
 * @return An integer less than, equal to, or greater than zero if the
 * first 'n' bytes of 's1' are found, respectively to first 'n' bytes 
 * of 's2'
 */
int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*str1;
	unsigned char	*str2;

	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	while (n-- > 0)
	{
		if (*str1 != *str2)
			return (*str1 - *str2);
		str1++;
		str2++;
	}
	return (0);
}
