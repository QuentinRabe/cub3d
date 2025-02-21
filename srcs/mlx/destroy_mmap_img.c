/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_mmap_img.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabefam <arabefam@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 14:36:59 by arabefam          #+#    #+#             */
/*   Updated: 2025/02/21 15:35:58 by arabefam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

void	destroy_mmap_img(void)
{
	t_vars	*v;

	v = vars_addr(GET, NULL);
	safe_destroy_img(v, &v->imgs->mmap);
	safe_destroy_img(v, &v->imgs->tile);
	safe_destroy_img(v, &v->imgs->player);
	safe_destroy_img(v, &v->imgs->floor);
	safe_destroy_img(v, &v->imgs->rl_mmap);
}
