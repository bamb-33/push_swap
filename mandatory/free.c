/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naadou <naadou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 10:02:27 by naadou            #+#    #+#             */
/*   Updated: 2024/01/09 16:46:01 by naadou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void	free_t_data(t_data *x)
{
	int	i;

	i = 0;
	while (i < x->stack_size)
	{
		free(x->a[i]);
		free(x->b[i]);
		i++;
	}
	free(x->a);
	free(x->b);
	free(x->hm_a);
	free(x->hm_b);
}

void	free_stack_clone(int **x, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		free(x[i]);
		i++;
	}
	free(x);
}

void	free_strings(char *s1, char *s2)
{
	free(s1);
	free(s2);
}

void	free_previous(t_data *x, int flag)
{
	int	i;

	i = 0;
	free(x->a);
	if (flag >= 2)
		free(x->b);
	if (flag >= 3)
	{
		while (i < x->stack_size)
			free(x->a[i++]);
	}
	i = 0;
	if (flag >= 4)
	{
		while (i < x->stack_size)
			free(x->b[i++]);
	}
	if (flag >= 5)
		free(x->hm_a);
	exit(1);
}
