/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabefam <arabefam@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 13:25:23 by arabefam          #+#    #+#             */
/*   Updated: 2025/02/14 20:31:03 by arabefam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data.h"
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
	v->mlx_win = mlx_new_window(v->mlx, WIDTH, HEIGHT, "cub3D");
	mini_map(v);
	mlx_hook(v->mlx_win, 2, 1L << 0, key_press, v);
	mlx_hook(v->mlx_win, 3, 1L << 1, key_release, v);
	mlx_loop_hook(v->mlx, game_loop, v);
	mlx_loop(v->mlx);
}

int	main(int ac, char **argv)
{
	char	**contents;
	t_vars	vars;

	vars_addr(SET, &vars);
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
