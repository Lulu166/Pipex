/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luhumber <luhumber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 13:03:06 by luhumber          #+#    #+#             */
/*   Updated: 2023/02/06 11:17:39 by luhumber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putchar(int c)
{
	return (write(1, &c, 1));
}

int	ft_putstr(char *s)
{
	int	i;

	if (!s)
		return (write (1, "(null)", 6));
	i = 0;
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
	return (i);
}

int	ft_putnbr(int n)
{
	if (n == -2147483648)
		return (ft_putstr("-2147483648"));
	if (n < 0)
		return (ft_putchar('-') + ft_putnbr(-n));
	if (n >= 0 && n < 10)
		return (ft_putchar(n + '0'));
	return ((ft_putnbr(n / 10)) + (ft_putchar((n % 10) + '0')));
}

unsigned int	ft_putunsignednbr(unsigned int n)
{
	if (n > 0 && n < 10)
		return (ft_putchar(n + '0'));
	return ((ft_putnbr(n / 10)) + (ft_putchar((n % 10) + '0')));
}
