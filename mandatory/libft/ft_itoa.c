/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luhumber <luhumber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 09:51:41 by luhumber          #+#    #+#             */
/*   Updated: 2022/11/15 16:26:56 by luhumber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_intlen(long n)
{
	int	l;

	l = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		n = -n;
		l++;
	}
	while (n > 0)
	{
		n /= 10;
		l++;
	}
	return (l);
}

static char	*equal_zero(char *dst)
{
	dst[0] = 48;
	return (dst);
}

char	*ft_itoa(int n)
{
	int		len;
	char	*dst;
	long	nb;

	nb = n;
	len = ft_intlen(nb);
	dst = malloc(sizeof(char) * len + 1);
	if (!dst)
		return (NULL);
	dst[len--] = '\0';
	if (nb == 0)
		return (equal_zero(dst));
	else if (nb < 0)
	{
		dst[0] = '-';
		nb = -nb;
	}
	while (nb > 0)
	{
		dst[len--] = (nb % 10) + 48;
		nb = nb / 10;
	}
	return (dst);
}
