/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabefam <arabefam@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 13:26:07 by arabefam          #+#    #+#             */
/*   Updated: 2025/02/12 11:17:13 by arabefam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# ifndef STAT
#  define STAT 0
# endif
# define SPACES "\t\n\v\f\r "
# define NUMBERS "0123456789\n"
# define ELTS "10NSWE\t\n\v\f\r "
# define ABS_ELTS "10NSWE"
# define BLACK_BLD "\e[1;30m"
# define PLAYER "NSWE"
# define RED_BG "\e[41m"
# define RED "\e[1;91m"
# define GREEN_BG "\e[0;102m"
# define GREEN "\e[1;92m"
# if STAT == 0
#  define ITERATIONS 1000000000
# elif STAT == 1
#  define ITERATIONS 100000000
# else
#  define ITERATIONS 0
# endif
# define WIDTH 960
# define HEIGHT 540
# define TILE 16

# include <stdio.h>
# include <stdbool.h>
# include <libft.h>
# include <get_next_line.h>
# include <data.h>
# include <mlx.h>
# include <ascii.h>

void	mini_map(t_vars *v);
int		get_map_width(char **map);
int		get_map_height(char **map);
/*=============EVENTS=============*/
int		key_hook(int key, t_vars *v);
/*=============UTILS=============*/
void	free_array(char **arr);
void	free_vars(t_vars *vars);
void	print_array(char **arr);
void	print_textures(t_txt t[4]);
void	print_banner(void);
void	print_success_progress(char *step);
int		is_in(char *set, char c);
void	skip(char *set, char *str, int *index);
int		count_array(char **arr);
void	fake_sleep(unsigned long iterations);
/*=============ERROR_HANDLER=============*/
void	print_error(char *error);
size_t	file_lines(char *name);
bool	has_obvious_error(char **argv, int ac);
char	**read_content(char *name);
bool	is_only(char *set, char *str);
/*=============PARSE=============*/
void	parse(char **content, t_vars *vars);
void	parse_texture(char **contents);
void	parse_color(char **contents);
void	parse_map(char **contents, char ***map);
int		parsing_process(char **map);
void	check_process(char **contents, void (*foo)(char*, char**));
void	check_color_values(char *content, char **contents);
void	store_texture(char **contents, t_txt t[4]);
void	store_color(char **contents, t_colors c[2]);
bool	is_texture(char *content);
int		check_left(char **map, int rw, int cl);
int		check_right(char **map, int rw, int cl);
int		check_down(char **map, int rw, int cl);
int		check_up(char **map, int rw, int cl);
char	*trimed_line(char *line);
#endif
