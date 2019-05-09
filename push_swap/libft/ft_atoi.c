/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgysella <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 20:48:32 by hgysella          #+#    #+#             */
/*   Updated: 2018/12/02 14:15:09 by hgysella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *str)
{
	int		rez;
	int		f;
	int		i;

	f = 1;
	rez = 0;
	i = 0;
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\v' \
			|| str[i] == '\f' || str[i] == '\r' || str[i] == '\t')
		i++;
	if (str[i] == '-')
		f = -1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i] >= '0' && str[i] <= '9' && str[i])
	{
		rez = rez * 10 + str[i] - '0';
		i++;
	}
	if ((unsigned int)rez > 2147483647 && f == 1)
		return (-1);
	if ((unsigned int)rez > 2147483648 && f == -1)
		return (0);
	return (f * rez);
}
