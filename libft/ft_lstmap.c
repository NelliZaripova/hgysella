/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgysella <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/02 12:25:32 by hgysella          #+#    #+#             */
/*   Updated: 2018/12/02 19:34:37 by hgysella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_del(t_list *new)
{
	t_list *t;
	
	while (new)
	{
		t = new;
		new = new->next;
		free(t);
	}
}

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new;
	t_list	*tmp;

	if (!lst && !f)
		return (NULL);
	tmp = ft_lstnew(f(lst)->content, f(lst)->content_size);
	new = tmp;
	while (lst->next)
	{
		lst = lst->next;
		tmp->next = ft_lstnew(f(lst)->content, f(lst)->content_size);
		if (tmp->next == NULL)
			ft_del(new);
		tmp = tmp->next;
	}
	return (new);
}
