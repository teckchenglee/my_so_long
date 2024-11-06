/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlee <tlee@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 20:55:32 by tlee              #+#    #+#             */
/*   Updated: 2024/06/12 14:53:59 by tlee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Return a pointer to the last element of a list
 * 
 * @param lst A pointer to the first element of the list
 * 
 * @return A pointer to the last element of the list,
 * or NULL if the list is empty
 */
t_list	*ft_lstlast(t_list *lst)
{
	t_list	*tmp;

	if (!lst)
		return (NULL);
	tmp = lst;
	while (tmp->next)
		tmp = tmp->next;
	return (tmp);
}
