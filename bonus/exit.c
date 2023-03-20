/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luhumber <luhumber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 18:16:39 by lucas             #+#    #+#             */
/*   Updated: 2023/03/20 13:36:43 by luhumber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_print_error(char	*str)
{
	char	*join;

	join = ft_strjoin("pipex : ", str);
	perror(join);
	free(join);
	return (1);
}

void	ft_free_cmd(char ***cmd)
{
	int	i;
	int	k;

	i = -1;
	while (cmd[++i])
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
	int	i;

	i = 0;
	ft_free_cmd(pipex->cmd);
	if (pipex->input_fd)
		close(pipex->input_fd);
	if (pipex->file_out)
		close(pipex->file_out);
	free(pipex->pid);
	while (pipex->split_path[i])
		free(pipex->split_path[i++]);
	free(pipex->split_path);
	if (code == 0)
		exit(0);
	else
		exit(1);
}
