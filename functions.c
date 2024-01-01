/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naadou <naadou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 16:11:40 by naadou            #+#    #+#             */
/*   Updated: 2024/01/01 18:52:18 by naadou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	sa(int *a, t_data *var)
{
	int	tmp;
	int	len;

	len = stack_len(var->hm_a);
	tmp = a[len - 1];
	a[len - 1] = a[len - 2];
	a[len - 2] = tmp;
}

void	sb(int *b, t_data *var)
{
	int	tmp;
	int	len;

	len = stack_len(var->hm_b);
	tmp = b[len - 1];
	b[len - 1] = b[len - 2];
	b[len - 2] = tmp;
}

void	pa(int *a, int *b, int ac, t_data *var)
{
	int	len_a;
	int	len_b;

	len_a = stack_len(var->hm_a);
	len_b = stack_len(var->hm_b);
	if (len_a == ac)
		printf("stack is full");
	else
	{
		a[len_a] = b[len_b - 1];
		var->hm_b[len_b - 1] = 0;
		var->hm_a[len_a] = 1;
	}
}

void	pb(int *a, int *b, int ac, t_data *var)
{
	int	len_a;
	int	len_b;

	len_a = stack_len(var->hm_a);
	len_b = stack_len(var->hm_b);
	if (len_b == ac)
		printf("stack is full");
	else
	{
		a[len_b] = b[len_a - 1];
		var->hm_a[len_a - 1] = 0;
		var->hm_b[len_b] = 1;
	}
}

void	ra(int *a, t_data *var)
{
	int	i;
	int	len;
	int	tmp1;
	int	tmp2;

	i = 0;
	len = stack_len(var->hm_a);
	tmp1 = a[len - 1];
	a[len - 1] = a[0];
	len--;
	while (len - 1 > 0)
	{
		if (i % 2 == 0)
		{
			tmp2 = a[len - 1];
			a[len - 1] = tmp1;
		}
		else
		{
			tmp1 = a[len - 1];
			a[len - 1] = tmp2;
		}
		i++;
		len--;
	}
}

void	rb(int *b, t_data *var)
{
	int	i;
	int	len;
	int	tmp1;
	int	tmp2;

	i = 0;
	len = stack_len(var->hm_b);
	tmp1 = b[len - 1];
	b[len - 1] = b[0];
	len--;
	while (len - 1 > 0)
	{
		if (i % 2 == 0)
		{
			tmp2 = b[len - 1];
			b[len - 1] = tmp1;
		}
		else
		{
			tmp1 = b[len - 1];
			b[len - 1] = tmp2;
		}
		i++;
		len--;
	}
}

void	rra(int *a, t_data *var)
{
	int	i;
	int	len;
	int	tmp1;
	int	tmp2;

	i = 0;
	len = stack_len(var->hm_a);
	tmp1 = a[i];
	a[i] = a[len - 1];
	i++;
	while (i < len - 1)
	{
		if (i % 2 == 0)
		{
			tmp2 = a[i];
			a[i] = tmp1;
		}
		else
		{
			tmp1 = a[i];
			a[i] = tmp2;
		}
		i++;
	}
}

void	rrb(int *b, t_data *var)
{
	int	i;
	int	len;
	int	tmp1;
	int	tmp2;

	i = 0;
	len = stack_len(var->hm_b);
	tmp1 = b[i];
	b[i] = b[len - 1];
	len--;
	while (i > len - 1)
	{
		if (i % 2 == 0)
		{
			tmp2 = b[i];
			b[i] = tmp1;
		}
		else
		{
			tmp1 = b[i];
			b[i] = tmp2;
		}
		i++;
	}
}
