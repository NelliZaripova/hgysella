/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgysella <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 17:14:30 by hgysella          #+#    #+#             */
/*   Updated: 2018/11/30 18:20:23 by hgysella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>

static	size_t	ft_len(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char			*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	len;
	char	*d;

	i = 0;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	len = ft_len(s1) + ft_len(s2);
	d = (char*)malloc(sizeof(char) * (len + 1));
	if (d == NULL)
		return (NULL);
	while (s1[i])
	{
		d[i] = s1[i];
		i++;
	}
	len = 0;
	while (s2[len])
	{
		d[i] = s2[len];
		len++;
		i++;
	}
	d[i] = '\0';
	return (d);
}
