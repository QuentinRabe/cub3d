/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabefam <arabefam@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 11:54:06 by arabefam          #+#    #+#             */
/*   Updated: 2025/01/09 14:01:46 by arabefam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

bool	is_map_first(int n, char **arr)
{
	int	count;
	int	i;

	count = 0;
	i = -1;
	while (count < n && arr[++i])
	{
		printf("%d - [%s]\n", i, arr[i]);
		if (is_only(SPACES, arr[i]))
			continue;
		if (is_only(ELTS, arr[i]))
		{
			print_error("Map should not go first.");
			return (true);
		}
		count++;
	}
	return (false);
}

bool	contains_at_least(int n, char **arr)
{
	int	count;
	int	i;

	count = 0;
	i = -1;
	while (count < n && arr[++i])
	{
		if (is_only(SPACES, arr[i]))
			continue;
		count++;
	}
	if (count < n)
	{
		print_error("File should contain enough descriptions.");
		return (false);
	}
	return (true);
}

void	parse(char **content)
{
	if (!contains_at_least(6, content) || is_map_first(6, content))
		return ;
}
