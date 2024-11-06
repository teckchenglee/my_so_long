/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlee <tlee@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 20:31:25 by tlee              #+#    #+#             */
/*   Updated: 2024/06/12 15:02:54 by tlee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Count the number of nodes in a list
 * 
 * This function traverses the list pointed to by 'lst' and counts the number of
 * elements it contains. It return the count of element in the list
 *  
 * @param lst A pointer to the first element of the list
 * 
 * @return The number of elements in the list
 */
int	ft_lstsize(t_list *lst)
{
	t_list	*tmp;
	int		count;

	tmp = lst;
	count = 0;
	while (tmp)
	{
		tmp = tmp -> next;
		count++;
	}
	return (count);
}
