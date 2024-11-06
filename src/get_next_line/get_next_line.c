/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlee <tlee@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 20:58:25 by tlee              #+#    #+#             */
/*   Updated: 2024/06/20 14:18:55 by tlee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/**
 * @brief Reads from a file descriptor until a newline character or EOF is
 * encountered
 * 
 * This function reads data from the file descriptor `fd` into a dynamically
 * allocated string `str`, appending each read chunk until a newline character
 * is found or end of the file.
 * 
 * @param fd The file descriptor to read from
 * @param str A pointer to a string where the read data will be stored
 * @return A pointer to the string containing the data from 'fd'
 * Return NULL when allocation fails or no more data to read
 */
char	*ft_readline(int fd, char *str)
{
	char	*new_str;
	ssize_t	r_bytes;
	char	*buffer;

	buffer = (char *) malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	r_bytes = 1;
	while (r_bytes > 0)
	{
		r_bytes = read(fd, buffer, BUFFER_SIZE);
		if (r_bytes < 0)
			return (free(str), free(buffer), NULL);
		buffer[r_bytes] = '\0';
		if (!str)
			str = ft_strdup("");
		new_str = ft_strjoin(str, buffer);
		free(str);
		str = new_str;
		if (!str)
			return (free(buffer), NULL);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	return (free(buffer), str);
}

/**
 * @brief Extracts a line from the beginning of a given string up to the newline
 * character
 * 
 * @param str The input string from which to extract a line.
 * @return A pointer to a newly allocated string containing the extracted line
 * or the entire string if no newline character is found. 
 * Returns NULL if `str` is NULL or empty, or if memory allocation fails. 
 */
char	*ft_extractline(char *str)
{
	char	*tmp;
	int		count;

	if (!str || !*str)
		return (NULL);
	count = 0;
	while (str[count] && str[count] != '\n' )
		count++;
	if (str[count] == '\n' && str[count] != '\0' )
		count += 1;
	else
		return (ft_strdup(str));
	tmp = (char *)malloc ((count + 1) * sizeof(char));
	if (!tmp)
		return (NULL);
	tmp[count] = '\0';
	while (count--)
		tmp[count] = str[count];
	return (tmp);
}

/**
 * @brief Removes the first line from the input string and returns the remainder
 * 
 * @param str The input string from which to remove the first line
 * @return A pointer to a newly allocated string containing the remainder of
 * `str` after removing the first line.
 * Returns NULL if `str` is NULL or if memory allocation fails.
 */
char	*ft_removeline(char *str)
{
	char	*remain;
	size_t	count;

	if (!str)
		return (NULL);
	count = 0;
	while (str[count] && str[count] != '\n')
		count++;
	if (!str[count])
		return (free(str), NULL);
	count++;
	remain = ft_strdup(str + count);
	return (free(str), remain);
}

/**
 * @brief Get the next line object
 * 
 * @param fd The file descriptor from which to read the next line
 * @return A pointer to a newly allocated string containing the next line read
 * from `fd`.Returns NULL if `fd` is invalid, `BUFFER_SIZE` is less than or
 * equal to 0, or if memory allocation fails during processing
 * 
 * @note static variables have the property of preserving their value even after
 * they are out of their scope
 */
char	*get_next_line(int fd)
{
	char		*line;
	static char	*str = NULL;

	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	str = ft_readline(fd, str);
	if (!str)
		return (NULL);
	line = ft_extractline(str);
	if (!line)
	{
		free(str);
		str = NULL;
		return (NULL);
	}
	str = ft_removeline(str);
	return (line);
}
