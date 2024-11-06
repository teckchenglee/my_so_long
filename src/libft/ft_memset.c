/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlee <tlee@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 10:21:10 by tlee              #+#    #+#             */
/*   Updated: 2024/06/12 16:52:50 by tlee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Fills memory with a constant byte
 * 
 * This function fills the first 'len' bytes of the memory area pointed to by
 * 's' with the constant byte 'c'
 * 
 * @param s Pointer to the memory area to be filled
 * 
 * @param c The byte value to be written
 * 
 * @param len Number of bytes to written
 * 
 * @return A pointer to the memory area 's'
 */
void	*ft_memset(void *s, int c, size_t len)
{
	unsigned char	*ptr;

	ptr = s;
	while (len--)
	{
		*ptr = (unsigned char)c;
		ptr++;
	}
	return (s);
}
