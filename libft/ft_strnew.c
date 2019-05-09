/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgysella <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 18:56:18 by hgysella          #+#    #+#             */
/*   Updated: 2018/12/01 14:50:42 by hgysella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "libft.h"

char	*ft_strnew(size_t size)
{
	void	*s;

	if (size == (size_t)(-1))
		return (NULL);
	s = (char*)malloc(size + 1);
	if (s == NULL)
		return (NULL);
	ft_memset(s, (int)'\0', size + 1);
	return (s);
}
