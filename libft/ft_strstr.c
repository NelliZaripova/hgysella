/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgysella <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 18:25:31 by hgysella          #+#    #+#             */
/*   Updated: 2018/11/30 19:21:31 by hgysella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strstr(const char *h, const char *n)
{
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	if (n[i] == '\0')
		return ((char *)h);
	while (h[i])
	{
		j = 0;
		if (h[i] == n[j])
		{
			k = i;
			while (n[j] && h[k])
				if (h[++k] != n[++j])
					break ;
		}
		if (n[j] == '\0')
			return ((char *)h + (k - j));
		i++;
	}
	return (NULL);
}
