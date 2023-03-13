/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luhumber <luhumber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 18:37:06 by lucas             #+#    #+#             */
/*   Updated: 2022/11/16 18:40:56 by luhumber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	int	i;

	i = 0;
	if ((unsigned char)c == 0)
		return ((char *)&str[ft_strlen(str)]);
	while (str[i])
	{
		if ((unsigned char)(str[i]) == (unsigned char)c)
			return ((char *)(str + i));
		i++;
	}
	return (NULL);
}
