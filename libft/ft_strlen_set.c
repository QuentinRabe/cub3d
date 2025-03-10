/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen_set.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabefam <arabefam@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 14:25:32 by arabefam          #+#    #+#             */
/*   Updated: 2025/01/16 14:36:31 by arabefam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_is_in(char *set, char c)
{
	int	i;

	i = -1;
	while (set[++i])
	{
		if (c == set[i])
			return (1);
	}
	return (0);
}

size_t	ft_strlen_set(char *str, char *set)
{
	size_t	count;
	int		i;

	i = -1;
	count = 0;
	while (str[++i] && !ft_is_in(set, str[i]))
		count++;
	return (count);
}
