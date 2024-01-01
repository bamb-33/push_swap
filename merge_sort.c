/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naadou <naadou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 15:27:09 by naadou            #+#    #+#             */
/*   Updated: 2024/01/01 20:49:32 by naadou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	merge(int ac, t_data *var)
{
	static int	x;
	int			n1;
	int			n2;
	int			l_a;
	int			l_b;

	if (!x)
		x = 1;
	i = 0;
	l_a = stack_len(a) - 1;
	n1 = var.a[l_a][1];
	/*spam PA as long as we have the same number in the hash map
	 and we stop pushing to the b stack when we encounter a
	 different number in the hash map.
	*/
	while (n1 == var.a[l_a][1])
	{
		pb(var.a, var.b, ac, &var);
		l_a--;
	}
	n2 = var.a[l_a][1];
	/*we will be comparing and top integer of both the satcks and moving 
	 integersform stackb to a until b is empty
	*/
	while (var.a[stack_len(a) - 1][1] == n2 && var.b[stack_len(b) - 1][1] == n1)
	{
		l_a = stack_len(a) - 1;
		l_b = stack_len(b) - 1;
		rrb(var.b);
		if (var.a[l_a][0] <= b[l_b][0])
		{
			var.a[l_a][1] = x;
			ra(var.a, &var);
		}
		else
		{
			pa(var.a, var.b, ac, &var);
			var.a[l_b][1] = x;
			ra(var.a, &var);
		}
	}
	x++;
	/*until we have the same group in the whole stack we will
	 not stop and we will keep on merging
	*/
	tmp = a[0][1];
	while (a[i][1] == tmp)
		i++;
	if (i != (ac - 1))
		merge(ac, &var);
}
