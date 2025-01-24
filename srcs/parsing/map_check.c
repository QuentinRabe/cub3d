/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabefam <arabefam@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 08:59:05 by arabefam          #+#    #+#             */
/*   Updated: 2025/01/24 09:22:47 by arabefam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

static int	map_height(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	return (i);
}

int	check_up(char **map, int rw, int cl)
{
	if ((rw - 1) < 0)
		return (1);
	else if (is_in(SPACES, map[rw - 1][cl]))
		return (1);
	return (0);
}

int	check_down(char **map, int rw, int cl)
{
	if ((rw + 1) >= map_height(map))
		return (1);
	else if (is_in(SPACES, map[rw + 1][cl]))
		return (1);
	return (0);
}

int	check_right(char **map, int rw, int cl)
{
	if ((cl + 1) > (int)ft_strlen(map[rw]))
		return (1);
	else if (is_in(SPACES, map[rw][cl + 1]))
		return (1);
	return (0);
}

int	check_left(char **map, int rw, int cl)
{
	if (cl - 1 < 0)
		return (1);
	else if (is_in(SPACES, map[rw][cl - 1]))
		return (1);
	return (0);
}
