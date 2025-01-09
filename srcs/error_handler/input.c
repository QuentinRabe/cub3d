/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabefam <arabefam@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 14:16:32 by arabefam          #+#    #+#             */
/*   Updated: 2025/01/09 08:24:43 by arabefam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

static bool	has_excepted_extension(char *name)
{
	char	*extension;
	int		index;

	if (ft_strlen(name) <= 4)
		return (print_error("Map has not the correct extension '.cub'\n"),
			false);
	index = ft_strlen(name) - 4;
	extension = ft_substr(name, index, 4);
	if (!ft_strcmp(extension, ".cub"))
	{
		if ((name[index - 1] && name[index - 1] == '/'))
			return (print_error("Map has not the correct extension '.cub'\n"),
				free(extension), false);
		return (free(extension), true);
	}
	return (print_error("Map has not the correct extension '.cub'\n"),
		free(extension), false);
}

static bool	has_invalid_args_number(int ac)
{
	if (ac != 2)
	{
		if (ac < 2)
			print_error("Too few argument.\n");
		else
			print_error("Too many arguments.\n");
		return (true);
	}
	return (false);
}

bool	has_obvious_error(char **argv, int ac)
{
	if (has_invalid_args_number(ac) || !has_excepted_extension(argv[1]))
		return (true);
	return (false);
}
