/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabefam <arabefam@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 08:54:28 by arabefam          #+#    #+#             */
/*   Updated: 2025/01/21 11:13:37 by arabefam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

static bool	has_too_much_color(char **colors)
{
	int	i;
	int	count;

	i = -1;
	count = 0;
	while (colors[++i])
		count++;
	if (count != 3)
		return (true);
	return (false);
}

static bool	has_too_much_commas(char *color)
{
	int	i;
	int	count;

	i = -1;
	count = 0;
	while (color[++i])
	{
		if (color[i] == ',')
			count++;
	}
	if (count != 2)
		return (true);
	return (false);
}

static bool	follow_rgb_format(char *color)
{
	char	**splitted;

	splitted = ft_split(color, ',');
	if (has_too_much_commas(color) || has_too_much_color(splitted))
	{
		free_array(splitted);
		return (false);
	}
	free_array(splitted);
	return (true);
}

static void	check_rgb_format(char *content, char **contents)
{
	size_t	id_len;
	size_t	len;
	char	*color;

	id_len = ft_strlen_set(content, SPACES);
	if (id_len > 1)
		return ;
	len = ft_strlen_charset(content + id_len + 1, '\n');
	color = ft_substr(content, id_len + 1, len);
	if (!follow_rgb_format(color))
	{
		free(color);
		free_array(contents);
		print_error("Color should follow this format rrr,ggg,bbb");
		exit(EXIT_FAILURE);
	}
	free(color);
}

void	parse_color(char **contents)
{
	int	i;
	int	count;
	int	index;

	count = 0;
	i = -1;
	while (contents[++i] && count < 2)
	{
		if (is_only(SPACES, contents[i])
			|| ft_strlen_set(contents[i], SPACES) > 1)
			continue ;
		check_rgb_format(contents[i], contents);
		index = ft_strlen_set(contents[i], SPACES);
		skip(SPACES, contents[i], &index);
		check_color_values(contents[i] + index, contents);
		count++;
	}
}
