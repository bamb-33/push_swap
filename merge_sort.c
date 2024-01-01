/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naadou <naadou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 15:27:09 by naadou            #+#    #+#             */
/*   Updated: 2024/01/01 18:51:18 by naadou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	merge(int *a, int *b, int ac, int *golden_hm, t_data var)
{
	int	i;
	int	tmp;

	i = 0;
	while (i < ac)
	{
		golden_hm[i] = i;
		i++;
	}
	tmp = golden_hm[0];
	/*spam PA as long as we have the same number in the hash map
	 and we stop pushing to the b stack when we encounter a
	 different number in the hash map.
	*/
	while (tmp == golden_hm[i])
	{
		pb(a, b, ac, &var);
		i++;
	}
	/*we will be comparing and top integer of both the satcks and moving 
	 integersform stackb to a until b is empty
	*/
	while (stack_len(b))
	{
		rrb(b);
		if (a[0] <= b[0])
			ra(a, &var);
		else
		{
			pa(a, b, ac, &var);
			ra(a, &var);
		}
	}
	/*until we have the same group in the whole stack we will
	 not stop and we will keep on merging
	*/
	tmp = golden_hm[0];
	while (golden_hm[i] == tmp)
		i++;
	if (i != (ac - 1))
		merge(a, b, ac, golden_hm);
}
