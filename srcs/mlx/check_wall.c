/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_wall.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabefam <arabefam@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 09:54:06 by arabefam          #+#    #+#             */
/*   Updated: 2025/02/15 14:42:21 by arabefam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

int	check_wall(t_vars *v, double new_x, double new_y)
{
    int	tl_x = (int)(new_x) / TILE;
    int	tr_x = (int)(new_x + TILE - 1) / TILE;
    int	tl_y = (int)(new_y) / TILE;
    int	br_y = (int)(new_y + TILE - 1) / TILE;

    // Vérifie les murs aux coins et aux bords
    if (tl_x < 0 || tr_x < 0 || tl_y < 0 || br_y < 0 ||
        tl_x >= get_map_width(v->map) * TILE || tr_x >= get_map_width(v->map) * TILE ||
        tl_y >= get_map_height(v->map) * TILE || br_y >= get_map_height(v->map) * TILE)
    {
        fprintf(stderr, "Erreur: Coordonnées hors limites\n");
        return (1);
    }

    if (v->map[tl_y][tl_x] == '1' || v->map[tl_y][tr_x] == '1' ||
        v->map[br_y][tl_x] == '1' || v->map[br_y][tr_x] == '1')
    {
        fprintf(stderr, "Collision détectée aux coordonnées (%d, %d), (%d, %d), (%d, %d), (%d, %d)\n",
            tl_x, tl_y, tr_x, tl_y, tl_x, br_y, tr_x, br_y);
        return (1);
    }

    return (0);
}
