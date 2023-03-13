/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luhumber <luhumber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 10:55:11 by luhumber          #+#    #+#             */
/*   Updated: 2022/12/07 11:41:00 by luhumber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		ret;

	ret = 0;
	i = 0;
	va_start(args, str);
	if (write(1, 0, 0) != 0)
	{
		va_end(args);
		return (-1);
	}
	while (str[i])
	{
		if (str[i] == '%' && str[i + 1])
		{
			ret += ft_checkchar((str[i + 1]), args);
			i++;
		}
		else if (str[i] != '%' && str[i])
			ret += write(1, &str[i], 1);
		i++;
	}
	va_end(args);
	return (ret);
}

int	ft_checkchar(char c, va_list args)
{
	int	print_char;

	print_char = 0;
	if (c == 'c')
		print_char = ft_putchar(va_arg(args, int));
	else if (c == 's')
		print_char += ft_putstr(va_arg(args, char *));
	else if (c == 'p')
	{
		print_char += write (1, "0x", 2);
		print_char += ft_hexa(va_arg(args, unsigned long long int), 'a');
	}
	else if (c == 'd' || c == 'i')
		print_char += ft_putnbr(va_arg(args, int));
	else if (c == 'u')
		print_char += ft_putunsignednbr(va_arg(args, unsigned int));
	else if (c == 'x')
		print_char += ft_hexa(va_arg(args, unsigned int), 'a');
	else if (c == 'X')
		print_char += ft_hexa(va_arg(args, unsigned int), 'A');
	else if (c == '%')
		print_char += ft_putchar(c);
	else
		print_char += ft_putchar(c);
	return (print_char);
}
