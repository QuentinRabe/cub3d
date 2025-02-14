/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_mmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabefam <arabefam@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 14:33:08 by arabefam          #+#    #+#             */
/*   Updated: 2025/02/14 15:01:38 by arabefam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

void	move_forward(t_vars *v, t_img *m, t_img *t, t_img *p)
{
	destroy_mmap_img(v, m, t, p);
	init_images(v, &m, &t, &p);
	v->player_x += cos(v->angle) * MOVE_SPEED;
	v->player_y += sin(v->angle) * MOVE_SPEED;
	render_mmap(v, m, t, p);
}
