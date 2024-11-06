/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlee <tlee@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 14:09:09 by tlee              #+#    #+#             */
/*   Updated: 2024/06/12 15:21:36 by tlee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Locate byte in memory
 * 
 * This function search for the first occurrence of the byte 'c' in the initial
 * 'n' bytes of the memory area pointed to by 's'
 * 
 * @param s Pointer to the memory area to be searched
 * 
 * @param c The byte value to be located
 * 
 * @param n Number of bytes to be searched
 * 
 * @return A pointer to the first occurrence of the byte 'c' in the memory area
 * pointed to by 's', or NULL if the byte is not found within the first 'n' byte
 */
void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*ptr;

	ptr = (unsigned char *)s;
	while (n--)
	{
		if (*ptr == (unsigned char)c)
		{
			s = ptr;
			return ((void *)s);
		}
		ptr++;
	}
	return (NULL);
}
