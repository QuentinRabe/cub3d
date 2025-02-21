/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabefam <arabefam@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 19:55:58 by arabefam          #+#    #+#             */
/*   Updated: 2025/02/21 11:51:32 by arabefam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

static void	init_key_pressed(t_vars *v)
{
	v->pressed_a = false;
	v->pressed_d = false;
	v->pressed_s = false;
	v->pressed_w = false;
	v->pressed_escape = false;
	v->pressed_left = false;
	v->pressed_right = false;
}

void	init_images(void)
{
	int		mmap_w;
	int		mmap_h;
	t_vars	*v;

	v = vars_addr(GET, NULL);
	mmap_w = get_map_width(v->map) * TILE;
	mmap_h = get_map_height(v->map) * TILE;
	v->imgs->mmap = new_img(NULL,&mmap_w, &mmap_h);
	v->imgs->tile = new_img("./tiles/crate.xpm", NULL, NULL);
	v->imgs->player = new_img("./tiles/player.xpm", NULL, NULL);
	v->imgs->floor = new_img("./tiles/floor.xpm", NULL, NULL);
	mmap_addr(SET, v->imgs->mmap);
	tile_addr(SET, v->imgs->tile);
	player_addr(SET, v->imgs->player);
	floor_addr(SET, v->imgs->floor);
}

static void	find_player_orientation(t_vars *v)
{
	char	c;

	c = v->map[(int) v->player_y / TILE][(int) v->player_x / TILE];
	if (c == 'N')
		v->angle = 3 * (M_PI / 2);
	else if (c == 'E')
		v->angle = 0;
	else if (c == 'S')
		v->angle = M_PI / 2;
	else
	 	v->angle = M_PI;
}

static void	find_player_position(t_vars *v)
{
	int	y;
	int	x;

	y = -1;
	while (v->map[++y])
	{
		x = -1;
		while (v->map[y][++x])
		{
			if (is_in(PLAYER, v->map[y][x]))
			{
				v->player_x = x * TILE;
				v->player_y = y * TILE;
				return ;
			}
		}
	}
}

void	mini_map(t_vars *v)
{
	v->imgs->mmap = NULL;
	v->imgs->tile = NULL;
	v->imgs->player = NULL;
	v->imgs->floor = NULL;
	init_key_pressed(v);
	init_images();
	find_player_position(v);
	find_player_orientation(v);
	render_mmap();
}
