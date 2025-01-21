/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabefam <arabefam@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 08:54:28 by arabefam          #+#    #+#             */
/*   Updated: 2025/01/21 21:31:43 by arabefam         ###   ########.fr       */
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
	int		i;

	i = 0;
	skip(SPACES, content, &i);
	id_len = ft_strlen_set(content + i, SPACES);
	if (id_len > 1)
		return ;
	i += 1;
	skip(SPACES, content, &i);
	len = ft_strlen_set(content + i, SPACES);
	color = ft_substr(content, i, len);
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

	count = 0;
	i = -1;
	while (contents[++i] && count < 2)
	{
		if (is_only(SPACES, contents[i]) || is_texture(contents[i]))
			continue ;
		check_rgb_format(contents[i], contents);
		check_color_values(contents[i], contents);
		count++;
	}
}
