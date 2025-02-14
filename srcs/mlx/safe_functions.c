/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   safe_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabefam <arabefam@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 07:27:25 by arabefam          #+#    #+#             */
/*   Updated: 2025/02/14 08:02:56 by arabefam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

void	safe_new_img(t_vars *v, t_img *new, int width, int height)
{
	new->img = mlx_new_image(v->mlx, width, height);
	if (!new->img)
		exit(EXIT_FAILURE);
}

void	safe_get_data_addr(t_img *new)
{
	new->addr = mlx_get_data_addr(new->img, &new->bpp, \
&new->size_line, &new->endian);
	if (!new->addr)
		exit(EXIT_FAILURE);
}

void	safe_xpm_file_to_img(t_vars *v, t_img *new, char *filename)
{
	new->img = mlx_xpm_file_to_image(v->mlx, filename, \
&new->width, &new->height);
	if (!new->img)
		exit(EXIT_FAILURE);
}
