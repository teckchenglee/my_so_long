/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlee <tlee@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 14:15:49 by tlee              #+#    #+#             */
/*   Updated: 2024/06/12 15:33:49 by tlee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Copy memory area
 * 
 * This function copies 'len' bytes from the memory area pointed to by 'src' to
 * the memory area pointed to by 'dest'. The memory areas must not overlap
 * 
 * @param dest Pointer to the destination memory area where data is to be copied
 * 
 * @param src Pointer to the source memory area where data is to be copied
 * 
 * @param len Number of bytes to be copied
 * 
 * @return A pointer to the destination memory area 'dest' 
 */
void	*ft_memcpy(void *dest, const void *src, size_t len)
{
	unsigned char	*tmp_dest;
	unsigned char	*tmp_src;

	if (src == NULL && dest == NULL)
		return (dest);
	tmp_dest = (unsigned char *)dest;
	tmp_src = (unsigned char *)src;
	while (len--)
		*tmp_dest++ = *tmp_src++;
	return (dest);
}
