/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabefam <arabefam@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 09:17:34 by arabefam          #+#    #+#             */
/*   Updated: 2025/01/24 08:37:43 by arabefam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

bool	there_is_map_under(char **contents, int i)
{
	while (is_only(SPACES, contents[i]))
		i++;
	if (contents[i])
		return (true);
	return (false);
}

int	count_trimed_map_len(char **contents, int i)
{
	int	count;

	count = 0;
	while (contents[i] && is_only(SPACES, contents[i]))
		i++;
	while (contents[i])
	{
		if (is_only(SPACES, contents[i])
			&& !there_is_map_under(contents, i + 1))
			break ;
		count++;
		i++;
	}
	return (count);
}

static char	**trim_array(char **contents, int j)
{
	char	**trimed;
	int		len;
	int		i;

	len = count_trimed_map_len(contents, j);
	while (contents[j] && is_only(SPACES, contents[j]))
		j++;
	trimed = (char **) malloc((len + 1) * sizeof(char *));
	if (!trimed)
		return (NULL);
	i = 0;
	while (len)
	{
		trimed[i++] = ft_strdup(contents[j++]);
		len--;
	}
	trimed[i] = NULL;
	return (trimed);
}

void	parse_map(char **contents)
{
	int		i;
	int		count;
	char	**map;

	count = 0;
	i = 0;
	while (count < 6)
	{
		if (is_only(SPACES, contents[i++]))
			continue ;
		count++;
	}
	if (!count_trimed_map_len(contents, i))
	{
		free_array(contents);
		print_error("File should contain map description.");
		exit(EXIT_FAILURE);
	}
	map = trim_array(contents, i);
	if (parsing_process(map))
		return (free_array(contents), exit(EXIT_FAILURE));
	print_array(map);
	free_array(map);
}
