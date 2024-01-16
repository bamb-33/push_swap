/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_a_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naadou <naadou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 16:11:40 by naadou            #+#    #+#             */
/*   Updated: 2024/01/09 15:55:44 by naadou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void	sa_bonus(int **a, t_data *var)
{
	int	*tmp;
	int	len;

	len = stack_len(var->hm_a);
	tmp = a[len - 1];
	a[len - 1] = a[len - 2];
	a[len - 2] = tmp;
}

void	pa_bonus(int **a, int **b, int ac, t_data *var)
{
	int	len_a;
	int	len_b;
	int	*tmp;

	len_a = stack_len(var->hm_a);
	len_b = stack_len(var->hm_b);
	if (len_a == ac)
		return ;
	else
	{
		tmp = a[len_a];
		a[len_a] = b[len_b - 1];
		b[len_b - 1] = tmp;
		var->hm_b[len_b - 1] = 0;
		var->hm_a[len_a] = 1;
	}
}

void	ra_bonus(int **a, t_data *var)
{
	int	i;
	int	len;
	int	*tmp1;
	int	*tmp2;

	i = 0;
	len = stack_len(var->hm_a);
	tmp1 = a[i];
	a[i] = a[len - 1];
	while (i < len - 1)
	{
		i++;
		if (i % 2 == 1)
		{
			tmp2 = a[i];
			a[i] = tmp1;
		}
		else
		{
			tmp1 = a[i];
			a[i] = tmp2;
		}
	}
}

void	rra_bonus(int **a, t_data *var)
{
	int	i;
	int	len;
	int	*tmp1;
	int	*tmp2;

	i = 0;
	len = stack_len(var->hm_a);
	tmp1 = a[len - 1];
	a[len - 1] = a[0];
	while (i < len - 1)
	{
		i++;
		if (i % 2 == 1)
		{
			tmp2 = a[len - i - 1];
			a[len - i - 1] = tmp1;
		}
		else
		{
			tmp1 = a[len - i - 1];
			a[len - i - 1] = tmp2;
		}
	}
}

void	rr_bonus(t_data *var)
{
	ra_bonus(var->a, var);
	rb_bonus(var->b, var);
}
