/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naadou <naadou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 16:04:01 by naadou            #+#    #+#             */
/*   Updated: 2024/01/05 18:49:15 by naadou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

int	up(int *a, int *b, int flag, t_data *x)
{
	int	sum;

	sum = 0;
	while (*a != (stack_len(x->hm_a) - 1))
	{
		if (flag == 1)
			ra(x->a, x, 1);
		sum++;
		(*a)++;
	}
	while (*b != (stack_len(x->hm_b) - 1))
	{
		if (flag == 1)
			rb(x->b, x, 1);
		sum++;
		(*b)++;
	}
	return (sum);
}

int	down(int *a, int *b, int flag, t_data *x)
{
	int	sum;

	sum = 0;
	while (*a != -1)
	{
		if (flag == 1)
			rra(x->a, x, 1);
		sum++;
		(*a)--;
	}
	while (*b != -1)
	{
		if (flag == 1)
			rrb(x->b, x, 1);
		sum++;
		(*b)--;
	}
	return (sum);
}

int	same_direction_up(int *a, int *b, int flag, t_data *x)
{
	int	sum;
	int	len_b;
	int	len_a;

	len_a = stack_len(x->hm_a) - 1;
	len_b = stack_len(x->hm_b) - 1;
	sum = 0;
	while ((*a != len_a && *b != len_b))
	{
		if (flag == 1)
			rr(x);
		(*a)++;
		(*b)++;
		sum++;
	}
	return (sum);
}

int	same_direction_down(int *a, int *b, int flag, t_data *x)
{
	int	sum;
	int	len_b;
	int	len_a;

	len_a = stack_len(x->hm_a) - 1;
	len_b = stack_len(x->hm_b) - 1;
	sum = 0;
	while ((*a != -1 && *b != -1))
	{
		if (flag == 1)
			rrr(x);
		(*a)--;
		(*b)--;
		sum++;
	}
	return (sum);
}

int	move(int a, int b, int flag, t_data *x)
{
	int	ud_a;
	int	ud_b;
	int	sum;

	ud_a = 0;
	ud_b = 0;
	sum = 0;
	if (a < (stack_len(x->hm_a) - 1) / 2)
		ud_a = 1;
	if (b < (stack_len(x->hm_b) - 1) / 2)
		ud_b = 1;
	if (ud_a == ud_b)
	{
		if (ud_a == 0 && ud_b == 0)
			sum += same_direction_up(&a, &b, flag, x);
		else
			sum += same_direction_down(&a, &b, flag, x);
	}
	if (ud_a == 0 || ud_b == 0)
		sum += up(&a, &b, flag, x);
	else
		sum += down(&a, &b, flag, x);
	if (flag == 1)
		pb(x->a, x->b, x->stack_size, x);
	return (sum);
}
