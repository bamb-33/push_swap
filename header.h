/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naadou <naadou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 18:34:35 by naadou            #+#    #+#             */
/*   Updated: 2024/01/07 20:51:59 by naadou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include "Libft/libft.h"

typedef struct s_data
{
	int	**a;
	int	**b;
	int	*hm_a;
	int	*hm_b;
	int	stack_size;
}	t_data;

//a_b_functions
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

//error
int		error(t_data var, char **av);
void	error_exit(void);
// long long int	ft_atoi(const char *str);

//big_stack
void	algorithme(t_data *x);

//move
int		move(int a, int b, int flag, t_data *x);

//small_stack
void	small_stack(t_data *x);

//sort
int		**bubble_sort(int **stack, int len_b);
void	a_sort(int a, t_data *x);
void	b_sort(int b, t_data *x);
int		is_a_sorted(t_data *x);
void	sort(t_data *x);

//stack_len
int		stack_len(int *stack);
int		str_len(char **stack);

//free
void	free_t_data(t_data x);
void	free_stack_clone(int **x, int len);
void	free_strings(char *s1, char *s2);

//bonus
// ft_call
void	ft_call(char *str, t_data *x);

//is_sorted
int		is_sorted(t_data *x);

//a_b_functions_bonus
void	sa_bonus(int **a, t_data *var);
void	sb_bonus(int **b, t_data *var);
void	pa_bonus(int **a, int **b, int ac, t_data *var);
void	pb_bonus(int **a, int **b, int ac, t_data *var);
void	ra_bonus(int **a, t_data *var);
void	rb_bonus(int **b, t_data *var);
void	rra_bonus(int **a, t_data *var);
void	rrb_bonus(int **b, t_data *var);
void	rr_bonus(t_data *var);
void	rrr_bonus(t_data *var);

//tmp
void	print_stack(t_data var);

#endif