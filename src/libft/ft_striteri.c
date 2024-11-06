/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlee <tlee@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 10:43:08 by tlee              #+#    #+#             */
/*   Updated: 2024/06/12 17:01:07 by tlee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @brief Apply a function to each character of a string with its index
 * 
 * This function applies the function f to each character of the string passed
 * as argument, passing its index as first argument. Each character is passed by
 * address to 'f' to be modified if necessary
 * 
 * @param s Pointer to the null-terminated string to be processed
 * 
 * @param f Pointer to the function to apply to each character of the string
 */
void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	count;

	count = 0;
	while (s[count] != '\0')
	{
		(*f)(count, &s[count]);
		count++;
	}
}
