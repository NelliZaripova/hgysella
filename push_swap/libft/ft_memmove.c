/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgysella <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 18:18:58 by hgysella          #+#    #+#             */
/*   Updated: 2018/11/30 18:53:51 by hgysella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	size_t					i;
	const unsigned char		*src1;
	unsigned char			*dst1;

	src1 = src;
	dst1 = dst;
	i = 0;
	if (src1 < dst1)
	{
		while ((int)n-- > 0)
			dst1[n] = src1[n];
	}
	else
		while (i < n)
		{
			dst1[i] = src1[i];
			i++;
		}
	return (dst1);
}
