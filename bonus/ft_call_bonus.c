/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_call_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naadou <naadou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 20:10:39 by naadou            #+#    #+#             */
/*   Updated: 2024/01/05 21:13:23 by naadou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void	ft_call(char *str, t_data *x)
{
	if (str[0] == 's' && str[1] == 'a')
		sa_bonus(x->a, x);
	else if (str[0] == 's' && str[1] == 'b')
		sb_bonus(x->b, x);
	// else if (str[0] == 's' && str[1] == 's')
	// 	ss_bonus(a, b, 1); //'crying emoji'
	else if (str[0] == 'p' && str[1] == 'a')
		pa_bonus(x->a, x->b, x->stack_size, x);
	else if (str[0] == 'p' && str[1] == 'b')
		pb_bonus(x->a, x->b, x->stack_size, x);
	else if (str[0] == 'r' && str[1] == 'a')
		ra_bonus(x->a, x);
	else if (str[0] == 'r' && str[1] == 'b')
		rb_bonus(x->b, x);
	else if (str[0] == 'r' && str[1] == 'r')
		rr_bonus(x);
	else if (str[0] == 'r' && str[1] == 'r' && str[2] == 'a')
		rra_bonus(x->a, x);
	else if (str[0] == 'r' && str[1] == 'r' && str[2] == 'b')
		rrb_bonus(x->b, x);
	else if (str[0] == 'r' && str[1] == 'r' && str[2] == 'r')
		rrr_bonus(x);
	else
		error_exit();
}
