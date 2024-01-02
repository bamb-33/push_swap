/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naadou <naadou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 16:11:40 by naadou            #+#    #+#             */
/*   Updated: 2024/01/02 19:02:26 by naadou           ###   ########.fr       */
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

void	sb(int **b, t_data *var)
{
	int	*tmp;
	int	len;

	len = stack_len(var->hm_b);
	tmp = b[len - 1];
	b[len - 1] = b[len - 2];
	b[len - 2] = tmp;
	write(1, "sb\n", 3);
}

void	pa(int **a, int **b, int ac, t_data *var)
{
	int	len_a;
	int	len_b;

	len_a = stack_len(var->hm_a);
	len_b = stack_len(var->hm_b);
	if (len_a == ac)
		return ;
	else
	{
		a[len_a] = b[len_b - 1];
		var->hm_b[len_b - 1] = 0;
		var->hm_a[len_a] = 1;
	}
	write(1, "pa\n", 3);
}

void	pb(int **a, int **b, int ac, t_data *var)
{
	int	len_a;
	int	len_b;

	len_a = stack_len(var->hm_a);
	len_b = stack_len(var->hm_b);
	if (len_b == ac)
		return ;
	else
	{
		b[len_b] = a[len_a - 1];
		var->hm_a[len_a - 1] = 0;
		var->hm_b[len_b] = 1;
	}
	write(1, "pb\n", 3);
}

void	ra(int **a, t_data *var)
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
	write(1, "ra\n", 3);
}

void	rb(int **b, t_data *var)
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
	write(1, "rb\n", 3);
}

void	rra(int **a, t_data *var)
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
	write(1, "rra\n", 4);
}

void	rrb(int **b, t_data *var)
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
	write(1, "rrb\n", 4);
}
