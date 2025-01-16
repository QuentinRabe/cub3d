/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabefam <arabefam@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 14:15:16 by arabefam          #+#    #+#             */
/*   Updated: 2025/01/16 15:15:57 by arabefam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

void	check_id(char *id, int *bits)
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

void	check_valid_identifier(char *content, char **contents)
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
 Valid identifiers are: NO, EA, SO, WE, F, C. Please check them and ensure all identifiers are unique and valid.");
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
		count++;
	}
}
