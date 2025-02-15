/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabefam <arabefam@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 15:29:54 by arabefam          #+#    #+#             */
/*   Updated: 2025/02/15 16:54:18 by arabefam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

int	game_loop(t_vars *v)
{
	t_img	*m;
	t_img	*t;
	t_img	*p;
	t_img	*f;

	m = mmap_addr(GET, NULL);
	t = tile_addr(GET, NULL);
	p = player_addr(GET, NULL);
	f = floor_addr(GET, NULL);
	if (v->pressed_w)
		move_forward(&m, &t, &p, &f);
	if (v->pressed_a)
		move_left(&m, &t, &p, &f);
	if (v->pressed_s)
		move_backward(&m, &t, &p, &f);
	if (v->pressed_d)
		move_right(&m, &t, &p, &f);
	if (v->pressed_left)
		rotate_left(v);
	if (v->pressed_right)
		rotate_right(v);
	if (v->pressed_escape)
		end_game(v);
	return (0);
}

int	key_release(int key, t_vars *v)
{
	if (key == XK_w)
		v->pressed_w = false;
	if (key == XK_a)
		v->pressed_a = false;
	if (key == XK_d)
		v->pressed_d = false;
	if (key == XK_s)
		v->pressed_s = false;
	if (key == XK_Escape)
		v->pressed_escape = false;
	if (key == XK_Left)
		v->pressed_left = false;
	if (key == XK_Right)
		v->pressed_right = false;
	return (0);
}

int	key_press(int key, t_vars *v)
{
	if (key == XK_w)
		v->pressed_w = true;
	if (key == XK_a)
		v->pressed_a = true;
	if (key == XK_d)
		v->pressed_d = true;
	if (key == XK_s)
		v->pressed_s = true;
	if (key == XK_Escape)
		v->pressed_escape = true;
	if (key == XK_Left)
		v->pressed_left = true;
	if (key == XK_Right)
		v->pressed_right = true;
	return (0);
}

int	end_game(t_vars *v)
{
	t_img	*m;
	t_img	*t;
	t_img	*p;
	t_img	*f;

	m = mmap_addr(GET, NULL);
	t = tile_addr(GET, NULL);
	p = player_addr(GET, NULL);
	f = floor_addr(GET, NULL);
	free_vars(v);
	destroy_mmap_img(&m, &t, &p, &f);
	mlx_destroy_window(v->mlx, v->mlx_win);
	mlx_destroy_display(v->mlx);
	free_array(v->map);
	free(v->mlx);
	exit(EXIT_SUCCESS);
	return (0);
}
