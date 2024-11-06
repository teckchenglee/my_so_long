/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlee <tlee@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 17:28:31 by tlee              #+#    #+#             */
/*   Updated: 2024/06/12 14:45:58 by tlee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Clears a list and frees the memory of its content using a specified
 * deletion function
 * 
 * @param lst A pointer to a pointer to the first element of the list
 * 
 * @param del The deletion function used to free the content of each element
 * 
 * @note It recursively calls itself with the address of the 'next' pointer
 * till the reaches the end of the list. And start deleting the node in
 * reverse order
 */
void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	if (!lst || !del || !(*lst))
		return ;
	ft_lstclear(&(*lst)->next, del);
	(del)((*lst)->content);
	free(*lst);
	*lst = NULL;
}
