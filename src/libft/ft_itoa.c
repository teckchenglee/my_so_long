/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlee <tlee@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 11:50:17 by tlee              #+#    #+#             */
/*   Updated: 2024/06/12 14:18:27 by tlee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Calculate the allocated space require
 * 
 * This function calculate the allocate space require to represent the integer
 * value in a string and return the size reqiure to allocated this value
 * 
 * @param n Integer value
 * 
 * @return The size require
 */
static int	ft_len(int n)
{
	int	count;
	int	value;

	value = n;
	count = 0;
	if (value == -2147483648)
	{
		return (11);
	}
	if (value <= 0)
	{
		value *= -1;
		count++;
	}
	while (value > 0)
	{
		value /= 10;
		count++;
	}
	return (count);
}

/**
 * @brief Convert the integer value to a string
 * 
 * This function parse the integer value and return a string representation
 * of the received argument. 
 * 
 * @param n Integer value to be converted
 * 
 * @return The string representing the integer value or NULL if allocation
 * fails
 */
char	*ft_itoa(int n)
{
	char	*str;
	long	value;
	int		len;
	int		sign;

	value = n;
	sign = 0;
	if (n < 0)
	{
		value *= -1;
		sign = 1;
	}
	len = ft_len(n);
	str = (char *)malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	str[len] = '\0';
	while (len--)
	{
		str[len] = (value % 10) + '0';
		value /= 10;
		if (sign && len == 0)
			str[len] = '-';
	}
	return (str);
}
