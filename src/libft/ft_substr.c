/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlee <tlee@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 16:56:02 by tlee              #+#    #+#             */
/*   Updated: 2024/06/12 17:58:36 by tlee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Create a substring of a given string
 * 
 * This function creates a new null-terminated substring from the
 * null-terminated string `s`, starting at the index `start` and containing at
 * most `len` characters. The resulting substring is allocated dynamically and
 * must be freed by the caller to avoid memory leaks
 * 
 * @param s Pointer to the null-terminated string from which the substring will
 * be created
 * 
 * @param start Index of the first character of the substring within `s`
 * 
 * @param len Maximum length of the substring
 * 
 * @return A pointer to the newly allocated substring, or NULL if memory
 * allocation fails or if `s` is NULL. 
 */
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	count;
	char	*str_ptr;

	if (s == NULL)
		return (NULL);
	count = 0;
	while (s[count] != '\0')
		count++;
	if (start > count)
		len = 0;
	else if (len > (count - start))
		len = count - start;
	str = (char *)malloc((len + 1) * sizeof (char));
	if (!str)
		return (NULL);
	str_ptr = str;
	str[len] = '\0';
	while (len-- && *s)
		*str++ = s[start++];
	return (str_ptr);
}
