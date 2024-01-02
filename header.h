/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naadou <naadou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 18:34:35 by naadou            #+#    #+#             */
/*   Updated: 2024/01/02 19:02:35 by naadou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"

typedef struct s_data
{
	int	**a;
	int	**b;
	int	*hm_a;
	int	*hm_b;
	int	stack_size;
}	t_data;

//functions
void	sa(int **a, t_data *var);
void	sb(int **b, t_data *var);
void	pa(int **a, int **b, int ac, t_data *var);
void	pb(int **a, int **b, int ac, t_data *var);
void	ra(int **a, t_data *var);
void	rb(int **b, t_data *var);
void	rra(int **a, t_data *var);
void	rrb(int **b, t_data *var);

//stack_len
int		stack_len(int *stack);

//merge
void	merge(int ac, t_data *var);

//tmp
void	print_stack(t_data var);

#endif