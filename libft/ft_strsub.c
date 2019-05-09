/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgysella <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 15:38:35 by hgysella          #+#    #+#             */
/*   Updated: 2018/11/30 18:19:20 by hgysella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*d;

	i = 0;
	if (s == NULL)
		return (NULL);
	d = (char*)malloc(sizeof(char) * (len + 1));
	if (d == NULL)
		return (NULL);
	while (i < len)
	{
		d[i] = s[start];
		i++;
		start++;
	}
	d[i] = '\0';
	return (d);
}
