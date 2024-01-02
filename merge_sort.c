/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naadou <naadou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 15:27:09 by naadou            #+#    #+#             */
/*   Updated: 2024/01/02 19:28:57 by naadou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	merge(int ac, t_data *var)
{
	int			i;
	static int	x;
	int			n1;
	int			n2;
	int			l_a;
	int			l_b;

	if (!x)
		x = -1;
	i = 0;
	l_a = stack_len(var->hm_a) - 1;
	// if (l_a - 1 < 0)
	// 	return ;
	// print_stack(*var);
	// return ;
	n1 = var->a[l_a][1];
	/*spam PA as long as we have the same number in the hash map
	 and we stop pushing to the b stack when we encounter a
	 different number in the hash map.
	*/
	while (n1 == var->a[l_a][1])
	{
		pb(var->a, var->b, ac, var);
		l_a--;
	}
	n2 = var->a[l_a][1];
	/*we will be comparing and top integer of both the satcks and moving 
	 integersform stackb to a until b is empty
	*/
	// print_stack(*var);
	while (stack_len(var->hm_b) - 1 >= 0 && var->a[stack_len(var->hm_a) - 1][1] == n2)
	{
		l_a = stack_len(var->hm_a) - 1;
		l_b = stack_len(var->hm_b) - 1;
		if (var->a[l_a][0] <= var->b[0][0])
		{
			var->a[l_a][1] = x;
			ra(var->a, var);
		}
		else
		{
			rrb(var->b, var);
			pa(var->a, var->b, ac, var);
			var->a[l_a + 1][1] = x;
			ra(var->a, var);
		}
	}
	while (var->a[stack_len(var->hm_a) - 1][1] == n2)
	{
		l_a = stack_len(var->hm_a) - 1;
		var->a[l_a][1] = x;
		ra(var->a, var);
	}
	while (stack_len(var->hm_b))
	{
		rrb(var->b, var);
		pa(var->a, var->b, ac, var);
		l_a = stack_len(var->hm_a) - 1;
		var->a[l_a][1] = x;
		ra(var->a, var);
	}
	// print_stack(*var);
	// printf("+++++++++++++++++++++\n\n\n");
	x--;
	/*until we have the same group in the whole stack we will
	 not stop and we will keep on merging
	*/
	n1 = var->a[0][1];
	while (i < ac && var->a[i][1] == n1)
		i++;
	if (i != (ac))
		merge(ac, var);
	// printf("sum of actions is:  %d\n", z);
}
