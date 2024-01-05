/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_len.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naadou <naadou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 17:37:42 by naadou            #+#    #+#             */
/*   Updated: 2024/01/05 16:21:15 by naadou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	stack_len(int *stack)
{
	int	i;

	i = 0;
	while (stack[i] == 1)
		i++;
	return (i);
}

int	str_len(char **stack)
{
	int	i;

	i = 0;
	while (stack[i])
		i++;
	return (i);
}
