/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabefam <arabefam@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 11:54:06 by arabefam          #+#    #+#             */
/*   Updated: 2025/01/26 17:55:08 by arabefam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

static bool	is_id(char *content, int *count)
{
	if (!ft_strcmp(content, "NO")
		|| !ft_strcmp(content, "EA")
		|| !ft_strcmp(content, "SO")
		|| !ft_strcmp(content, "WE")
		|| !ft_strcmp(content, "F")
		|| !ft_strcmp(content, "C"))
	{
		(*count)++;
		free(content);
		return (true);
	}
	return (false);
}

static bool	is_map_first(int n, char **arr)
{
	int		count;
	int		i;
	int		index;
	size_t	len;
	char	*content;

	count = 0;
	i = -1;
	index = 0;
	while (count < n && arr[++i])
	{
		if (is_only(SPACES, arr[i]))
			continue ;
		skip(SPACES, arr[i], &index);
		len = ft_strlen_set(arr[i] + index, SPACES);
		content = ft_substr(arr[i], index, len);
		if (is_id(content, &count))
			continue ;
		if (is_only(ELTS, content))
			return (free(content), \
			print_error("Map should not go first."), true);
		free(content);
		count++;
	}
	return (false);
}

static bool	contains_at_least(int n, char **arr)
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
	char	**map;

	map = NULL;
	if (!contains_at_least(6, contents) || is_map_first(6, contents))
		return (free_array(contents), exit(EXIT_FAILURE));
	parse_texture(contents);
	parse_color(contents);
	parse_map(contents, &map);
	store_texture(contents, vars->textures);
	store_color(contents, vars->colors);
	print_array(map);
	free_array(map);
}
