/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_call_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naadou <naadou@student.3.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 20:10:39 by naadou            #+#    #+#             */
/*   Updated: 2024/01/06 20:20:58 by naadou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void	error_cmd(t_data *x)
{
	free_t_data(x);
	write(2, "Error\n", 6);
	exit(1);
}

void	ft_call(char *str, t_data *x)
{
	if (!ft_strncmp(str, "sa\n", 3))
		sa_bonus(x->a, x);
	else if (!ft_strncmp(str, "sb\n", 3))
		sb_bonus(x->b, x);
	else if (!ft_strncmp(str, "ss\n", 3))
		ss_bonus(x);
	else if (!ft_strncmp(str, "pa\n", 3))
		pa_bonus(x->a, x->b, x->stack_size, x);
	else if (!ft_strncmp(str, "pb\n", 3))
		pb_bonus(x->a, x->b, x->stack_size, x);
	else if (!ft_strncmp(str, "ra\n", 3))
		ra_bonus(x->a, x);
	else if (!ft_strncmp(str, "rb\n", 3))
		rb_bonus(x->b, x);
	else if (!ft_strncmp(str, "rr\n", 3))
		rr_bonus(x);
	else if (!ft_strncmp(str, "rra\n", 4))
		rra_bonus(x->a, x);
	else if (!ft_strncmp(str, "rrb\n", 4))
		rrb_bonus(x->b, x);
	else if (!ft_strncmp(str, "rrr\n", 4))
		rrr_bonus(x);
	else
		error_cmd(x);
}

void	read_instructions(t_data *var)
{
	char	*instructions;

	instructions = get_next_line(0);
	while (instructions)
	{
		ft_call(instructions, var);
		free (instructions);
		instructions = get_next_line(0);
	}
}
