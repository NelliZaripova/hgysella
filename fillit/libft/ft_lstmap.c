/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgysella <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/02 12:25:32 by hgysella          #+#    #+#             */
/*   Updated: 2018/12/02 14:11:28 by hgysella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new;
	t_list	*tmp;

	if (!(new = (t_list *)malloc(sizeof(t_list))) || !lst)
		return (NULL);
	if (!(tmp = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	tmp = f(lst);
	new = tmp;
	while (lst->next)
	{
		lst = lst->next;
		tmp->next = f(lst);
		if (!tmp)
			return (NULL);
		tmp = tmp->next;
	}
	return (new);
}
