/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabefam <arabefam@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 08:45:43 by arabefam          #+#    #+#             */
/*   Updated: 2025/01/09 13:52:18 by arabefam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

size_t	file_lines(char *name)
{
	int		fd;
	char	*line;
	size_t	count;

	count = 0;
	fd = open(name, O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		count++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (count);
}

char	**read_content(char *name)
{
	int		fd;
	size_t	lines;
	char	**map;
	size_t	i;

	lines = file_lines(name);
	map = (char **) malloc((lines + 1) * sizeof(char *));
	if (!map)
		return (NULL);
	fd = open(name, O_RDONLY);
	i = 0;
	while (i <= lines)
		map[i++] = get_next_line(fd);
	return (map);
}
