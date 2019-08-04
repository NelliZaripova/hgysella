/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_lldi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwinthei <jwinthei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 15:06:47 by jwinthei          #+#    #+#             */
/*   Updated: 2019/08/01 17:02:23 by jwinthei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cw.h"

void			op_lldi(t_cw *cw, size_t i_car)
{
	if (cw_codage_validator(cw, i_car, LLDI))
		return ;
	cw->arg[0] = (cw->cod.arg.v1 == REG_CODE) ?\
				cw->car[i_car]->reg[cw->arg[0]] : cw->arg[0];
	cw->arg[1] = (cw->cod.arg.v2 == REG_CODE) ?\
				cw->car[i_car]->reg[cw->arg[1]] : cw->arg[1];
	cw->pos = PCV(cw->arg[0] + cw->arg[1] + cw->car[i_car]->pc);
	cw->pos = cw_code_to_byte(cw->map, cw->pos + REG_SIZE, REG_SIZE);
	cw->car[i_car]->reg[cw->arg[2]] = cw->pos;
	cw->car[i_car]->carry = (cw->pos) ? 0 : 1;
	cw->car[i_car]->pc = PCV(cw->car[i_car]->pc + cw->step);
}
