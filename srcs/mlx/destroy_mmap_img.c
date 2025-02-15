/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_mmap_img.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabefam <arabefam@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 14:36:59 by arabefam          #+#    #+#             */
/*   Updated: 2025/02/15 15:08:30 by arabefam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

void	destroy_mmap_img(t_img **m, t_img **t, t_img **p, t_img **f)
{
	t_vars	*v;

	v = vars_addr(GET, NULL);
	safe_destroy_img(v, m);
	safe_destroy_img(v, t);
	safe_destroy_img(v, p);
	safe_destroy_img(v, f);
}
