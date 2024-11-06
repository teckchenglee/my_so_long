/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlee <tlee@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 18:10:05 by tlee              #+#    #+#             */
/*   Updated: 2024/06/12 15:50:13 by tlee             ###   ########.fr       */
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
void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
