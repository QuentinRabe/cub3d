/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   macros.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabefam <arabefam@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 15:10:40 by arabefam          #+#    #+#             */
/*   Updated: 2025/02/21 19:44:02 by arabefam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MACROS_H
# define MACROS_H
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
# define MOVE_SPEED 0.8
# define MMAP_SIZE 200

#endif
