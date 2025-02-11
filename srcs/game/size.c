/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   size.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabefam <arabefam@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 19:18:33 by arabefam          #+#    #+#             */
/*   Updated: 2025/02/11 19:49:46 by arabefam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

int	get_map_height(char **map)
{
	int	i;
	int	count;

	count = 0;
	i = -1;
	while (map[++i])
		count++;
	return (count);
}

int	get_map_width(char **map)
{
	int	i;
	int	max;
	int	len;

	max = 0;
	i = -1;
	while (map[++i])
	{
		len = ft_strlen(map[i]);
		if (max < len)
			max = len;
	}
	return (max);
}
