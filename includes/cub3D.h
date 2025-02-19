/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabefam <arabefam@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 13:26:07 by arabefam          #+#    #+#             */
/*   Updated: 2025/02/19 07:06:44 by arabefam         ###   ########.fr       */
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
# define HITBOX_OFFSET 4
# define ROTATE_ANGLE 1.0
# if STAT == 0
#  define ITERATIONS 1000000000
# elif STAT == 1
#  define ITERATIONS 100000000
# else
#  define ITERATIONS 0
# endif
# define WIDTH 960
# define HEIGHT 540
# define TILE 32
# define MOVE_SPEED 0.15
# define MMAP_SIZE 200
#define KEY_W 119
#define KEY_A 97
#define KEY_S 115
#define KEY_D 100

# include <stdio.h>
# include <stdbool.h>
# include <libft.h>
# include <get_next_line.h>
# include <data.h>
# include <mlx.h>
# include <ascii.h>
# include <math.h>
# include <X11/keysym.h>

void	mini_map(t_vars *v);
int		get_map_width(char **map);
int		get_map_height(char **map);
/*=============EVENTS=============*/
int		end_game(t_vars *v);
int		key_press(int key, t_vars *v);
int		key_release(int key, t_vars *v);
int		game_loop(t_vars *v);
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
/*=============GETTETS_SETTERS=============*/
t_vars	*vars_addr(t_opt option, t_vars *addr);
t_img	*player_addr(t_opt option, t_img *addr);
t_img	*tile_addr(t_opt option, t_img *addr);
t_img	*mmap_addr(t_opt option, t_img *addr);
t_img	*floor_addr(t_opt option, t_img *addr);
/*=============SAFE_FUNCTIONS=============*/
void	safe_xpm_file_to_img(t_vars *v, t_img *new_img, char *filename);
void	safe_get_data_addr(t_img *new_img);
void	safe_new_img(t_vars *v, t_img *new_img, int width, int height);
void	safe_destroy_img(t_vars *v, t_img **img_to_delete);
/*=============IMAGE=============*/
t_img	*new_img(char *filename, int *width, int *height);
/*=============RENDER_MMAP=============*/
void	render_mmap(t_img *m, t_img *t, t_img *p, t_img *f);
void	destroy_mmap_img(t_img **m, t_img **t, t_img **p, t_img **f);
/*=============CPY_IMG=============*/
void	put_img_to_img(t_img *dst, t_img *src, int x, int y);
void	init_images(t_img **m, t_img **t, t_img **p, t_img **f);
/*=============PLAYER_MOVE=============*/
void	move_forward(t_img **m, t_img **t, t_img **p, t_img **f);
void	move_backward(t_img **m, t_img **t, t_img **p, t_img **f);
void	move_left(t_img **m, t_img **t, t_img **p, t_img **f);
void	move_right(t_img **m, t_img **t, t_img **p, t_img **f);
void	rotate_right(t_vars *v);
void	rotate_left(t_vars *v);
int		check_wall(t_vars *v, double new_x, double new_y);
#endif
