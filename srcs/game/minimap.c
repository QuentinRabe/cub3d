/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabefam <arabefam@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 19:55:58 by arabefam          #+#    #+#             */
/*   Updated: 2025/02/14 08:37:29 by arabefam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

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

	mmap = new_img(NULL, &v->mmap_size, &v->mmap_size);
	tile = new_img("./tiles/block.xpm", NULL, NULL);
	player = new_img("./tiles/player.xpm", NULL, NULL);
	find_player_position(v);
	mmap_addr(SET, mmap);
	tile_addr(SET, tile);
	player_addr(SET, player);
	render_mmap(v, mmap, tile, player);
}
