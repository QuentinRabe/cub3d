/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_mmap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabefam <arabefam@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 08:07:04 by arabefam          #+#    #+#             */
/*   Updated: 2025/02/15 15:01:06 by arabefam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

void	render_mmap(t_img *m, t_img *t, t_img *p, t_img *f)
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
				put_img_to_img(m, t, x * TILE, y * TILE);
			if (!is_in(SPACES, v->map[y][x]) && v->map[y][x] != '1')
				put_img_to_img(m, f, x * TILE, y * TILE);
			x++;
		}
		y++;
	}
	put_img_to_img(m, p, v->player_x, v->player_y);
	mlx_put_image_to_window(v->mlx, v->mlx_win, m->img, 0, 0);
}
