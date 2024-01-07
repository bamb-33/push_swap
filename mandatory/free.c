/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naadou <naadou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 10:02:27 by naadou            #+#    #+#             */
/*   Updated: 2024/01/07 19:24:25 by naadou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void	free_t_data(t_data x)
{
	int	i;

	i = 0;
	while (i < x.stack_size)
	{
		free(x.a[i]);
		free(x.b[i]);
		i++;
	}
	free(x.a);
	free(x.b);
	free(x.hm_a);
	free(x.hm_b);
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
