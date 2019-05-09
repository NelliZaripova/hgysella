/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgysella <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 19:18:13 by hgysella          #+#    #+#             */
/*   Updated: 2018/12/02 13:29:20 by hgysella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strnstr(const char *h, const char *n, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	if (n[i] == '\0')
		return ((char *)h);
	while (h[i] && i < len)
	{
		j = 0;
		if (h[i] == n[j])
		{
			k = i;
			while (n[j] && h[k] && k < len)
				if (h[++k] != n[++j])
					break ;
		}
		if (n[j] == '\0')
			return ((char *)h + (k - j));
		i++;
	}
	return (NULL);
}
