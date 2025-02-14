/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vars.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabefam <arabefam@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 07:17:33 by arabefam          #+#    #+#             */
/*   Updated: 2025/02/14 07:23:30 by arabefam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

t_vars	*vars_addr(t_opt option, t_vars *addr)
{
	static t_vars	*ptr;

	if (option == SET)
		ptr = addr;
	return (ptr);
}
