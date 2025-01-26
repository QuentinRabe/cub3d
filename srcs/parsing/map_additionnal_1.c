/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_additionnal_1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabefam <arabefam@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 17:08:29 by arabefam          #+#    #+#             */
/*   Updated: 2025/01/26 17:51:10 by arabefam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

static bool	is_still_map(char *line, int index)
{
	while (line[index] != '\0')
	{
		if (is_in(SPACES, line[index]))
			index += 1;
		else
			return (true);
	}
	return (false);
}

char	*trimed_line(char *line)
{
	size_t	len;

	len = 0;
	while (is_still_map(line, len))
	{
		len += ft_strlen_charset(line + len, '1');
		len += ft_strlen_set(line + len, SPACES);
	}
	return (ft_substr(line, 0, len));
}
