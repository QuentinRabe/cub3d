/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cpy_img.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabefam <arabefam@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 07:55:17 by arabefam          #+#    #+#             */
/*   Updated: 2025/02/14 08:02:18 by arabefam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

static unsigned int	get_pixel_img(t_img *img, int x, int y)
{
	return (*(unsigned int *)(img->addr + (y * img->size_line) + (x * \
img->bpp / 8)));
}

static void	put_pixel_img(t_img *img, int x, int y, int color)
{
	char	*pixel;

	if (color == (int)0xFF000000)
		return ;
	pixel = img->addr + (y * img->size_line + x * (img->bpp / 8));
	*(int *)pixel = color;
}

void	put_img_to_img(t_img *dst, t_img *src, int x, int y)
{
	int	i;
	int	j;

	i = -1;
	while (++i < src->width)
	{
		j = -1;
		while (++j < src->height)
			put_pixel_img(dst, x + i, y + j, get_pixel_img(src, i, j));
	}
}
