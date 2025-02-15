/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabefam <arabefam@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 16:42:37 by arabefam          #+#    #+#             */
/*   Updated: 2025/02/15 16:55:11 by arabefam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

void	rotate_left(t_vars *v)
{
	v->angle -= ROTATE_ANGLE;
	if (v->angle < 0)
		v->angle += 2 * M_PI;
}

void	rotate_right(t_vars *v)
{
	v->angle += ROTATE_ANGLE;
	if (v->angle > 2 * M_PI)
		v->angle -= 2 * M_PI;
}
