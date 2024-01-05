/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_functions.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naadou <naadou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 16:11:40 by naadou            #+#    #+#             */
/*   Updated: 2024/01/05 11:25:54 by naadou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	sa(int **a, t_data *var)
{
	int	t1;
	int	t2;
	int	len;

	len = stack_len(var->hm_a);
	t1 = a[len - 1][0];
	t2 = a[len - 1][1];
	a[len - 1][0] = a[len - 2][0];
	a[len - 1][1] = a[len - 2][1];
	a[len - 2][0] = t1;
	a[len - 2][1] = t2;
	write(1, "sa\n", 3);
}

void	pa(int **a, int **b, int ac, t_data *var)
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
	write(1, "pa\n", 3);
}

void	ra(int **a, t_data *var, int flag)
{
	int	i;
	int	len;
	int	*tmp1;
	int	*tmp2;

	i = 0;
	len = stack_len(var->hm_a);
	tmp1 = a[i];
	a[i] = a[len - 1];
	while (len - 1 > 0)
	{
		i++;
		len--;
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
	if (flag == 1)
		write(1, "ra\n", 3);
}

void	rra(int **a, t_data *var, int flag)
{
	int	i;
	int	len;
	int	*tmp1;
	int	*tmp2;

	i = 0;
	len = stack_len(var->hm_a);
	tmp1 = a[len - 1];
	a[len - 1] = a[0];
	while (len - 1 > 0)
	{
		i++;
		len--;
		if (i % 2 == 1)
		{
			tmp2 = a[len - 1];
			a[len - 1] = tmp1;
		}
		else
		{
			tmp1 = a[len - 1];
			a[len - 1] = tmp2;
		}
	}
	if (flag == 1)
		write(1, "rra\n", 4);
}

void	rr(t_data *var)
{
	ra(var->a, var, 0);
	rb(var->b, var, 0);
	write(1, "rr\n", 3);
}
