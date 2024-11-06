/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlee <tlee@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 20:13:35 by tlee              #+#    #+#             */
/*   Updated: 2024/06/12 17:51:39 by tlee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Locate the last occurrence of a character in a string
 * 
 * This function returns a pointer to the last occurrence of the character c in 
 * string s. The return value return a pointer to the matched character or NULL
 * if the character not found. If c specified as '\0', these functions return
 * a pointer to the terminator 
 * 
 * @param s Pointer to the null-terminated string to be searched
 * 
 * @param c The character to search for
 * 
 * @return A pointer to the last occurrence of the character `c` in the string
 * `s`, or NULL if the character is not found 
 */
char	*ft_strrchr(const char *s, int c)
{
	const char	*tmp;

	tmp = NULL;
	while (*s)
	{
		if (*s == (char)c)
			tmp = s;
		s++;
	}
	if (*s == (char)c)
		return ((char *)s);
	return ((char *)tmp);
}
