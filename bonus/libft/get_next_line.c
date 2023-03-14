/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luhumber <luhumber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 09:57:16 by luhumber          #+#    #+#             */
/*   Updated: 2023/01/09 12:44:39 by luhumber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_read(int fd, char *buf)
{
	char		*new_buffer;
	int			nbchr;

	nbchr = 1;
	new_buffer = NULL;
	if (buf)
		new_buffer = ft_joinbuffer(new_buffer, buf);
	while (!ft_strchr(buf, '\n') && nbchr)
	{
		nbchr = read(fd, buf, BUFFER_SIZE);
		if (nbchr < 0)
			return (free(buf), NULL);
		buf[nbchr] = '\0';
		new_buffer = ft_joinbuffer(new_buffer, buf);
	}
	return (new_buffer);
}

void	ft_setup_buffer(char *buff_t, char *buffer)
{
	int		i;
	int		k;
	char	*dst;

	i = 0;
	while (buff_t[i] && buff_t[i] != '\n')
		i++;
	if (buff_t[i++] == '\0')
		return ;
	dst = malloc(sizeof(char *) * ((ft_new_strlen(buff_t) - i) + 1));
	if (!dst)
		return ;
	k = 0;
	while (buff_t[i])
	{
		dst[k] = buff_t[i];
		i++;
		k++;
	}
	dst[k] = 0;
	i = -1;
	while (dst[++i])
		buffer[i] = dst[i];
	buffer[i] = 0;
	free(dst);
}

char	*ft_setup_line(char *buff_t, char *line)
{
	int			i;

	i = 0;
	if (!buff_t[0])
		return (NULL);
	while (buff_t[i] != '\n' && buff_t[i] != '\0')
		i++;
	line = malloc(sizeof(char *) * (i + 1));
	if (!line)
		return (NULL);
	i = 0;
	while (buff_t[i] != '\n' && buff_t[i] != '\0')
	{
		line[i] = buff_t[i];
		i++;
	}
	if (buff_t[i] == '\n')
	{
		line[i] = '\n';
		i++;
	}
	line[i] = 0;
	return (line);
}

char	*get_next_line(int fd)
{
	static char		buffer[BUFFER_SIZE + 1];
	char			*buff_t;
	char			*line;

	line = NULL;
	if (fd < 0 || read(fd, 0, 0) || BUFFER_SIZE <= 0)
		return (NULL);
	buff_t = ft_read(fd, buffer);
	line = ft_setup_line(buff_t, line);
	ft_setup_buffer(buff_t, buffer);
	free(buff_t);
	return (line);
}
