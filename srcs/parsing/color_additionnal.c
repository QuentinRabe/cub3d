/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_additionnal.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabefam <arabefam@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 09:26:52 by arabefam          #+#    #+#             */
/*   Updated: 2025/01/21 17:50:43 by arabefam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

bool	is_texture(char *content)
{
	int	i;

	i = 0;
	skip(SPACES, content, &i);
	if (ft_strlen_set(content + i, SPACES) == 2)
		return (true);
	return (false);
}

static bool	is_in_rgb_range(int color)
{
	return (color >= 0 && color <= 255);
}

static void	ft_atoi_check(char *color, char **contents, char **colors)
{
	if (!is_only(NUMBERS, color) || !is_in_rgb_range(ft_atoi(color)))
	{
		printf("[%s]\n", color);
		free_array(contents);
		free_array(colors);
		print_error("Color should be a number between 0 and 255");
		exit(EXIT_FAILURE);
	}
}

void	check_color_values(char *content, char **contents)
{
	char	**splitted;
	int		i;
	int		index;

	index = 0;
	skip(SPACES, content, &index);
	index += 1;
	skip(SPACES, content, &index);
	splitted = ft_split(content + index, ',');
	i = -1;
	while (splitted[++i])
		ft_atoi_check(splitted[i], contents, splitted);
	free_array(splitted);
}
