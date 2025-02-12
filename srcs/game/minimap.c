/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabefam <arabefam@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 19:55:58 by arabefam          #+#    #+#             */
/*   Updated: 2025/02/12 13:01:20 by arabefam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

void	draw_mmap(t_vars *v)
{
	int	i;

	i = -1;
	while (v->map[++i])
		
}

static void	init_mmap_imgs(t_vars *v)
{
	t_img	mmap_img;
	t_img	tile_img;

	v->mmap->i_mmap = &mmap_img;
	v->mmap->height = get_map_height(v->map);
	v->mmap->width = get_map_width(v->map);
	v->mmap->i_mmap->img = mlx_new_image(v->mlx, v->mmap->width * TILE, \
v->mmap->height * TILE);
	v->mmap->i_mmap->addr = mlx_get_data_addr(v->mlx, &v->mmap->i_mmap->bpp, \
&v->mmap->i_mmap->size_line, &v->mmap->i_mmap->endian);
	v->mmap->tile = &tile_img;
	v->mmap->tile->img = mlx_xpm_file_to_image(v->mlx, "./tiles/block.xpm", \
&v->mmap->tile->width, &v->mmap->tile->height);
	if (!v->mmap->tile->img)
		exit(EXIT_FAILURE);
	v->mmap->tile->addr = mlx_get_data_addr(v->mlx, &v->mmap->tile->bpp, \
&v->mmap->tile->size_line, &v->mmap->tile->endian);
}

void	mini_map(t_vars *v)
{
	init_mmap_imgs(v);
	mlx_put_image_to_window(v->mlx, v->mlx_win, v->mmap->tile->img, 0, 0);
}
