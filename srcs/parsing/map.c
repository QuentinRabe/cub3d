/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabefam <arabefam@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 09:17:34 by arabefam          #+#    #+#             */
/*   Updated: 2025/01/22 09:48:07 by arabefam         ###   ########.fr       */
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

// static char	**trim_array(char **contents)
// {
// 	char	**trimed;


// }

void	parse_map(char **contents)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (count < 6)
	{
		if (is_only(SPACES, contents[i++]))
			continue;
		count++;
	}
	printf("Trimed array length = %d\n", count_trimed_map_len(contents, i));
}
