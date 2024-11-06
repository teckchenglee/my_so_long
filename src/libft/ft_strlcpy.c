/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlee <tlee@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 19:10:43 by tlee              #+#    #+#             */
/*   Updated: 2024/06/12 17:35:56 by tlee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Copy a string to a destination buffer with size limit
 * 
 * This function copy the null-terminated string 'src' to the destination buffer
 * 'dst' with a size limit of 'size'. It ensures that the destination buffer is
 * null-terminated and not overflowed by truncating 'src' if necessary
 * 
 * @param dst Pointer to the destination buffer where the string is to be copied
 * 
 * @param src Pointer to the null-terminated source string to be copied
 * 
 * @param size Maximum number of characters to be copied to the destination
 * buffer
 * 
 * @return The length of the copied string (`src`)
 */
size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	counter;
	size_t	src_len;

	src_len = 0;
	counter = 0;
	while (src[src_len] != '\0')
		src_len++;
	if (src_len + 1 < size)
	{
		while (counter < src_len + 1)
		{
			dst[counter] = src[counter];
			counter++;
		}
	}
	else if (size != 0)
	{
		while (counter < size - 1)
		{
			dst[counter] = src[counter];
			counter++;
		}
		dst[size - 1] = '\0';
	}
	return (src_len);
}
