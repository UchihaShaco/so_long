/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalwahei <jalwahei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 10:38:55 by jalwahei          #+#    #+#             */
/*   Updated: 2023/02/07 18:57:17 by jalwahei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./mlx/mlx.h"
# include "./ft_printf/ft_printf.h"
# include "./libft/libft.h"

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <string.h>
# include <stdio.h>

typedef struct s_v
{
	void	*wall;
	void	*player;
	void	*saski;
	void	*ramen;
	char	**map;
	void	*mlx;
	void	*mlx_win;
	void	*img;
	int		img_s;
	int		x;
	int		y;
	int		current_x;
	int		current_y;
	int		n_lines;
	int		col_s;
	int		c_count;
	int		p_count;
	int		e_count;
	int		l;
	int		c;
	int		m;
	int		k;
	int		move_count;
}	t_v;

/*****************************Map Print**********************************/
void	add_collectible(t_v v);
void	add_floor(t_v v);
void	add_wall(char obj_name, t_v v);
void	add_naruto(t_v v);
void	add_saski(t_v v);
void	get_map(int fd, int line_s, t_v *v);
int		re_map(t_v *v);
/*****************************Validation Map**********************************/
int		validation_ber(char *str);
int		validation_c(t_v *v);
int		validation_map(t_v *v);
int		val_rectangle(t_v *v);
int		valid_p_c_e(t_v *v);
/*****************************Utils**********************************/
int		move_naruto_image(int keycode, t_v *v);
int		ft_exit(t_v *v);
void	print_error(void);
int		valid_dif_char(t_v *v);

#endif