/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_mmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabefam <arabefam@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 14:33:08 by arabefam          #+#    #+#             */
/*   Updated: 2025/02/21 11:48:51 by arabefam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

void	move_forward(void)
{
	t_vars	*v;
	double	new_x;
	double	new_y;

	v = vars_addr(GET, NULL);
	new_x = v->player_x + cos(v->angle) * MOVE_SPEED;
	new_y = v->player_y + sin(v->angle) * MOVE_SPEED;
	if (check_wall(v, new_x, new_y))
		return ;
	destroy_mmap_img();
	init_images();
	v->player_x += cos(v->angle) * MOVE_SPEED;
	v->player_y += sin(v->angle) * MOVE_SPEED;
	render_mmap();
}

void	move_backward(void)
{
	t_vars	*v;
	double	new_x;
	double	new_y;

	v = vars_addr(GET, NULL);
	new_x = v->player_x - cos(v->angle) * MOVE_SPEED;
	new_y = v->player_y - sin(v->angle) * MOVE_SPEED;
	if (check_wall(v, new_x, new_y))
		return ;
	destroy_mmap_img();
	init_images();
	v->player_x -= cos(v->angle) * MOVE_SPEED;
	v->player_y -= sin(v->angle) * MOVE_SPEED;
	render_mmap();
}

void	move_left(void)
{
	t_vars	*v;
	double	new_x;
	double	new_y;

	v = vars_addr(GET, NULL);
	new_x = v->player_x - cos(v->angle + (M_PI / 2)) * MOVE_SPEED;
	new_y = v->player_y - sin(v->angle + (M_PI / 2)) * MOVE_SPEED;
	if (check_wall(v, new_x, new_y))
		return ;
	destroy_mmap_img();
	init_images();
	v->player_x -= cos(v->angle + (M_PI / 2)) * MOVE_SPEED;
	v->player_y -= sin(v->angle + (M_PI / 2)) * MOVE_SPEED;
	render_mmap();
}

void	move_right(void)
{
	t_vars	*v;
	double	new_x;
	double	new_y;

	v = vars_addr(GET, NULL);
	new_x = v->player_x + cos(v->angle + (M_PI / 2)) * MOVE_SPEED;
	new_y = v->player_y + sin(v->angle + (M_PI / 2)) * MOVE_SPEED;
	if (check_wall(v, new_x, new_y))
		return ;
	destroy_mmap_img();
	init_images();
	v->player_x += cos(v->angle + (M_PI / 2)) * MOVE_SPEED;
	v->player_y += sin(v->angle + (M_PI / 2)) * MOVE_SPEED;
	render_mmap();
}
