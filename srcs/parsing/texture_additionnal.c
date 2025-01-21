/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_additionnal.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabefam <arabefam@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 21:57:47 by arabefam          #+#    #+#             */
/*   Updated: 2025/01/21 21:59:10 by arabefam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

void	check_process(char **contents, void (*foo)(char*, char**))
{
	int	i;
	int	count;

	i = -1;
	count = 0;
	while (count < 6 && contents[++i])
	{
		if (is_only(SPACES, contents[i]))
			continue ;
		foo(contents[i], contents);
		count++;
	}
}
