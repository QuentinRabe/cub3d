/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabefam <arabefam@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 14:15:16 by arabefam          #+#    #+#             */
/*   Updated: 2025/01/21 10:49:41 by arabefam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

static size_t	try_to_open_file(char *content, char **contents, \
size_t index, int *count)
{
	char	*filename;
	size_t	len;
	int		fd;

	len = ft_strlen_charset(content + index, '\n');
	filename = ft_substr(content, index, len);
	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		print_error("One or more specified texture paths do not exist.\
 Please verify the paths and try again.");
		close(fd);
		free_array(contents);
		free(filename);
		exit(EXIT_FAILURE);
	}
	close(fd);
	(*count)++;
	free(filename);
	return (len);
}

static void	check_texture_path(char *content, char **contents, \
t_txt t[4], int *j)
{
	size_t		index;
	static int	count = 0;
	size_t		len;

	if (count < 4)
	{
		index = ft_strlen_set(content, SPACES) + 1;
		if (index == 2)
			return ;
		len = try_to_open_file(content, contents, index, &count);
		t[*j].id = ft_substr(content, 0, 2);
		t[*j].path = ft_substr(content, index, len);
		(*j)++;
	}
	if (count == 4)
		count = 0;
}

static void	check_id(char *id, int *bits)
{
	if (!ft_strcmp(id, "NO"))
		*bits |= 1 << 5;
	else if (!ft_strcmp(id, "SO"))
		*bits |= 1 << 4;
	else if (!ft_strcmp(id, "WE"))
		*bits |= 1 << 3;
	else if (!ft_strcmp(id, "EA"))
		*bits |= 1 << 2;
	else if (!ft_strcmp(id, "F"))
		*bits |= 1 << 1;
	else if (!ft_strcmp(id, "C"))
		*bits |= 1;
}

static void	check_valid_identifier(char *content, char **contents)
{
	char		*id;
	size_t		len;
	static int	bits = 0;
	static int	count = 0;

	len = ft_strlen_set(content, SPACES);
	id = ft_substr(content, 0, len);
	check_id(id, &bits);
	free(id);
	count++;
	if (count == 6)
	{
		if (bits != 63)
		{
			print_error("The file contains one or more invalid identifiers.\
 Valid identifiers are: NO, EA, SO, WE, F, C.\
 Please check them and ensure all identifiers are unique and valid.");
			free_array(contents);
			exit(EXIT_FAILURE);
		}
		bits = 0;
		count = 0;
	}
}

void	parse_texture(char **contents, t_txt t[4])
{
	int	i;
	int	count;
	int	j;

	i = -1;
	count = 0;
	j = 0;
	while (count < 6 && contents[++i])
	{
		if (is_only(SPACES, contents[i]))
			continue ;
		check_valid_identifier(contents[i], contents);
		check_texture_path(contents[i], contents, t, &j);
		count++;
	}
}
