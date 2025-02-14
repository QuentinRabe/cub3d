/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabefam <arabefam@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 08:05:40 by arabefam          #+#    #+#             */
/*   Updated: 2025/02/14 15:12:09 by arabefam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

int	key_hook(int key, t_vars *v)
{
	t_img	*m;
	t_img	*t;
	t_img	*p;

	m = mmap_addr(GET, NULL);
	t = tile_addr(GET, NULL);
	p = player_addr(GET, NULL);
	if (key == 65307)
	{
		free_vars(v);
		destroy_mmap_img(v, m, t, p);
		mlx_destroy_window(v->mlx, v->mlx_win);
		mlx_destroy_display(v->mlx);
		free_array(v->map);
		free(v->mlx);
		exit(EXIT_SUCCESS);
	}
	if (key == 119)
		move_forward(v, m, t, p);
	printf("key = %d\n", key);
	return (0);
}
