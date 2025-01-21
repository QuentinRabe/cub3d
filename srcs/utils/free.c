/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabefam <arabefam@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 21:32:27 by arabefam          #+#    #+#             */
/*   Updated: 2025/01/21 22:14:44 by arabefam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

void	free_vars(t_vars *vars)
{
	int	i;

	i = -1;
	while (++i < 4)
	{
		free(vars->textures[i].id);
		free(vars->textures[i].path);
	}
	i = -1;
	while (++i < 2)
		free(vars->colors[i].id);
}
