/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luhumber <luhumber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 12:09:35 by luhumber          #+#    #+#             */
/*   Updated: 2022/12/07 11:41:18 by luhumber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

ssize_t	ft_hexa(unsigned long long int num, char c)
{
	char	*base;
	char	ret[17];
	char	*nb_ptr;

	if (c == 'a')
		base = "0123456789abcdef";
	else if (c == 'A')
		base = "0123456789ABCDEF";
	if (num == 0)
		return (write(1, "0", 1));
	ret[16] = '\0';
	nb_ptr = &ret[16];
	*nb_ptr = 0;
	nb_ptr--;
	while (num)
	{
		*nb_ptr-- = base[num % 16];
		num /= 16;
	}
	nb_ptr++;
	return (write(1, nb_ptr, ft_strlen(nb_ptr)));
}
