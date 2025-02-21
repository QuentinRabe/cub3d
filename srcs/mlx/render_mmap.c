/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_mmap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabefam <arabefam@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 08:07:04 by arabefam          #+#    #+#             */
/*   Updated: 2025/02/21 15:17:15 by arabefam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

void	render_mmap(void)
{
	int		y;
	int		x;
	t_vars	*v;

	y = 0;
	v = vars_addr(GET, NULL);
	while (v->map[y])
	{
		x = 0;
		while (v->map[y][x])
		{
			if (v->map[y][x] == '1')
				put_img_to_img(v->imgs->mmap, v->imgs->tile, \
x * TILE, y * TILE);
			if (!is_in(SPACES, v->map[y][x]) && v->map[y][x] != '1')
				put_img_to_img(v->imgs->mmap, v->imgs->floor, \
x * TILE, y * TILE);
			x++;
		}
		y++;
	}
	put_img_to_img(v->imgs->mmap, v->imgs->player, v->player_x, v->player_y);
	mlx_put_image_to_window(v->mlx, v->mlx_win, v->imgs->mmap->img, 0, 0);
}
