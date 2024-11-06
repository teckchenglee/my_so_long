/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlee <tlee@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 18:18:20 by tlee              #+#    #+#             */
/*   Updated: 2024/06/12 15:54:29 by tlee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Writes a string to the specified file descriptor
 * 
 * This function writes the string `s` to the file descriptor `fd`
 * 
 * @param s The string to be written
 * 
 * @param fd The file descriptor to which the character will be written
 */
void	ft_putstr_fd(char *s, int fd)
{
	int	count;

	count = 0;
	while (s[count] != '\0')
	{
		write (fd, &s[count], 1);
		count++;
	}
}
