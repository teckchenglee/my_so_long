/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlee <tlee@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 16:08:52 by tlee              #+#    #+#             */
/*   Updated: 2024/06/12 16:57:08 by tlee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*This function return a pointer to a new string which is a duplicate of the 
string 
Return a pointer to the duplicated string or NULL if insufficient memory
allocated*/

/**
 * @brief Duplicate a string
 * 
 * This function duplicates the string 's' by dynamically allocating memory for
 * a new string containing a copy of the characters from 's', including the
 * terminating null character
 * 
 * @param s Pointer to the null-terminated string to be duplicated
 * 
 * @return A pointer to the newly allocated string containing a duplicated of
 * the string 's'. Return NULL if memory allocation fails
 */
char	*ft_strdup(const char *s)
{
	char	*str;
	size_t	count;
	size_t	i;

	count = 0;
	while (s[count] != '\0')
		count++;
	str = (char *)malloc (count + 1);
	if (!str)
		return (NULL);
	i = 0;
	while (i < count)
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
