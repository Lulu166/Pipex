/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luhumber <luhumber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 16:22:28 by luhumber          #+#    #+#             */
/*   Updated: 2022/11/16 14:58:31 by luhumber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_check(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		len;
	int		k;
	char	*dst;

	i = 0;
	if (!s1 || !set)
		return (NULL);
	len = ft_strlen(s1) - 1;
	while (ft_check(s1[i], set) == 1)
		i++;
	while (ft_check(s1[len], set) == 1 && (len > 0))
		len--;
	len++;
	k = len - i;
	if (len + i == 1)
		return ("");
	dst = ft_substr(s1, i, k);
	return (dst);
}
