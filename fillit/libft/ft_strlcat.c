/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgysella <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 19:14:47 by hgysella          #+#    #+#             */
/*   Updated: 2018/11/29 18:09:25 by hgysella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t n)
{
	size_t	i;
	size_t	j;
	size_t	k;
	size_t	jj;

	i = ft_strlen(src);
	j = ft_strlen(dst);
	jj = j;
	if (j >= n)
		return (i + n);
	else
	{
		k = 0;
		if (n != 0)
		{
			while (j < n - 1 && src[k])
			{
				dst[j] = src[k];
				k++;
				j++;
			}
			dst[j] = '\0';
		}
		return (i + jj);
	}
}
