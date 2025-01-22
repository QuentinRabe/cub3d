/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabefam <arabefam@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 11:54:06 by arabefam          #+#    #+#             */
/*   Updated: 2025/01/22 08:20:09 by arabefam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

bool	is_map_first(int n, char **arr)
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
		printf("%s\n", content);
		if (is_only(ELTS, content))
			return (free(content), print_error("Map should not go first."), true);
		free(content);
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
