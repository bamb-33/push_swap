/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_b_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naadou <naadou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 17:34:56 by naadou            #+#    #+#             */
/*   Updated: 2024/01/05 21:13:47 by naadou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void	sb_bonus(int **b, t_data *var)
{
	int	*tmp;
	int	len;

	len = stack_len(var->hm_b);
	tmp = b[len - 1];
	b[len - 1] = b[len - 2];
	b[len - 2] = tmp;
}

void	pb_bonus(int **a, int **b, int ac, t_data *var)
{
	int	len_a;
	int	len_b;
	int	*tmp;

	len_a = stack_len(var->hm_a);
	len_b = stack_len(var->hm_b);
	if (len_b == ac)
		return ;
	else
	{
		tmp = b[len_b];
		b[len_b] = a[len_a - 1];
		a[len_a - 1] = tmp;
		var->hm_a[len_a - 1] = 0;
		var->hm_b[len_b] = 1;
	}
}

void	rb_bonus(int **b, t_data *var)
{
	int	i;
	int	len;
	int	*tmp1;
	int	*tmp2;

	i = 0;
	len = stack_len(var->hm_b);
	tmp1 = b[i];
	b[i] = b[len - 1];
	while (len - 1 > 0)
	{
		i++;
		len--;
		if (i % 2 == 1)
		{
			tmp2 = b[i];
			b[i] = tmp1;
		}
		else
		{
			tmp1 = b[i];
			b[i] = tmp2;
		}
	}
}

void	rrb_bonus(int **b, t_data *var)
{
	int	i;
	int	len;
	int	*tmp1;
	int	*tmp2;

	i = 0;
	len = stack_len(var->hm_b);
	tmp1 = b[len - 1];
	b[len - 1] = b[0];
	while (len - 1 > 0)
	{
		i++;
		len--;
		if (i % 2 == 1)
		{
			tmp2 = b[len - 1];
			b[len - 1] = tmp1;
		}
		else
		{
			tmp1 = b[len - 1];
			b[len - 1] = tmp2;
		}
	}
}

void	rrr_bonus(t_data *var)
{
	rra(var->a, var, 0);
	rrb(var->b, var, 0);
}
