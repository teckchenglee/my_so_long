/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlee <tlee@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 11:50:41 by tlee              #+#    #+#             */
/*   Updated: 2024/11/02 14:53:41 by tlee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Sets the first len bytes of the memory area pointed to by s to zero
 *
 * @param s		Pointer to the memory area to be zeroed
 * @param len	Number of bytes to zero
 */
void	ft_bzero(void *s, size_t len)
{
	unsigned char	*tmp;

	tmp = (unsigned char *)s;
	while (len--)
	{
		*(tmp) = 0;
		tmp++;
	}
}
