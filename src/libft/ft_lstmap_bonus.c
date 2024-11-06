/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlee <tlee@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 18:26:45 by tlee              #+#    #+#             */
/*   Updated: 2024/07/25 20:12:00 by tlee             ###   ########.fr       */
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
static t_list	*ft_lst_new(void *content)
{
	t_list	*element;

	element = (t_list *)malloc (sizeof(t_list));
	if (!element)
		return (NULL);
	element->content = content;
	element->next = NULL;
	return (element);
}

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
static void	ft_lst_clear(t_list **lst, void (*del)(void*))
{
	if (!lst || !del || !(*lst))
		return ;
	ft_lstclear(&(*lst)->next, del);
	(del)((*lst)->content);
	free(*lst);
	*lst = NULL;
}

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
static void	ft_lst_addback(t_list **lst, t_list *new)
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

/**
 * @brief Applies a function to each element of a list and creates a new list 
 * with the result
 * 
 * This function iterates through the list pointed to by `lst`, applies the
 * function `f` to the content of each element, and creates a new list with 
 * the results. If any memory allocation fails during the process, or if the
 * function `f` returns NULL for any element's content, it deletes the new
 * list and returns NULL.
 * 
 * @param lst A pointer to the first element of the list to the mapped
 * 
 * @param f The function to apply to the content of each element
 * This function is called with a pointer to the content of each element.
 * 
 * @param del The deletion function used to free the content of each element
 * in case of failure
 * This function is called with a pointer to the content of each element.
 * 		If NULL, no deletion is performed on the content.
 * 
 * @return A pointer to the first element of the new list, or NULL if any
 * failure occurs
 */
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*tmp;
	void	*mapped_content;

	if (!lst || !f || !del)
		return (NULL);
	new_list = NULL;
	while (lst)
	{
		mapped_content = f(lst->content);
		if (!mapped_content)
			ft_lst_clear (&new_list, del);
		tmp = ft_lst_new(mapped_content);
		if (!tmp)
		{
			ft_lst_clear(&new_list, del);
			del(mapped_content);
			return (NULL);
		}
		ft_lst_addback(&new_list, tmp);
		lst = lst->next;
	}
	return (new_list);
}
