/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disasm_func.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwinthei <jwinthei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/26 09:13:15 by jritchie          #+#    #+#             */
/*   Updated: 2019/08/01 21:15:14 by jwinthei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DISASM_FUNC_H
# define DISASM_FUNC_H

# include "libft.h"
# include "op.h"
# define MAX(a, b) (a > b ? a : b)

void			disasm_func(int in, int out);
void			add_args(char *str, char cmd, unsigned char *bytes,\
												unsigned char args);
char			*ltoa_base(long long int n, int base);
long long int	ft_labs(long long int a);

#endif
