/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlee <tlee@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 18:17:24 by tlee              #+#    #+#             */
/*   Updated: 2024/06/12 14:51:53 by tlee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Iterates over each element of a list and applies a given function to
 * its content
 * 
 * @param lst A pointer to the first element of the list
 * 
 * @param f The function to apply to the conten of each element
 */
void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*tmp;

	if (!lst)
		return ;
	tmp = lst;
	while (tmp)
	{
		f(tmp->content);
		tmp = tmp->next;
	}
}
