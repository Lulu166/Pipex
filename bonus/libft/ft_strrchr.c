/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luhumber <luhumber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 20:14:36 by lucas             #+#    #+#             */
/*   Updated: 2022/11/16 18:40:50 by luhumber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	char	ch;
	char	*p;

	ch = c;
	p = (char *) 0;
	if ((unsigned char)c == 0)
		return ((char *)&str[ft_strlen(str)]);
	while (*str)
	{
		if (*str == ch)
			p = (char *)str;
		str++;
	}
	return (p);
}
