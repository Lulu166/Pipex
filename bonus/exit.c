/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <lucas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 18:16:39 by lucas             #+#    #+#             */
/*   Updated: 2023/03/19 23:30:23 by lucas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_free_cmd(char ***cmd)
{
	int	i;
	int	k;

	i = -1;
	while (cmd[i++])
	{
		k = -1;
		while (cmd[i][++k])
			free(cmd[i][k]);
		free(cmd[i]);
	}
	free(cmd);
}

int	ft_error(t_pipe *pipex)
{
	write(2, strerror(errno), ft_strlen(strerror(errno)));
	write(2, "\n", 1);
	ft_end(pipex, 1);
	exit(1);
}

void	ft_end(t_pipe *pipex, int code)
{
	ft_free_cmd(pipex->cmd);
	close(pipex->input_fd);
	close(pipex->file_out);
	free(pipex->pid);
	free(pipex);
	if (code == 0)
		exit(0);
	else
		exit(1);
}
