/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabefam <arabefam@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 13:25:23 by arabefam          #+#    #+#             */
/*   Updated: 2025/01/21 11:40:26 by arabefam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

void	free_array(char **arr)
{
	int	i;

	i = -1;
	while (arr[++i])
		free(arr[i]);
	free(arr);
}

void	print_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		if (!is_only(SPACES, map[i]))
			printf("%s", map[i]);
		i++;
	}
}

int	main(int ac, char **argv)
{
	char	**contents;
	t_vars	vars;

	if (!has_obvious_error(argv, ac))
	{
		contents = read_content(argv[1]);
		parse(contents, &vars);
		// print_textures(vars.textures);
		free_array(contents);
		ft_putstr_fd("No error.\n", 1);
	}
	else
		exit (1);
	return (0);
}
