/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_images.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalwahei <jalwahei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 10:42:46 by jalwahei          #+#    #+#             */
/*   Updated: 2023/02/07 18:24:11 by jalwahei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	add_wall(char obj_name, t_v v)
{
	char	*relative_path;

	relative_path = "./assets/wall.xpm";
	v.img_s = 0;
	if (obj_name == '1')
	{
		v.img = mlx_xpm_file_to_image(v.mlx, relative_path, &v.img_s, &v.img_s);
		mlx_put_image_to_window(v.mlx, v.mlx_win, v.img, v.x, v.y);
	}
}

void	add_floor(t_v v)
{
	char	*relative_path;

	relative_path = "./assets/gras.xpm";
	v.img_s = 0;
	v.img = mlx_xpm_file_to_image(v.mlx, relative_path, &v.img_s, &v.img_s);
	mlx_put_image_to_window(v.mlx, v.mlx_win, v.img, v.x, v.y);
}

void	add_collectible(t_v v)
{
	char	*relative_path;

	relative_path = "./assets/ramen.xpm";
	v.img_s = 0;
	v.img = mlx_xpm_file_to_image(v.mlx, relative_path, &v.img_s, &v.img_s);
	mlx_put_image_to_window(v.mlx, v.mlx_win, v.img, v.x, v.y);
}

void	add_naruto(t_v v)
{
	char	*relative_path;

	relative_path = "./assets/player.xpm";
	v.img_s = 0;
	v.img = mlx_xpm_file_to_image(v.mlx, relative_path, &v.img_s, &v.img_s);
	mlx_put_image_to_window(v.mlx, v.mlx_win, v.img, v.x, v.y);
}

void	add_saski(t_v v)
{
	char	*relative_path;

	relative_path = "./assets/saski.xpm";
	v.img_s = 0;
	v.img = mlx_xpm_file_to_image(v.mlx, relative_path, &v.img_s, &v.img_s);
	mlx_put_image_to_window(v.mlx, v.mlx_win, v.img, v.x, v.y);
}
