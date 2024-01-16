/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_len.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naadou <naadou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 17:37:42 by naadou            #+#    #+#             */
/*   Updated: 2024/01/16 15:00:05 by naadou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

int	stack_len(int *stack)
{
	int	i;

	i = 0;
	while (stack[i] == 1)
		i++;
	return (i);
}

int	str_len(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
