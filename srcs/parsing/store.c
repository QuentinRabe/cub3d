/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabefam <arabefam@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 14:25:19 by arabefam          #+#    #+#             */
/*   Updated: 2025/01/22 08:02:48 by arabefam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

static void	process_color(char *content, t_colors c[2], int i)
{
	int		j;
	char	**splitted;

	j = 0;
	skip(SPACES, content, &j);
	c[i].id = ft_substr(content, j, 1);
	j += 1;
	skip(SPACES, content, &j);
	splitted = ft_split(content + j, ',');
	c[i].red = (int) ft_atoi(splitted[0]);
	c[i].green = (int) ft_atoi(splitted[1]);
	c[i].blue = (int) ft_atoi(splitted[2]);
	free_array(splitted);
}

static void	process_texture(char *content, t_txt t[4], int i)
{
	int		j;
	size_t	len;

	j = 0;
	skip(SPACES, content, &j);
	t[i].id = ft_substr(content, j, 2);
	j += 2;
	skip(SPACES, content, &j);
	len = ft_strlen_set(content + j, SPACES);
	t[i].path = ft_substr(content, j, len);
}

void	store_color(char **contents, t_colors c[2])
{
	int		i;
	int		count;

	i = -1;
	count = 0;
	while (contents[++i] && count < 2)
	{
		if (is_only(SPACES, contents[i]) || is_texture(contents[i]))
			continue ;
		process_color(contents[i], c, count);
		count++;
	}
}

void	store_texture(char **contents, t_txt t[4])
{
	int		i;
	int		count;

	i = -1;
	count = 0;
	while (contents[++i] && count < 4)
	{
		if (is_only(SPACES, contents[i]) || !is_texture(contents[i]))
			continue ;
		process_texture(contents[i], t, count);
		count++;
	}
}
