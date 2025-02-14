/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   safe_functions_1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabefam <arabefam@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 14:39:25 by arabefam          #+#    #+#             */
/*   Updated: 2025/02/14 14:42:35 by arabefam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

void	safe_destroy_img(t_vars *v, t_img *img_to_delete)
{
	if (img_to_delete->img)
		mlx_destroy_image(v->mlx, img_to_delete->img);
	else
		print_error("Something goes wrong while destroying image");
}
