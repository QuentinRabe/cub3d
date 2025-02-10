/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   status.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabefam <arabefam@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 14:20:50 by arabefam          #+#    #+#             */
/*   Updated: 2025/02/10 09:50:56 by arabefam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

void	print_error(char *error)
{
	ft_putstr_fd("\n"RED_BG BLACK_BLD"  Error  "RESET"\n", 2);
	ft_putstr_fd(RED, 2);
	ft_putstr_fd(error, 2);
	ft_putendl_fd(RESET, 2);
}
