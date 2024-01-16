/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naadou <naadou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 18:34:35 by naadou            #+#    #+#             */
/*   Updated: 2024/01/16 18:17:37 by naadou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <unistd.h>
# include <stdlib.h>
# include <stddef.h>
# include "libft/libft.h"

typedef struct s_data
{
	int	**a;
	int	**b;
	int	*hm_a;
	int	*hm_b;
	int	stack_size;
}	t_data;

void	sa(int **a, t_data *var);
void	sb(int **b, t_data *var);
void	pa(int **a, int **b, int ac, t_data *var);
void	pb(int **a, int **b, int ac, t_data *var);
void	ra(int **a, t_data *var, int flag);
void	rb(int **b, t_data *var, int flag);
void	rra(int **a, t_data *var, int flag);
void	rrb(int **b, t_data *var, int flag);
void	rr(t_data *var);
void	rrr(t_data *var);

int		error(t_data var, char **av);
void	error_exit(void);

int		is_sorted(t_data *x);

void	algorithme(t_data *x);

int		move(int a, int b, int flag, t_data *x);

int		**bubble_sort(int **stack, int len_b);
void	sort(t_data *x);

int		stack_len(int *stack);
int		str_len(char **stack);

void	free_t_data(t_data *x);
void	free_integers(char **strs, int size);
void	free_stack_clone(int **x, int len);
void	free_strings(char *s1, char *s2);
void	free_previous(t_data *x, int flag);

void	ft_call(char *str, t_data *x);
void	read_instructions(t_data *var);

void	sa_bonus(int **a, t_data *var);
void	sb_bonus(int **b, t_data *var);
void	ss_bonus(t_data *var);
void	pa_bonus(int **a, int **b, int ac, t_data *var);
void	pb_bonus(int **a, int **b, int ac, t_data *var);
void	ra_bonus(int **a, t_data *var);
void	rb_bonus(int **b, t_data *var);
void	rra_bonus(int **a, t_data *var);
void	rrb_bonus(int **b, t_data *var);
void	rr_bonus(t_data *var);
void	rrr_bonus(t_data *var);

#endif