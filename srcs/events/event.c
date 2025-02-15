/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabefam <arabefam@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 08:05:40 by arabefam          #+#    #+#             */
/*   Updated: 2025/02/14 20:29:31by arabefam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

int	game_loop(t_vars *v)
{
	t_img	*m;
	t_img	*t;
	t_img	*p;

	m = mmap_addr(GET, NULL);
	t = tile_addr(GET, NULL);
	p = player_addr(GET, NULL);
	if (v->pressed_w)
		move_forward(v, &m, &t, &p);
	if (v->pressed_a)
		move_left(v, &m, &t, &p);
	if (v->pressed_s)
		move_backward(v, &m, &t, &p);
	if (v->pressed_d)
		move_right(v, &m, &t, &p);
	return (0);
}

int	key_release(int key, t_vars *v)
{
	if (key == KEY_W)
		v->pressed_w = false;
	if (key == KEY_A)
		v->pressed_a = false;
	if (key == KEY_D)
		v->pressed_d = false;
	if (key == KEY_S)
		v->pressed_s = false;
	return (0);
}

int	key_press(int key, t_vars *v)
{
	if (key == KEY_W)
		v->pressed_w = true;
	if (key == KEY_A)
		v->pressed_a = true;
	if (key == KEY_D)
		v->pressed_d = true;
	if (key == KEY_S)
		v->pressed_s = true;
	return (0);
}

int	key_hook(int key, t_vars *v)
{
	t_img	*m;
	t_img	*t;
	t_img	*p;

	m = mmap_addr(GET, NULL);
	t = tile_addr(GET, NULL);
	p = player_addr(GET, NULL);
	if (key == 65307)
	{
		free_vars(v);
		destroy_mmap_img(v, &m, &t, &p);
		mlx_destroy_window(v->mlx, v->mlx_win);
		mlx_destroy_display(v->mlx);
		free_array(v->map);
		free(v->mlx);
		exit(EXIT_SUCCESS);
	}
	return (0);
}
