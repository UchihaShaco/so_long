/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalwahei <jalwahei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 17:02:03 by jalwahei          #+#    #+#             */
/*   Updated: 2023/02/07 19:48:41 by jalwahei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

#include "mlx/mlx.h"
#include <stdio.h>

void	fill_map(t_v *v, int i, int j)
{
	while (i < v->n_lines)
	{
		j = 0;
		v->x = 0;
		while (j < (v->col_s - 1))
		{
			add_floor(*v);
			if (v->map[i][j] == '1')
				add_wall(v->map[i][j], *v);
			else if (v->map[i][j] == 'C')
				add_collectible(*v);
			else if (v->map[i][j] == 'P')
			{
				add_naruto(*v);
				v->current_x = i;
				v->current_y = j;
			}
			else if (v->map[i][j] == 'E')
				add_saski(*v);
			v->x += 64;
			j++;
		}
		i++;
		v->y += 64;
	}
}

int	re_map(t_v *v)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	v->y = 0;
	fill_map(v, i, j);
	mlx_hook(v->mlx_win, 17, 0, ft_exit, v);
	return (0);
}

int	find_column_and_line_size(int fd, t_v *v)
{
	int		line_s;
	int		column_size;
	char	c;

	column_size = 0;
	line_s = 0;
	while (read(fd, &c, 1))
	{
		if (c == '\n')
			line_s++;
		column_size++;
	}
	line_s = line_s + 1;
	column_size = (column_size / line_s) + 1 ;
	v->col_s = column_size;
	v->n_lines = line_s;
	return (line_s);
}

void	get_map(int fd, int line_s, t_v *v)
{
	char	*line;
	int		i;

	v->k = 0;
	v->m = 0;
	v->l = 0;
	v->c = 0;
	i = 0;
	v->c_count = 0;
	v->p_count = 0;
	v->e_count = 0;
	v->move_count = 0;
	v->map = malloc(sizeof(char *) * (v->col_s * line_s) + line_s);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		v->map[i++] = line;
	}
}

int	main(int argc, char **argv)
{
	int		fd;
	int		line_s;
	t_v		*v;

	if (argc != 2)
		return (0);
	if (validation_ber(argv[1]) == 0)
		print_error();
	v = malloc(sizeof(t_v));
	v->mlx = mlx_init();
	fd = open(argv[1], O_RDONLY);
	line_s = find_column_and_line_size(fd, v);
	v->mlx_win = mlx_new_window(v->mlx, (v->col_s - 1) * 64, line_s * 64, "K");
	close(fd);
	fd = open(argv[1], O_RDONLY);
	get_map(fd, line_s, v);
	validation_map(v);
	re_map(v);
	mlx_key_hook(v->mlx_win, move_naruto_image, v);
	mlx_loop(v->mlx);
	return (0);
}
