/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabefam <arabefam@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 09:53:24 by arabefam          #+#    #+#             */
/*   Updated: 2025/02/21 15:28:38 by arabefam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# include <stdbool.h>

typedef struct s_vars	t_vars;
typedef struct s_txt	t_txt;
typedef struct s_img	t_img;
typedef struct s_colors	t_colors;
typedef struct s_imgs	t_imgs;

enum e_opt
{
	GET,
	SET
};

typedef enum e_opt		t_opt;

struct s_colors
{
	char	*id;
	int		red;
	int		green;
	int		blue;
};

struct s_txt
{
	char	*id;
	char	*path;
};

struct s_imgs
{
	t_img	*mmap;
	t_img	*tile;
	t_img	*floor;
	t_img	*player;
	t_img	*rl_mmap;
};

struct s_img
{
	void	*img;
	char	*addr;
	int		bpp;
	int		size_line;
	int		endian;
	int		width;
	int		height;
};

struct s_vars
{
	t_txt		textures[4];
	t_colors	colors[2];
	t_imgs		*imgs;
	char		**map;
	void		*mlx;
	void		*mlx_win;
	int			mmap_size;
	double		player_x;
	double		player_y;
	double		angle;
	bool		pressed_w;
	bool		pressed_s;
	bool		pressed_a;
	bool		pressed_d;
	bool		pressed_escape;
	bool		pressed_left;
	bool		pressed_right;
};

#endif
