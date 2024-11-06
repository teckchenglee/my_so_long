/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlee <tlee@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 17:14:05 by tlee              #+#    #+#             */
/*   Updated: 2024/06/12 16:53:17 by tlee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Copy memory area, allowing overlap between source and destination
 * 
 * This function copies `len` bytes from the memory area pointed to by `src` to
 * the memory area pointed to by `dest`. Unlike ft_memcpy, the memory areas may
 * overlap. The copying takes place as if the memory areas were not overlapping,
 * therefore, it is safe to use for copying data within the same memory block,
 * even if the source and destination regions overlap.
 * 
 * @param dest Pointer to the destination memory area where data is to be copied
 * 
 * @param src Pointer to the source memory area where data is to be copied
 * 
 * @param len Number of bytes to be copied
 * 
 * @return A pointer to the destination memory area 'dest'
 * 
 * @note If dest less than or equal to src, meaning memory regions do not
 * overlap. It perform forward copy. It iterate through the memory region from 
 * src and copy each byte to dest
 * If dest greater than src, meaning possible overlap. It perform backward copy.
 * It move both tmp_dest and tmp_src to the end of memory region, and iterate
 * backward copying each byte from src to dest
 */
void	*ft_memmove(void *dest, const void *src, size_t len)
{
	unsigned char	*tmp_dest;
	unsigned char	*tmp_src;

	if (dest == NULL && src == NULL)
		return (NULL);
	tmp_dest = (unsigned char *)dest;
	tmp_src = (unsigned char *)src;
	if (dest <= src)
	{
		while (len--)
			*tmp_dest++ = *tmp_src++;
	}
	else
	{
		tmp_dest += len -1;
		tmp_src += len -1;
		while (len--)
			*tmp_dest-- = *tmp_src--;
	}
	return (dest);
}
