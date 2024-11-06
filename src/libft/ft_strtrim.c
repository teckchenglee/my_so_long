/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlee <tlee@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 16:41:55 by tlee              #+#    #+#             */
/*   Updated: 2024/06/12 17:55:20 by tlee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Check if a character exists in a string
 * 
 * @param s Pointer to the null-terminated string to be searched
 * 
 * @param c The character to search for
 * 
 * @return 1 if the character `c` is found in the string `s`, 0 otherwise 
 */
static size_t	ft_checker(const char *s, char const c)
{
	size_t	count;

	if (!s)
		return (0);
	count = 0;
	while (s[count] != '\0')
	{
		if (s[count] == c)
			return (1);
		count++;
	}
	return (0);
}

/**
 * @brief Calculate the length of a null-terminated string
 * 
 * @param s Pointer to the null-terminated string
 * 
 * @return The length of the string 's'
 */
static size_t	ft_str_len(const char *s)
{
	size_t	count;

	count = 0;
	while (s[count] != '\0')
		count++;
	return (count);
}

/**
 * @brief Remove leading and trailing characters specified in the set from a
 * string
 * 
 * This function allocate and returns a copy of s1 with the characters specified
 * in set removed from the beginning and the end of the string
 * Return the trimmed string or NULL if the allocation fails
 *  
 * @param s1 Pointer to the null-terminated string to be trimmed
 * 
 * @param set Pointer to the null-terminated string containing characters to be
 * trimmed
 * 
 * @return A pointer to the newly allocated trimmed string, or NULL if memory
 * allocation fails or if either `s1` or `set` is NULL
 */
char	*ft_strtrim(char const *s1, char const *set)
{
	char	*trim;
	size_t	start;
	size_t	end;
	size_t	count;

	if (s1 == NULL || set == NULL)
		return (NULL);
	start = 0;
	while (s1[start] != '\0' && ft_checker(set, s1[start]))
		start++;
	end = ft_str_len(s1);
	while (end > start && ft_checker(set, s1[end - 1]))
		end--;
	trim = (char *)malloc((end - start) + 1 * sizeof(char));
	if (!trim)
		return (NULL);
	count = 0;
	while ((start + count) < end)
	{
		trim[count] = *(s1 + (start + count));
		count++;
	}
	trim[count] = '\0';
	return (trim);
}
