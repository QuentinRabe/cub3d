/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_wall.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabefam <arabefam@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 09:54:06 by arabefam          #+#    #+#             */
/*   Updated: 2025/02/15 10:42:54 by arabefam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

int	check_wall(t_vars *v, double new_x, double new_y)
{
	int	tl_x = (int)(new_x) / TILE;
	int	tr_x = (int)(new_x + TILE) / TILE;
	int	tl_y = (int)(new_y) / TILE;
	int	br_y = (int)(new_y + TILE) / TILE;

	// Vérifie les murs aux coins et aux bords
	if (v->map[tl_y][tl_x] == '1' || v->map[tl_y][tr_x] == '1' ||
		v->map[br_y][tl_x] == '1' || v->map[br_y][tr_x] == '1')
		return (1);
	return (0);
}
