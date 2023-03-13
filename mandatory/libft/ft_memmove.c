/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luhumber <luhumber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 14:25:56 by luhumber          #+#    #+#             */
/*   Updated: 2022/11/14 12:38:37 by luhumber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*d;
	char		*s;

	d = (char *)dst;
	s = (char *)src;
	if (dst > src)
		while (len--)
			d[len] = s[len];
	else
		ft_memcpy(d, s, len);
	return ((void *)d);
}
