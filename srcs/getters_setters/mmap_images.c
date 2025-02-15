/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mmap_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabefam <arabefam@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 08:08:10 by arabefam          #+#    #+#             */
/*   Updated: 2025/02/15 14:57:48 by arabefam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

t_img	*player_addr(t_opt option, t_img *addr)
{
	static t_img	*ptr;

	if (option == SET)
		ptr = addr;
	return (ptr);
}

t_img	*tile_addr(t_opt option, t_img *addr)
{
	static t_img	*ptr;

	if (option == SET)
		ptr = addr;
	return (ptr);
}

t_img	*mmap_addr(t_opt option, t_img *addr)
{
	static t_img	*ptr;

	if (option == SET)
		ptr = addr;
	return (ptr);
}

t_img	*floor_addr(t_opt option, t_img *addr)
{
	static t_img	*ptr;

	if (option == SET)
		ptr = addr;
	return (ptr);
}
