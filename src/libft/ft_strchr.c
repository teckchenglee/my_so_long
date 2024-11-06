/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlee <tlee@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 18:57:25 by tlee              #+#    #+#             */
/*   Updated: 2024/06/12 16:43:41 by tlee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Locate the first occurrence of a character in a string
 * 
 * This function searches for the first occurrence of the character 'c' in the
 * string 's'. If c specified as '\0', these functions return a pointer to the
 * terminator
 * 
 * @param s Pointer to the null-terminated string to be searched
 * 
 * @param c The character to be located
 * 
 * @return A pointer to the first occurrence of the charcter 'c' in the string
 * 's', or a null pointer if the character not found
 */
char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if (*s == (char)c)
		return ((char *)s);
	return (NULL);
}
