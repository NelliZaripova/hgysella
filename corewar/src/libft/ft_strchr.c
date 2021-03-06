/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwinthei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 17:20:35 by jwinthei          #+#    #+#             */
/*   Updated: 2019/03/23 16:59:12 by jwinthei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strchr(const char *src, int c)
{
	while (1)
	{
		if (*src == c)
			return (char*)(src);
		if (*src == '\0')
			break ;
		src++;
	}
	return (NULL);
}
