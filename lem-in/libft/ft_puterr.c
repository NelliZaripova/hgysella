/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puterr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwinthei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 15:58:42 by jwinthei          #+#    #+#             */
/*   Updated: 2019/02/27 16:44:13 by jwinthei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_puterr(int retv, const char *s)
{
	if (!s)
		return (0);
	write(2, s, ft_strlen(s));
	write(2, "\n", 1);
	return (retv);
}
