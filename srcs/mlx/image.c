/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabefam <arabefam@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 07:12:50 by arabefam          #+#    #+#             */
/*   Updated: 2025/02/14 07:42:23 by arabefam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

void	new_img_process(t_img *new, int width, int height)
{
	t_vars	*v;

	v = vars_addr(GET, NULL);
	safe_new_img(v, new, width, height);
	safe_get_data_addr(new);
}

void	new_xpm_img_process(char *filename, t_img *new)
{
	t_vars	*v;

	v = vars_addr(GET, NULL);
	safe_xpm_file_to_img(v, new, filename);
	safe_get_data_addr(new);
}

t_img	*new_img(char *filename, int *width, int *height)
{
	t_img	*new;

	new = (t_img *) malloc(sizeof(t_img));
	if (!new)
		return (NULL);
	if (filename)
		new_xpm_img_process(filename, new);
	else
		new_img_process(new, *width, *height);
	return (new);
}
