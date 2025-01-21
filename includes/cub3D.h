/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabefam <arabefam@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 13:26:07 by arabefam          #+#    #+#             */
/*   Updated: 2025/01/21 11:34:01 by arabefam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# define SPACES "\t\n\v\f\r "
# define NUMBERS "0123456789\n"
# define ELTS "10P\n"

# include <stdio.h>
# include <stdbool.h>
# include <libft.h>
# include <get_next_line.h>
# include <data.h>

/*=============UTILS=============*/
void	free_array(char **arr);
void	print_textures(t_txt t[4]);
void	skip(char *set, char *str, int *index);
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
void	check_color_values(char *content, char **contents);
#endif
