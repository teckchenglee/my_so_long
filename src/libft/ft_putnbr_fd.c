/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlee <tlee@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 18:51:52 by tlee              #+#    #+#             */
/*   Updated: 2024/06/12 15:52:46 by tlee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Writes a character to the specified file descriptor
 * 
 * This function writes the character `c` to the file descriptor `fd`
 * 
 * @param c The character to be written
 * 
 * @param fd The file descriptor to which the character will be written
 */
static void	ft_putchar(char c, int fd)
{
	write(fd, &c, 1);
}

/**
 * @brief Write an integer to the specified file descriptor
 * 
 * This function writes the integer `n` to the file descriptor `fd`
 * 
 * @param n The integer to be written
 * 
 * @param fd The file descriptor to which the character will be written
 */
void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
	{
		ft_putchar_fd ('-', fd);
		ft_putchar_fd ('2', fd);
		n = 147483648;
	}
	if (n < 0)
	{
		ft_putchar_fd ('-', fd);
		n *= -1;
	}
	if (n >= 10)
	{
		ft_putnbr_fd (n / 10, fd);
		ft_putnbr_fd (n % 10, fd);
	}
	else
		ft_putchar (n + '0', fd);
}
