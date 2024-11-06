/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlee <tlee@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 19:10:47 by tlee              #+#    #+#             */
/*   Updated: 2024/05/21 19:34:11 by tlee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Allocates for an array of nmemb elements of size bytes and initializes
 * the memory to zero
 * 
 * This function allocates memory for an array of nmemb elements of size
 * bytes each and return a pointer to the allocated memory. The memory is
 * set to zero.
 *
 * @param nmemb	Number of elements
 * @param size	Size of each element
 *
 * @return A pointer to the allocated memory, or NULL if allocation fails
 */
void	*ft_calloc(size_t nmemb, size_t size)
{
	unsigned char	*ptr;
	size_t			count;

	ptr = malloc (nmemb * size);
	if (!ptr)
		return (NULL);
	count = 0;
	while (count < nmemb * size)
		ptr[count++] = 0;
	return (ptr);
}
