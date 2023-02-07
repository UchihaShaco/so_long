/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_val.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalwahei <jalwahei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 14:01:20 by jalwahei          #+#    #+#             */
/*   Updated: 2023/02/07 19:49:31 by jalwahei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	valid_p_c_e(t_v *v)
{
	int	i;

	i = 0;
	while (i < v->n_lines)
	{
		v->l = 0;
		while (v->l < (v->col_s - 1))
		{
			if (v->map[i][v->l] == 'C')
				v->c_count++;
			if (v->map[i][v->l] == 'P')
				v->p_count++;
			if (v->map[i][v->l] == 'E')
				v->e_count++;
			v->l++;
		}
		i++;
	}
	if (v->c_count < 1 || v->p_count != 1 || v->e_count != 1)
	{
		ft_printf("ERROR MAP\n");
		ft_exit(v);
	}
	return (1);
}

int	val_rectangle(t_v *v)
{
	int	tmp;

	tmp = (v->col_s - 1) * v->n_lines;
	tmp = tmp / v->n_lines;
	if (tmp != (v->col_s - 1))
	{
		ft_printf("ERROR MAP \nshould be rectangular \n");
		ft_exit(v);
	}
	return (1);
}

int	validation_map(t_v *v)
{
	while (v->m < v->n_lines)
	{
		v->k = 0;
		while (v->k < (v->col_s - 1))
		{
			if (v->map[0][v->k] != '1' || v->map[v->n_lines - 1][v->k] != '1')
			{
				ft_printf("ERROR MAP\n");
				ft_exit(v);
			}
			if (v->map[v->m][0] != '1' || v->map[v->m][v->col_s - 2] != '1')
			{
				ft_printf("ERROR MAP\n");
				ft_exit(v);
			}
			v->k++;
		}
		v->m++;
	}
	if (valid_p_c_e(v) == 0 || val_rectangle(v) == 0)
		print_error();
	return (1);
}

static int	ber_f(char *str)
{
	int	i;

	i = 0;
	while (*str)
	{
		if (*str == '.')
		i++;
	str++;
	}
	return (i);
}

int	validation_ber(char *str)
{
	int	size;
	int	i;

	i = 0;
	size = ft_strlen(str);
	if (ber_f(str) > 1)
		return (0);
	if (str[size - 1] != 'r')
		return (0);
	if (str[size - 2] != 'e')
		return (0);
	if (str[size - 3] != 'b')
		return (0);
	if (str[size - 4] != '.')
		return (0);
	while (i < size)
		if (ft_isascii(str[i++]) != 1)
			return (0);
	return (1);
}
