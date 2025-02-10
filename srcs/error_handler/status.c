/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   status.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabefam <arabefam@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 14:20:50 by arabefam          #+#    #+#             */
/*   Updated: 2025/02/10 10:08:48 by arabefam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

void	print_success_progress(char *step)
{
	ft_putstr_fd(GREEN_BG BLACK_BLD"  Ok  "RESET"\n", 2);
	ft_putstr_fd("✅ ", 2);
	ft_putstr_fd(GREEN, 2);
	ft_putstr_fd(step, 2);
	ft_putendl_fd(RESET, 2);
}

void	print_error(char *error)
{
	ft_putstr_fd(RED_BG BLACK_BLD"  Error  "RESET"\n", 2);
	ft_putstr_fd("❌ ", 2);
	ft_putstr_fd(RED, 2);
	ft_putstr_fd(error, 2);
	ft_putendl_fd(RESET, 2);
}
