/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabefam <arabefam@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 14:15:16 by arabefam          #+#    #+#             */
/*   Updated: 2025/01/21 17:31:52 by arabefam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

static void	try_to_open_file(char *content, char **contents, \
size_t index, int *count)
{
	char	*filename;
	size_t	len;
	int		fd;

	skip(SPACES, content, (int *)&index);
	len = ft_strlen_charset(content + index, '\n');
	filename = ft_substr(content, index, len);
	printf("filename: %s\n", filename);
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
}

static void	check_texture_path(char *content, char **contents)
{
	size_t		index;
	int			i;
	static int	count = 0;

	i = 0;
	skip(SPACES, content, &i);
	if (count < 4)
	{
		index = ft_strlen_set(content + i, SPACES);
		if (index == 1)
			return ;
		skip(SPACES, content + i, &i);
		try_to_open_file(content + i, contents, index, &count);
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
	int			i = 0;
	static int	bits = 0;
	static int	count = 0;

	skip(SPACES, content, &i);
	len = ft_strlen_set(content + i, SPACES);
	id = ft_substr(content, i, len);
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

void	parse_texture(char **contents)
{
	int	i;
	int	count;

	i = -1;
	count = 0;
	while (count < 6 && contents[++i])
	{
		if (is_only(SPACES, contents[i]))
			continue ;
		check_valid_identifier(contents[i], contents);
		check_texture_path(contents[i], contents);
		count++;
	}
}
