/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabefam <arabefam@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 08:05:40 by arabefam          #+#    #+#             */
/*   Updated: 2025/02/11 19:45:47 by arabefam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

int	key_hook(int key, t_vars *v)
{
	if (key == 65307)
	{
		free_vars(v);
		mlx_destroy_window(v->mlx, v->mlx_win);
		mlx_destroy_display(v->mlx);
		free_array(v->map);
		free(v->mlx);
		exit(EXIT_SUCCESS);
	}
	return (0);
}
