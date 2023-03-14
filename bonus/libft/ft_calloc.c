/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luhumber <luhumber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 14:28:33 by luhumber          #+#    #+#             */
/*   Updated: 2022/11/16 18:16:33 by luhumber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*dst;

	if (count == 0)
		return (malloc(0));
	if ((SIZE_MAX / count) < size)
		return (NULL);
	else
		dst = malloc(count * size);
	if (!dst)
		return (NULL);
	ft_bzero(dst, size * count);
	return (dst);
}
