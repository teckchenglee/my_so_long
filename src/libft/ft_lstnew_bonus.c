/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlee <tlee@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 19:04:58 by tlee              #+#    #+#             */
/*   Updated: 2024/07/25 19:29:07 by tlee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Create a new list element with the given content
 * 
 * This function allocates memory for a new list element, initializes its
 * content with the provided 'content', sets its next pointer to NULL, and
 * returns a pointer to the newly created element. If memory allocation fails,
 * return NULL
 * 
 * @param content The content to be stored in the new list element
 * 
 * @return A pointer to the newly created list element,
 * or NULL if memory allocation fails
 */
t_list	*ft_lstnew(void *content)
{
	t_list	*element;

	element = (t_list *)malloc (sizeof(t_list));
	if (!element)
		return (NULL);
	element->content = content;
	element->next = NULL;
	return (element);
}
