/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_valid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalwahei <jalwahei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 16:48:45 by jalwahei          #+#    #+#             */
/*   Updated: 2023/02/07 19:49:33 by jalwahei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	valid_dif_char(t_v *v)
{
	int	j;

	j = 0;
	while (v->c < v->n_lines)
	{
		j = 0;
		while (j < (v->col_s - 1))
		{
			if (v->map[v->c][j] == '1' || v->map[v->c][j] == '0')
				;
			else if (v->map[v->c][j] == 'P' || v->map[v->c][j] == 'C')
				;
			else if (v->map[v->c][j] == 'E')
				;
			else
			{
				ft_printf("ERROR MAP \n");
				ft_exit(v);
			}
			j++;
		}
		v->c++;
	}
	return (1);
}

void	print_error(void)
{
	ft_printf("ERROR \n");
	exit (0);
}

int	ft_exit(t_v *v)
{
	free(v);
	exit(0);
	return (0);
}

int	validation_c(t_v *v)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < v->n_lines)
	{
		j = 0;
		while (j < (v->col_s - 1))
		{
			if (v->map[i][j] == 'C')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
