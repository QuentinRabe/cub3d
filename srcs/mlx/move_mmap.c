/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_mmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabefam <arabefam@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 14:33:08 by arabefam          #+#    #+#             */
/*   Updated: 2025/02/15 15:17:02 by arabefam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

void	move_forward(t_img **m, t_img **t, t_img **p, t_img **f)
{
	t_vars	*v;

	v = vars_addr(GET, NULL);
	destroy_mmap_img(m, t, p, f);
	init_images(m, t, p, f);
	v->player_x += cos(v->angle) * MOVE_SPEED;
	v->player_y += sin(v->angle) * MOVE_SPEED;
	render_mmap(*m, *t, *p, *f);
}

void	move_backward(t_img **m, t_img **t, t_img **p, t_img **f)
{
	t_vars	*v;

	v = vars_addr(GET, NULL);
	destroy_mmap_img(m, t, p, f);
	init_images(m, t, p, f);
	v->player_x -= cos(v->angle) * MOVE_SPEED;
	v->player_y -= sin(v->angle) * MOVE_SPEED;
	render_mmap(*m, *t, *p, *f);
}

void	move_left(t_img **m, t_img **t, t_img **p, t_img **f)
{
	t_vars	*v;

	v = vars_addr(GET, NULL);
	destroy_mmap_img(m, t, p, f);
	init_images(m, t, p, f);
	v->player_x += sin(v->angle) * MOVE_SPEED;
	v->player_y -= cos(v->angle) * MOVE_SPEED;
	render_mmap(*m, *t, *p, *f);
}

void	move_right(t_img **m, t_img **t, t_img **p, t_img **f)
{
	t_vars	*v;

	v = vars_addr(GET, NULL);
	destroy_mmap_img(m, t, p, f);
	init_images(m, t, p, f);
	v->player_x -= sin(v->angle) * MOVE_SPEED;
	v->player_y += cos(v->angle) * MOVE_SPEED;
	render_mmap(*m, *t, *p, *f);
}
