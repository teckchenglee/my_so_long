/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlee <tlee@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 16:00:55 by tlee              #+#    #+#             */
/*   Updated: 2024/06/12 16:52:24 by tlee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Counts the number of substrings delimited by a specific character in
 * a string
 * 
 * @param s The string to be analyzed
 * 
 * @param c The delimited character used to split the string into substring
 * 
 * @return The number of substring delimited by the character 'c' in the
 * string 's'
 */
static size_t	ft_wordcount(char const *s, char c)
{
	size_t	total;

	total = 0;
	if (!*s)
		return (0);
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s)
			total++;
		while (*s && *s != c)
			s++;
	}
	return (total);
}

/**
 * @brief Copies a substring from a string
 * 
 * This function copies the substring from index 'start' to 'end'
 * from the string 's' and return a newly allocated string containing
 * the copied substring
 * 
 * @param s The source string from which the substring will be copied
 * 
 * @param start The starting index of substring (inclusive)
 * 
 * @param end The ending index of the substring (exclusive)
 * 
 * @return A newly allocated string containing the copied substring.
 * Return NULL if memory allocation fails
 */
static char	*ft_copyword(const char *s, int start, int end)
{
	char	*word;
	int		i;

	word = (char *)malloc((end - start + 1) * sizeof(char));
	if (!word)
		return (NULL);
	i = 0;
	while (start < end)
		word[i++] = s[start++];
	word[i] = '\0';
	return (word);
}

/**
 * @brief Frees the memory allocated for copied word as it already
 * copied the substring to the 'list' string
 * 
 * This function frees the memory allocated for copied substring
 * 'array', and free each bytes used of the copied word up to index 'i'
 * 
 * @param array The array of strings to be freed
 * 
 * @param i The index up to which memory should be freed
 * 
 * @return NULL
 */
static char	**ft_freearray(char **array, size_t i)
{
	while (i > 0)
	{
		i--;
		free(*(array + i));
	}
	free(array);
	return (NULL);
}

/**
 * @brief Splits the string into substrings and stores them in the array
 * 
 * This function splits the string 's' into substrings based on the delimiter
 * character 'c' and stores them in the array 'list'. It iterates through the
 * string, identifies the substrings. Allocate memory for each substring. Copies
 * the characters into the allocated memory and stores the pointers to the
 * substring in the array.
 * 
 * @param list An array of string to store the substring
 * 
 * @param s The string to be split
 * 
 * @param c The delimiter character used to split the string
 * 
 * @param count The number of substring to be stored in the array
 * 
 * @return A pointer to the array of strings containing the substring. Return
 * NULL if memory allocation fails during substring creation
 */
static char	**ft_listword(char **list, char const *s, char c, size_t count)
{
	size_t	i;
	size_t	j;
	int		index;

	i = 0;
	j = 0;
	index = -1;
	while (j < count)
	{
		if (s[i] != c && index < 0)
			index = i;
		else if ((s[i] == c || s[i] == '\0') && index >= 0)
		{
			list[j] = ft_copyword(s, index, i);
			if (!list[j])
				return (ft_freearray(list, j));
			j++;
			index = -1;
		}
		i++;
	}
	list[j] = NULL;
	return (list);
}

/**
 * @brief Splits a string into an array of substring based on a delimiter
 * character
 *
 * This function splits the string `s` into an array of substrings, using the
 * delimiter character `c`. The resulting array of strings is terminated by a
 * NULL pointer. Memory allocation for the array and the individual substrings
 * is performed using malloc.
 * 
 * @param s The string to be split
 * 
 * @param c The delimiter character used to split the string
 * 
 * @return A pointer to an array of string, where each string is a substring
 * of 's' delimited by 'c'. Return NULL if memory allocation fails or if 's'
 * is NULL
 */
char	**ft_split(char const *s, char c)
{
	char	**list_word;
	size_t	count;

	count = ft_wordcount(s, c);
	list_word = (char **)malloc((count + 1) * sizeof(char *));
	if (!list_word)
		return (NULL);
	list_word = ft_listword(list_word, s, c, count);
	return (list_word);
}
