/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_additionnal.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabefam <arabefam@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 18:07:04 by arabefam          #+#    #+#             */
/*   Updated: 2025/01/29 19:43:50 by arabefam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

static bool	has_only_one_player(char **map)
{
	int	i;
	int	j;
	int	count;

	i = -1;
	count = 0;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (is_in(PLAYER, map[i][j]))
				count++;
			if (count > 1)
			{
				print_error("Map should contain only one player");
				return (false);
			}
		}
	}
	if (count == 0)
		return (print_error("Map should contain at least one player"), false);
	return (true);
}

static int	check_closed_process(char **map, int rw, int cl)
{
	if (map[rw][cl] == '0')
	{
		if (check_left(map, rw, cl)
			|| check_right(map, rw, cl)
			|| check_down(map, rw, cl)
			|| check_up(map, rw, cl))
			return (1);
	}
	return (0);
}

static bool	is_map_closed(char **map)
{
	int		cl;
	int		rw;

	rw = -1;
	while (map[++rw])
	{
		cl = -1;
		while (map[rw][++cl])
		{
			if (check_closed_process(map, rw, cl))
			{
				print_error("Map should be closed.");
				return (false);
			}
		}
	}
	return (true);
}

static bool	has_forbidden_elts(char **map)
{
	int		i;

	i = 0;
	while (map[i])
	{
		if (!is_only(ELTS, map[i]))
		{
			print_error("Map description should only contain 10[N][S][W][E].");
			return (true);
		}
		i++;
	}
	return (false);
}

int	parsing_process(char **map)
{
	if (has_forbidden_elts(map) || !is_map_closed(map)
		|| !has_only_one_player(map))
	{
		free_array(map);
		return (1);
	}
	return (0);
}
