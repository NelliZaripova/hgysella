/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgysella <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 19:29:22 by hgysella          #+#    #+#             */
/*   Updated: 2018/12/01 19:58:53 by hgysella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void*, size_t))
{
	while (*alst)
	{
		del((*alst)->content, (*alst)->content_size);
		free((*alst));
		(*alst) = (*alst)->next;
	}
	(*alst) = NULL;
}
