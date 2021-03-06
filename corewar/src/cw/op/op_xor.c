/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_xor.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwinthei <jwinthei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 15:07:32 by jwinthei          #+#    #+#             */
/*   Updated: 2019/07/31 20:44:42 by jwinthei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cw.h"

void			op_xor(t_cw *cw, size_t i_car)
{
	if (cw_codage_validator(cw, i_car, XOR))
		return ;
	cw->pos = (cw->cod.arg.v1 == REG_CODE) ?\
				cw->car[i_car]->reg[cw->arg[0]] : cw->arg[0];
	cw->pos ^= (cw->cod.arg.v2 == REG_CODE) ?\
				cw->car[i_car]->reg[cw->arg[1]] : cw->arg[1];
	cw->car[i_car]->reg[cw->arg[2]] = cw->pos;
	cw->car[i_car]->carry = (cw->pos) ? 0 : 1;
	cw->car[i_car]->pc = PCV(cw->car[i_car]->pc + cw->step);
}
