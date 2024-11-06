/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlee <tlee@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 17:15:10 by tlee              #+#    #+#             */
/*   Updated: 2024/06/11 20:36:41 by tlee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @brief Coverts a string to an integer
 *
 * This function parses the string pointed to by nptr to integer and returns
 * the result as an int value
 * 
 * @param nptr Pointer to the null-terminated byte string to convert
 *
 * @return The converted integer value
 */
int	ft_atoi(const char *nptr)
{
	int	value;
	int	sign;

	sign = 1;
	value = 0;
	while ((*nptr >= 9 && *nptr <= 13) || *nptr == 32)
		nptr++;
	if (*nptr == '+' || *nptr == '-')
	{
		if (*nptr == '-')
			sign *= -1;
		nptr++;
	}
	while (*nptr)
	{
		if (*nptr >= '0' && *nptr <= '9')
			value = value * 10 + (*nptr - '0');
		else
			break ;
		nptr++;
	}
	return (value * sign);
}
