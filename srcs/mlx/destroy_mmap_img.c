/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_mmap_img.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabefam <arabefam@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 14:36:59 by arabefam          #+#    #+#             */
/*   Updated: 2025/02/14 14:43:04 by arabefam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

void	destroy_mmap_img(t_vars *v, t_img *m, t_img *t, t_img *p)
{
	safe_destroy_img(v, m);
	safe_destroy_img(v, t);
	safe_destroy_img(v, p);
}
