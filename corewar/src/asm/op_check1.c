/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_check1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwinthei <jwinthei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 00:29:20 by jritchie          #+#    #+#             */
/*   Updated: 2019/08/01 20:42:05 by jwinthei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm_op.h"

char					get_map_pos(t_process *p, int pos)
{
	while (pos >= MEM_SIZE)
		pos -= MEM_SIZE;
	return (*(p->map + pos));
}

int						check_reg(int reg)
{
	return (reg > 0 && reg <= REG_NUMBER);
}

int						op_check(t_process *p)
{
	int			codage;

	codage = get_map_pos(p, (p->pc - p->map) + 1);
	if (p->op.id == LIVE || p->op.id == ZJMP || p->op.id == FORK ||
			p->op.id == LFORK)
		return (1);
	if (p->op.id > 15)
		return (0);
	return (g_op_tab[p->op.id].f_check(p));
}

int						op_check_live(t_process *p)
{
	(void)p;
	return (1);
}
