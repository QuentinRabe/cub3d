/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabefam <arabefam@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 14:16:32 by arabefam          #+#    #+#             */
/*   Updated: 2025/02/10 10:14:15 by arabefam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

static bool	can_be_opened(char *name)
{
	int		fd;
	char	*error;

	error = NULL;
	fd = open(name, O_RDONLY);
	if (fd < 0)
	{
		error = ft_strjoin("No such file named ", name);
		print_error(error);
		free(error);
		return (false);
	}
	close(fd);
	print_success_progress("Filename existence test passed.");
	return (true);
}

static bool	has_excepted_extension(char *name)
{
	char	*extension;
	int		index;

	if (ft_strlen(name) <= 4)
		return (print_error("Map has not the correct extension '.cub'."),
			false);
	index = ft_strlen(name) - 4;
	extension = ft_substr(name, index, 4);
	if (!ft_strcmp(extension, ".cub"))
	{
		if ((name[index - 1] && name[index - 1] == '/'))
			return (print_error("Map has not the correct extension '.cub'."),
				free(extension), false);
		return (print_success_progress("Filename extension test passed."), \
free(extension), true);
	}
	return (print_error("Map has not the correct extension '.cub'."),
		free(extension), false);
}

static bool	has_invalid_args_number(int ac)
{
	if (ac != 2)
	{
		if (ac < 2)
			print_error("Too few argument.");
		else
			print_error("Too many arguments.");
		return (true);
	}
	print_success_progress("Args number test passed.");
	return (false);
}

bool	has_obvious_error(char **argv, int ac)
{
	if (has_invalid_args_number(ac) || !has_excepted_extension(argv[1])
		|| !can_be_opened(argv[1]))
		return (true);
	return (false);
}
