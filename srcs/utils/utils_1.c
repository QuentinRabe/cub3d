/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabefam <arabefam@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 12:02:34 by arabefam          #+#    #+#             */
/*   Updated: 2025/01/16 13:37:03 by arabefam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

bool	is_only(char *set, char *str)
{
	int		i;
	int		j;
	size_t	count;

	i = -1;
	count = 0;
	while (str[++i])
	{
		j = -1;
		while (set[++j])
		{
			if (str[i] == set[j])
			{
				count++;
				break ;
			}
		}
	}
	if (count == ft_strlen(str))
		return (true);
	else
		return (false);
}
