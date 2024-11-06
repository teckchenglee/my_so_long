/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlee <tlee@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 18:35:40 by tlee              #+#    #+#             */
/*   Updated: 2024/06/12 15:49:42 by tlee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Writes a string followed by a newline character to the specified file
 * descriptor
 * 
 * This function writes the string `s` to the file descriptor `fd`, followed by
 * a newline character
 * 
 * @param s The string to be written
 * 
 * @param fd The file descriptor to which the string and newline will be written
 */
void	ft_putendl_fd(char *s, int fd)
{
	int	count;

	count = 0;
	while (s[count] != '\0')
	{
		write (fd, &s[count], 1);
		count++;
	}
	write (fd, "\n", 1);
}
