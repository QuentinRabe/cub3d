/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabefam <arabefam@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 13:25:23 by arabefam          #+#    #+#             */
/*   Updated: 2025/02/11 08:08:52 by arabefam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

void	print_array(char **arr)
{
	int	i;

	i = -1;
	while (arr[++i])
		printf("%s\n", arr[i]);
}

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

void	init_game(t_vars *v)
{
	v->mlx = mlx_init();
	v->mlx_wind = mlx_new_window(v->mlx, WIDTH, HEIGHT, "cub3D");
	mlx_key_hook(v->mlx_wind, key_hook, (void *) v);
	mlx_loop(v->mlx);
}

int	main(int ac, char **argv)
{
	char	**contents;
	t_vars	vars;

	print_banner();
	if (!has_obvious_error(argv, ac))
	{
		contents = read_content(argv[1]);
		parse(contents, &vars);
		free_array(contents);
		init_game(&vars);
		free_vars(&vars);
	}
	else
		exit (1);
	return (0);
}
