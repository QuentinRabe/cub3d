/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabefam <arabefam@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 19:55:58 by arabefam          #+#    #+#             */
/*   Updated: 2025/02/14 14:25:25 by arabefam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

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
	t_img	*mmap;
	t_img	*tile;
	t_img	*player;
	int		mmap_w;
	int		mmap_h;

	mmap_w = get_map_width(v->map) * TILE;
	mmap_h = get_map_height(v->map) * TILE;
	mmap = new_img(NULL,&mmap_w, &mmap_h);
	tile = new_img("./tiles/block.xpm", NULL, NULL);
	player = new_img("./tiles/player.xpm", NULL, NULL);
	find_player_position(v);
	find_player_orientation(v);
	printf("Player orientation = %f\n", v->angle);
	mmap_addr(SET, mmap);
	tile_addr(SET, tile);
	player_addr(SET, player);
	render_mmap(v, mmap, tile, player);
}
