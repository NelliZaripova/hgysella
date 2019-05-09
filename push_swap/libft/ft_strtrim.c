/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgysella <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 19:05:17 by hgysella          #+#    #+#             */
/*   Updated: 2018/12/01 11:49:53 by hgysella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>

static size_t	ft_mlen(char const *s)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = 0;
	while (s[i])
		if ((s[i] == ' ') || (s[i] == '\n') || (s[i] == '\t'))
			i++;
		else
			break ;
	while (s[i])
	{
		len++;
		i++;
	}
	while (i > 0 && len > 0)
	{
		i--;
		if (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
			len--;
		else
			break ;
	}
	return (len);
}

char			*ft_strtrim(char const *s)
{
	size_t	l;
	size_t	j;
	size_t	i;
	char	*d;

	i = 0;
	j = 0;
	if (s == NULL)
		return (NULL);
	l = ft_mlen(s);
	d = (char*)malloc(sizeof(char) * (l + 1));
	if (d == NULL)
		return (NULL);
	while (s[i])
		if (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
			i++;
		else
			break ;
	while (j < l)
		d[j++] = s[i++];
	d[j] = '\0';
	return (d);
}
