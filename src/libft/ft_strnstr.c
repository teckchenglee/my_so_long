/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlee <tlee@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 21:12:57 by tlee              #+#    #+#             */
/*   Updated: 2024/06/12 17:45:27 by tlee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Locate a substring in a string, with length limitation
 * 
 * This function locates the first occurence of the (little) string in the (big)
 * string, where not more than (len) characters are searched
 * 	If (little) is an empty string, return (big)
 * 	If (little) occurs nowhere in (big), return NULL
 * 		otherwise return pointer to the first character of the first occurrence
 * 
 * @param big Pointer to the null-terminated string to be searched
 * 
 * @param little Pointer to the null-terminated string to search for
 * 
 * @param len Maximum number of characters to search in the string `big`
 * 
 * @return A pointer to the first occurrence of the string `little` within
 * `big`, or NULL if `little` is not found within the first `len` characters of
 * `big` 
 */
char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	counter;

	if (*little == '\0')
		return ((char *)big);
	while (*big != '\0' && len > 0)
	{
		counter = 0;
		while (big [counter] == little [counter]
			&& little [counter] != '\0' && counter < len)
		{
			counter++;
		}
		if (little [counter] == '\0')
		{
			return ((char *)big);
		}
		big++;
		len--;
	}
	return (NULL);
}
