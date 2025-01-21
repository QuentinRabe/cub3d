/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabefam <arabefam@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 14:25:19 by arabefam          #+#    #+#             */
/*   Updated: 2025/01/21 14:36:21 by arabefam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

// static void	process(char *content, t_txt t[4], int *i)
// {
// 	char	*id;
// 	char	*path;

// 	id = ft_substr(content, )
// }

void	store_texture(char **contents, t_txt t[4])
{
	int		i;
	int		j;
	int		count;

	(void) j;
	(void) t;
	i = -1;
	count = 0;
	j = 0;
	while (contents[++i] && count < 4)
	{
		if (is_only(SPACES, contents[i])
			|| ft_strlen_set(contents[i], SPACES) < 2)
			continue ;

		count++;
	}
}
