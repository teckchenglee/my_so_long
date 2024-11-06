/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlee <tlee@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 18:52:03 by tlee              #+#    #+#             */
/*   Updated: 2024/06/12 17:26:06 by tlee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Concatenate two strings safely
 * 
 * This function appends the null-terminated string 'src' to the end of the
 * null-terminated string 'dst'. It ensures that the resulting string is
 * null-terminated and not longer than 'size' character to prevent a buffer
 * overflow.
 * 
 * @param dst Pointer to the destination string
 * 
 * @param src Pointer to the source string to be appended
 * 
 * @param size Maximum number of character that can be stored in the destination
 * buffer
 * 
 * @return The total length of the concatenated string if it fits within 'size',
 * otherwise return '(src_len + size)'
 */
size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	src_len;
	size_t	dst_len;
	size_t	total;

	src_len = 0;
	dst_len = 0;
	total = 0;
	while (src[src_len] != '\0')
		src_len++;
	while (dst[dst_len] != '\0' && dst_len <= size)
		dst_len++;
	if (dst_len <= size)
		total = dst_len + src_len;
	else
		return (src_len + size);
	while (*src && ((dst_len + 1) < size))
	{
		*(dst + dst_len) = *src++;
		dst_len++;
	}
	*(dst + dst_len) = '\0';
	return (total);
}
