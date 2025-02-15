/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_mmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabefam <arabefam@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 14:33:08 by arabefam          #+#    #+#             */
/*   Updated: 2025/02/15 10:44:44 by arabefam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

void	move_forward(t_vars *v, t_img **m, t_img **t, t_img **p)
{
	double	new_x;
	double	new_y;

	new_x = v->player_x + cos(v->angle) * MOVE_SPEED;
	new_y = v->player_y + sin(v->angle) * MOVE_SPEED;
	if (check_wall(v, new_x, new_y))
		return ;
	destroy_mmap_img(v, m, t, p);
	init_images(v, m, t, p);
	v->player_x += cos(v->angle) * MOVE_SPEED;
	v->player_y += sin(v->angle) * MOVE_SPEED;
	render_mmap(v, *m, *t, *p);
}

void	move_backward(t_vars *v, t_img **m, t_img **t, t_img **p)
{
	destroy_mmap_img(v, m, t, p);
	init_images(v, m, t, p);
	v->player_x -= cos(v->angle) * MOVE_SPEED;
	v->player_y -= sin(v->angle) * MOVE_SPEED;
	render_mmap(v, *m, *t, *p);
}

void	move_left(t_vars *v, t_img **m, t_img **t, t_img **p)
{
	destroy_mmap_img(v, m, t, p);
	init_images(v, m, t, p);
	v->player_x += sin(v->angle) * MOVE_SPEED;
	v->player_y -= cos(v->angle) * MOVE_SPEED;
	render_mmap(v, *m, *t, *p);
}

void	move_right(t_vars *v, t_img **m, t_img **t, t_img **p)
{
	destroy_mmap_img(v, m, t, p);
	init_images(v, m, t, p);
	v->player_x -= sin(v->angle) * MOVE_SPEED;
	v->player_y += cos(v->angle) * MOVE_SPEED;
	render_mmap(v, *m, *t, *p);
}
