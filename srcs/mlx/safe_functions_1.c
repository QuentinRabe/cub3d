/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   safe_functions_1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabefam <arabefam@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 14:39:25 by arabefam          #+#    #+#             */
/*   Updated: 2025/02/21 12:06:33 by arabefam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

void	safe_destroy_img(t_vars *v, t_img **img_to_delete)
{
	if (*img_to_delete && (*img_to_delete)->img)
	{
		mlx_destroy_image(v->mlx, (*img_to_delete)->img);
		free(*img_to_delete);
		*img_to_delete = NULL;
	}
	else
		print_error("Something goes wrong while destroying image");
}
