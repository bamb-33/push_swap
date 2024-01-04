/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_len.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naadou <naadou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 17:37:42 by naadou            #+#    #+#             */
/*   Updated: 2024/01/04 17:38:36 by naadou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	**bubble_sort(int **stack, int len_b)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (i < len_b)
	{
		j = i + 1;
		while (j < len_b)
		{
			if (stack[i][0] > stack[j][0])
			{
				tmp = stack[i][0];
				stack[i][0] = stack[j][0];
				stack[j][0] = tmp;
				tmp = stack[i][1];
				stack[i][1] = stack[j][1];
				stack[j][1] = tmp;
			}
			j++;
		}
		i++;
	}
	return (stack);
}

int	stack_len(int *stack)
{
	int	i;

	i = 0;
	while (stack[i] == 1)
		i++;
	return (i);
}