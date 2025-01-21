/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabefam <arabefam@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 09:53:24 by arabefam          #+#    #+#             */
/*   Updated: 2025/01/21 10:00:34 by arabefam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_H
# define DATA_H

typedef struct s_vars	t_vars;
typedef struct s_txt	t_txt;
typedef struct s_colors	t_colors;

struct s_txt
{
	char	*id;
	char	*path;
};

struct s_vars
{
	t_txt	textures[4];
};

#endif
