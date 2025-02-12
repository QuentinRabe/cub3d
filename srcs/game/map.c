/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabefam <arabefam@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 19:55:58 by arabefam          #+#    #+#             */
/*   Updated: 2025/02/12 10:53:45 by arabefam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

void	mini_map(t_vars *v)
{
	v->mmap->height = get_map_height(v->map);
	v->mmap->width = get_map_width(v->map);
	v->mmap->img = mlx_new_image(v->mlx, v->mmap->width * TILE, \
v->mmap->height * TILE);
	v->mmap->tile = mlx_xpm_file_to_image(v->mlx, "./tiles/block.xpm", &v->mmap->t_width, &v->mmap->height);
	mlx_put_image_to_window(v->mlx, v->mlx_win, v->mmap->tile, 0, 0);
}
