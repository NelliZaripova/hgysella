/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgysella <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 17:17:51 by hgysella          #+#    #+#             */
/*   Updated: 2018/12/02 19:36:28 by hgysella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t i;

	if (dst == src)
		return (dst);
	i = 0;
	while (i < n)
	{
		((unsigned char*)dst)[i] = ((const unsigned char*)src)[i];
		i++;
	}
	return (dst);
}
