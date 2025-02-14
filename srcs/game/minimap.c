/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabefam <arabefam@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 19:55:58 by arabefam          #+#    #+#             */
/*   Updated: 2025/02/14 07:56:50 by arabefam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

void	mini_map(t_vars *v)
{
	t_img	*mmap;
	t_img	*tile;
	t_img	*player;

	mmap = new_img(NULL, &v->mmap_size, &v->mmap_size);
	tile = new_img("./tiles/block.xpm", NULL, NULL);
	player = new_img("./tiles/player.xpm", NULL, NULL);
}
