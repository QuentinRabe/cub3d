/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabefam <arabefam@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 11:54:06 by arabefam          #+#    #+#             */
/*   Updated: 2025/01/21 22:07:43 by arabefam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

bool	is_map_first(int n, char **arr)
{
	int	count;
	int	i;

	count = 0;
	i = -1;
	while (count < n && arr[++i])
	{
		if (is_only(SPACES, arr[i]))
			continue ;
		if (is_only(ELTS, arr[i]))
			return (print_error("Map should not go first."), true);
		count++;
	}
	return (false);
}

bool	contains_at_least(int n, char **arr)
{
	int	count;
	int	i;

	count = 0;
	i = -1;
	while (count < n && arr[++i])
	{
		if (is_only(SPACES, arr[i]))
			continue ;
		count++;
	}
	if (count < n)
		return (print_error("File should contain enough descriptions."), false);
	return (true);
}

void	parse(char **contents, t_vars *vars)
{
	if (!contains_at_least(6, contents) || is_map_first(6, contents))
		return (free_array(contents), exit(EXIT_FAILURE));
	parse_texture(contents);
	parse_color(contents);
	store_texture(contents, vars->textures);
	store_color(contents, vars->colors);
}
