/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlee <tlee@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 16:25:05 by tlee              #+#    #+#             */
/*   Updated: 2024/06/12 14:29:17 by tlee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Add the node 'new' at the end of the list
 * 
 * @param lst current list
 * 
 * @param new new node
 * 
 * @note It traverse the list till the last element and assign the next pointer
 * to new node to form a complete linked list
 */
void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*tmp;

	if (!lst || !new)
		return ;
	if (!(*lst))
	{
		*lst = new;
		return ;
	}
	tmp = *lst;
	while (tmp->next)
	{
		tmp = tmp->next;
	}
	tmp->next = new;
}
