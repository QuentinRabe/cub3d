/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabefam <arabefam@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 19:55:58 by arabefam          #+#    #+#             */
/*   Updated: 2025/02/13 14:15:58 by arabefam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

unsigned int	get_pixel_img(t_img *img, int x, int y) {
	return (*(unsigned int *)((img->addr + (y * img->size_line) + (x * img->bpp / 8))));
}

void	put_pixel_img(t_img *img, int x, int y, int color)
{
	char	*pixel;

	if (color == (int)0xFF000000)
		return ;
	pixel = img->addr + (y * img->size_line + x * (img->bpp / 8));
	printf("Writing at addr=%p | x=%d, y=%d | offset=%d\n", (void *)pixel, x, y, y * img->size_line + x * (img->bpp / 8));
	*(int *)pixel = color;
}

void	put_img_to_img(t_img *dst, t_img *src, int x, int y) {
	int i;
	int j;

	i = 0;
	while(i < src->width) {
		j = 0;
		while (j < src->height) {
			put_pixel_img(dst, x + i, y + j, get_pixel_img(src, i, j));
			j++;
		}
		i++;
	}
}

void	mini_map(t_vars *v)
{
	t_img	*mmap;
	t_img	*tile;
	t_img	*player;
	int		y;
	int		x;

	mmap = (t_img *) malloc(sizeof(t_img));
	tile = (t_img *) malloc(sizeof(t_img));
	player = (t_img *) malloc(sizeof(t_img));
	mmap->width = get_map_width(v->map) * TILE;
	mmap->height = get_map_height(v->map) * TILE;
	mmap->img = mlx_new_image(v->mlx, mmap->width, mmap->height);
	mmap->addr = mlx_get_data_addr(mmap->img, &mmap->bpp, &mmap->size_line, &mmap->endian);
	tile->img = mlx_xpm_file_to_image(v->mlx, "./tiles/block.xpm", &tile->width, &tile->height);
	tile->addr = mlx_get_data_addr(tile->img, &tile->bpp, &tile->size_line, &tile->endian);
	player->img = mlx_xpm_file_to_image(v->mlx, "./tiles/player.xpm", &player->width, &player->height);
	player->addr = mlx_get_data_addr(player->img, &player->bpp, &player->size_line, &player->endian);
	y = 0;
	while (v->map[y])
	{
		x = 0;
		while (v->map[y][x])
		{
			if (v->map[y][x] == '1')
				put_img_to_img(mmap, tile, x * TILE, y * TILE);
			if (is_in(PLAYER, v->map[y][x]))
				put_img_to_img(mmap, player, x * TILE, y * TILE);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(v->mlx, v->mlx_win, mmap->img, 0, 0);
}
