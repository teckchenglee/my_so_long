/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlee <tlee@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 17:16:33 by tlee              #+#    #+#             */
/*   Updated: 2024/06/12 14:46:01 by tlee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Delete a single node from a linked list
 * 
 * This function delete the specified node from the linked list
 * 
 * @param lst Pointer to the node to be deleted
 * 
 * @param del Pointer to a function used to delete the content of the node
 */
void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	del(lst->content);
	free(lst);
}
