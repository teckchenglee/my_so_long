/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlee <tlee@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 19:49:21 by tlee              #+#    #+#             */
/*   Updated: 2024/06/12 17:39:50 by tlee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Apply a function to each character of a string, creating a new string
 * from the result
 * 
 * This function applies the function f to each character of the string s,
 * passing its index as the first argurment and the character as the second. A
 * new string is created to collect the results from the successive application
 * of f It return NULL if allocation fails 
 * 
 * @param s Pointer to the null-terminated string to be processed
 * 
 * @param f Pointer to the function to apply to each character of the string
 * 
 * @return A pointer to the newly allocated string containing the results of
 * applying `f` to each character of `s`. Return NULL if either `s` or `f` is
 * NULL or if memory allocation fails.
 */
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*str;
	unsigned int	count;
	unsigned int	i;

	if (!s || !f)
		return (NULL);
	count = 0;
	while (s[count] != '\0')
		count++;
	str = (char *)malloc ((count + 1) * sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	while (i < count)
	{
		str[i] = (*f)(i, s[i]);
		i++;
	}
	str[i] = '\0';
	return (str);
}
