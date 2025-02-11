/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabefam <arabefam@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 19:55:58 by arabefam          #+#    #+#             */
/*   Updated: 2025/02/11 20:04:44 by arabefam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

void	mini_map(t_vars *v)
{
	v->height = get_map_height(v->map);
	v->width = get_map_width(v->map);
	v->mini_img = mlx_new_image(v->mlx, v->width * TILE, v->height * TILE);
}
