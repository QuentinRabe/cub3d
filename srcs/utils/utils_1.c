/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabefam <arabefam@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 12:02:34 by arabefam          #+#    #+#             */
/*   Updated: 2025/01/29 19:38:38 by arabefam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

int	count_array(char **arr)
{
	int	i;

	i = -1;
	while (arr[++i])
		;
	return (i);
}

int	is_in(char *set, char c)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

void	print_textures(t_txt t[4])
{
	int	i;

	i = -1;
	while (++i < 4)
		printf("%s->%s\n", t[i].id, t[i].path);
}

void	skip(char *set, char *str, int *index)
{
	while (str[*index] && is_in(set, str[*index]))
		(*index)++;
}

bool	is_only(char *set, char *str)
{
	int		i;
	int		j;
	size_t	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		j = 0;
		while (set[j])
		{
			if (str[i] == set[j])
			{
				count++;
				break ;
			}
			j++;
		}
		i++;
	}
	if (count == ft_strlen(str))
		return (true);
	else
		return (false);
}
