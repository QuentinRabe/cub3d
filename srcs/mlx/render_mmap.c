/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_mmap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabefam <arabefam@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 08:07:04 by arabefam          #+#    #+#             */
/*   Updated: 2025/02/21 19:41:22 by arabefam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

void	check_offset(int *off_x, int *off_y)
{
	t_vars	*v;

	v = vars_addr(GET, NULL);
	if (*off_y < 0)
		*off_y = 0;
	if (*off_y + MMAP_SIZE > v->imgs->mmap->height)
		*off_y = v->imgs->mmap->height - MMAP_SIZE;
	if (*off_x < 0)
		*off_x = 0;
	if (*off_x + MMAP_SIZE > v->imgs->mmap->width)
		*off_x = v->imgs->mmap->width - MMAP_SIZE;
}

void	draw_rl_mmap(int off_x, int off_y)
{
	t_vars	*v;
	int	y;
	int	x;
	int	j;
	int	i;

	v = vars_addr(GET, NULL);
	y = off_y;
	i = 0;
	while (y < off_y + MMAP_SIZE)
	{
		x = off_x;
		j = 0;
		while (x < off_x + MMAP_SIZE)
		{
			put_pixel_img(v->imgs->rl_mmap, j, i, get_pixel_img(v->imgs->mmap, x, y));
			x++;
			j++;
		}
		i++;
		y++;
	}
}

void render_rl_mmap(void)
{
	t_vars *v;
	int off_y;
	int off_x;

	v = vars_addr(GET, NULL);
	off_x = (v->player_x + 16) - 100;
	off_y = (v->player_y + 16) - 100;
	check_offset(&off_x, &off_y);
	draw_rl_mmap(off_x, off_y);
	mlx_put_image_to_window(v->mlx, v->mlx_win, v->imgs->rl_mmap->img, 0, HEIGHT - 200);
}

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
	render_rl_mmap();
}
