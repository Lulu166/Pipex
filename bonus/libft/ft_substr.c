/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luhumber <luhumber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 15:34:28 by luhumber          #+#    #+#             */
/*   Updated: 2022/11/14 16:13:59 by luhumber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	char	*dst;

	j = 0;
	i = start;
	if (!s || start > ft_strlen(s))
		return (ft_strdup(""));
	if (len > ft_strlen(&s[start]))
		dst = malloc(sizeof(char) * (ft_strlen(&s[start]) + 1));
	else
		dst = malloc(sizeof(char) * (len + 1));
	if (dst == NULL)
		return (NULL);
	while (s[i] && j < len)
	{
		dst[j] = s[i];
		i++;
		j++;
	}
	dst[j] = 0;
	return (dst);
}
