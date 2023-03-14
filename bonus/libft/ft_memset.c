/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luhumber <luhumber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 17:11:08 by lucas             #+#    #+#             */
/*   Updated: 2022/11/14 10:02:10 by luhumber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t n)
{
	char			*str;
	unsigned char	ch;
	size_t			i;

	str = (char *)b;
	ch = c;
	i = 0;
	while (i < n)
	{
		str[i] = ch;
		i++;
	}
	return (str);
}
