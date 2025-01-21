/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_additionnal.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabefam <arabefam@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 09:26:52 by arabefam          #+#    #+#             */
/*   Updated: 2025/01/21 11:52:52 by arabefam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

static bool	is_in_rgb_range(int color)
{
	return (color >= 0 && color <= 255);
}

static void	ft_atoi_check(char *color, char **contents, char **colors)
{
	if (!is_only(NUMBERS, color) || !is_in_rgb_range(ft_atoi(color)))
	{
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

	splitted = ft_split(content, ',');
	i = -1;
	while (splitted[++i])
		ft_atoi_check(splitted[i], contents, splitted);
	free_array(splitted);
}
