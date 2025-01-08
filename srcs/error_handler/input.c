/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabefam <arabefam@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 14:16:32 by arabefam          #+#    #+#             */
/*   Updated: 2025/01/08 14:27:17 by arabefam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

static bool	has_invalid_args_number(int ac)
{
	if (ac != 2)
	{
		if (ac < 2)
			print_error("Too few argument.\n");
		else
			print_error("Too many arguments.\n");
		return (true);
	}
	return (false);
}

bool	has_obvious_error(char **argv, int ac)
{
	(void) argv;
	if (has_invalid_args_number(ac))
		return (true);
	return (false);
}
