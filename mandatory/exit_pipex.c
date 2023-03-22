/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_pipex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luhumber <luhumber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 15:50:37 by luhumber          #+#    #+#             */
/*   Updated: 2023/03/22 11:46:56 by luhumber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_parsing_args(char *cmd)
{
	if (!ft_strncmp("/", cmd, 2))
		return (1);
	if (!ft_strncmp(".", cmd, 1))
		return (1);
	if (!ft_strncmp(" ", cmd, 1))
		return (1);
	return (0);
}

int	ft_exit(t_pipe *pipex)
{
	int	i;

	i = 0;
	free(pipex->cmd1);
	free(pipex->cmd2);
	free(pipex->good_path_1);
	free(pipex->good_path_2);
	while (pipex->split_path[i])
		free(pipex->split_path[i++]);
	free(pipex->split_path);
	i = 0;
	if (pipex->error1 == 0)
		while (pipex->last_cmd1[i])
			free(pipex->last_cmd1[i++]);
	free(pipex->last_cmd1);
	i = 0;
	if (pipex->error2 == 0)
		while (pipex->last_cmd2[i])
			free(pipex->last_cmd2[i++]);
	free(pipex->last_cmd2);
	return (0);
}

int	ft_error(t_pipe *pipex)
{
	ft_printf("%s\n", strerror(errno));
	if (pipex->fd[0])
		close(pipex->fd[0]);
	if (pipex->fd[1])
		close(pipex->fd[1]);
	if (pipex->file_out)
		close(pipex->file_out);
	if (pipex->file_in)
		close(pipex->file_in);
	ft_exit(pipex);
	exit (1);
}
