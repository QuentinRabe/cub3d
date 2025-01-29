/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabefam <arabefam@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 09:17:34 by arabefam          #+#    #+#             */
/*   Updated: 2025/01/29 19:43:16 by arabefam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

static char	**cleaned_map(char **map)
{
	char	**new;
	int		i;

	new = (char **) malloc((count_array(map) + 1) * sizeof(char *));
	if (!new)
		return (NULL);
	i = -1;
	while (map[++i])
		new[i] = trimed_line(map[i]);
	new[i] = NULL;
	return (new);
}

static bool	there_is_map_under(char **contents, int i)
{
	while (contents[i] && is_only(SPACES, contents[i]))
		i++;
	if (contents[i])
		return (true);
	return (false);
}

static int	count_trimed_map_len(char **contents, int i)
{
	int	count;

	count = 0;
	while (contents[i] && is_only(SPACES, contents[i]))
		i++;
	while (contents[i])
	{
		if (is_only(SPACES, contents[i]) && !there_is_map_under(contents, i + 1))
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

void	parse_map(char **contents, char ***map)
{
	int		i;
	int		count;
	char	**arr;

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
	arr = trim_array(contents, i);
	if (parsing_process(arr))
		return (free_array(contents), exit(EXIT_FAILURE));
	*map = cleaned_map(arr);
	free_array(arr);
}
