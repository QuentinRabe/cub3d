/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_mmap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabefam <arabefam@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 08:07:04 by arabefam          #+#    #+#             */
/*   Updated: 2025/02/14 09:14:50 by arabefam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

void	mmap_size_check(int mmap_w, int mmap_h, t_vars *v)
{
	int	max;

	max = v->mmap_size;
	if (max > mmap_w)
		max = mmap_w;
	if (max > mmap_h)
		max = mmap_h;
	v->mmap_size = max;
}

void	offset_check(int *x, int *y, t_vars *v)
{
	int	mmap_w;
	int	mmap_h;

	mmap_w = get_map_width(v->map) * TILE;
	mmap_h = get_map_height(v->map) * TILE;
	mmap_size_check(mmap_w, mmap_h, v);
	if (*x < 0)
		*x = 0;
	if (*y < 0)
		*y = 0;
	if (*x + v->mmap_size > mmap_w)
		*x = mmap_w - v->mmap_size;
	if (*y + v->mmap_size > mmap_h)
		*y = mmap_h - v->mmap_size;
}

void	render_mmap(t_vars *v, t_img *m, t_img *t, t_img *p)
{
	int	off_x;
	int	off_y;
	int	x;
	int	y;

	(void) m;
	(void) t;
	(void) p;
	off_x = (int) v->player_x - (v->mmap_size / 2);
	off_y = (int) v->player_y - (v->mmap_size / 2);
	offset_check(&off_x, &off_y, v);
	y = off_y;
	x = off_x;
	while (y < off_y + v->mmap_size && v->map[y - off_y])
	{
		x = off_x;
		while (x < off_x + v->mmap_size && v->map[y - off_y][x - off_x])
		{
			if (v->map[y - off_y][x - off_x] == '1')
				put_img_to_img(m, t, (x - off_x) * TILE, (y - off_y) * TILE);
			if (is_in(PLAYER, v->map[y - off_y][x - off_x]))
				put_img_to_img(m, p, (x - off_x) * TILE, (y - off_y) * TILE);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(v->mlx, v->mlx_win, m->img, 0, 0);
}
