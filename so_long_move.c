/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_move.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalwahei <jalwahei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 14:42:11 by jalwahei          #+#    #+#             */
/*   Updated: 2023/02/07 19:49:27 by jalwahei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	go_right(t_v *v)
{
	if (v->map[v->current_x][v->current_y + 1] == '0')
	{
		v->move_count++;
		ft_printf("move - right: %d \n", v->move_count);
		v->map[v->current_x][v->current_y] = '0';
		v->map[v->current_x][v->current_y + 1] = 'P';
		re_map(v);
	}
	else if (v->map[v->current_x][v->current_y + 1] == 'C')
	{
		v->move_count++;
		ft_printf("move - right: %d \n", v->move_count);
		v->map[v->current_x][v->current_y] = '0';
		v->map[v->current_x][v->current_y + 1] = 'P';
		re_map(v);
	}
	else if (v->map[v->current_x][v->current_y + 1] == 'E')
	{
		if (validation_c(v) == 0)
		{
			v->move_count++;
			ft_printf("move - right: %d \n", v->move_count);
			exit(0);
		}
	}
}

static void	go_up(t_v *v)
{
	if (v->map[v->current_x - 1][v->current_y] == '0')
	{
		v->move_count++;
		ft_printf("move - up: %d \n", v->move_count);
		v->map[v->current_x][v->current_y] = '0';
		v->map[v->current_x - 1][v->current_y] = 'P';
		re_map(v);
	}
	else if (v->map[v->current_x - 1][v->current_y] == 'C')
	{
		v->move_count++;
		ft_printf("move - up: %d \n", v->move_count);
		v->map[v->current_x][v->current_y] = '0';
		v->map[v->current_x - 1][v->current_y] = 'P';
		re_map(v);
	}
	else if (v->map[v->current_x - 1][v->current_y] == 'E')
	{
		if (validation_c(v) == 0)
		{
			v->move_count++;
			ft_printf("move - up: %d \n", v->move_count);
			exit(0);
		}
	}
}

static void	go_left(t_v *v)
{
	if (v->map[v->current_x][v->current_y - 1] == '0')
	{
		v->move_count++;
		ft_printf("move - left: %d \n", v->move_count);
		v->map[v->current_x][v->current_y] = '0';
		v->map[v->current_x][v->current_y - 1] = 'P';
		re_map(v);
	}
	else if (v->map[v->current_x][v->current_y - 1] == 'C')
	{
		v->move_count++;
		ft_printf("move - left: %d \n", v->move_count);
		v->map[v->current_x][v->current_y] = '0';
		v->map[v->current_x][v->current_y - 1] = 'P';
		re_map(v);
	}
	else if (v->map[v->current_x][v->current_y - 1] == 'E')
	{
		if (validation_c(v) == 0)
		{
			v->move_count++;
			ft_printf("move - left: %d \n", v->move_count);
			exit(0);
		}
	}
}

static void	go_down(t_v *v)
{
	if (v->map[v->current_x + 1][v->current_y] == '0')
	{
		v->move_count++;
		ft_printf("move - down: %d \n", v->move_count);
		v->map[v->current_x][v->current_y] = '0';
		v->map[v->current_x + 1][v->current_y] = 'P';
		re_map(v);
	}
	else if (v->map[v->current_x + 1][v->current_y] == 'C')
	{
		v->move_count++;
		ft_printf("move - down: %d \n", v->move_count);
		v->map[v->current_x][v->current_y] = '0';
		v->map[v->current_x + 1][v->current_y] = 'P';
		re_map(v);
	}
	else if (v->map[v->current_x + 1][v->current_y] == 'E')
	{
		if (validation_c(v) == 0)
		{
			v->move_count++;
			ft_printf("move - down: %d \n", v->move_count);
			exit (0);
		}		
	}
}

int	move_naruto_image(int keycode, t_v *v)
{
	if (keycode == 2 || keycode == 124)
	{
		go_right(v);
	}
	if (keycode == 13 || keycode == 126)
	{
		go_up(v);
	}
	if (keycode == 0 || keycode == 123)
	{
		go_left(v);
	}
	if (keycode == 1 || keycode == 125)
	{
		go_down(v);
	}
	if (keycode == 53)
		ft_exit(v);
	return (0);
}
