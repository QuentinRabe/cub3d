/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_wall.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabefam <arabefam@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 09:54:06 by arabefam          #+#    #+#             */
/*   Updated: 2025/02/21 15:18:17 by arabefam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

int	check_wall(t_vars *v, double new_x, double new_y)
{
	int	top;
	int	bottom;
	int	left;
	int	right;

	top = (int)(new_y + HITBOX_OFFSET) / TILE;
	bottom = (int)(new_y + TILE - HITBOX_OFFSET) / TILE;
	left = (int)(new_x + HITBOX_OFFSET) / TILE;
	right = (int)(new_x + TILE - HITBOX_OFFSET) / TILE;
	if (v->map[top][left] == '1' || v->map[top][right] == '1' || \
v->map[bottom][left] == '1' || v->map[bottom][right] == '1')
		return (1);
	return (0);
}
