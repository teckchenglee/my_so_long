/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlee <tlee@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 17:54:25 by tlee              #+#    #+#             */
/*   Updated: 2024/06/12 17:05:24 by tlee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Concatenate two strings into a newly allocated string
 * 
 * This function concatenates the string 's1' and 's2' into a newly allocated
 * string, with 's2' appended to 's1'. Memory allocation is performed to create
 * the new string
 * 
 * @param s1 Pointer to the null-terminated first string
 * 
 * @param s2 Pointer to the null-terminated second string
 * 
 * @return A newly allocated string containing the concatenation of 's1' and
 * 's2' or NULL if allocation memory allocation fails
 */
char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	char	*str;
	char	*str_ptr;

	if (!s1 || !s2)
		return (NULL);
	s1_len = 0;
	while (s1[s1_len] != '\0')
		s1_len++;
	s2_len = 0;
	while (s2[s2_len] != '\0')
		s2_len++;
	str = (char *)malloc (s1_len + s2_len + 1);
	if (!str)
		return (NULL);
	str_ptr = str;
	while (*s1)
		*str++ = *s1++;
	while (*s2)
		*str++ = *s2++;
	*str = '\0';
	return (str_ptr);
}
