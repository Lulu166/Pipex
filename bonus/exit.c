/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <lucas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 18:16:39 by lucas             #+#    #+#             */
/*   Updated: 2023/03/22 18:07:14 by lucas            ###   ########.fr       */
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

void	ft_close_and_wait(t_pipe *pipex)
{
	int	i;

	i = 0;
	while (pipex->tab_fd[i])
		i++;
	while (i--)
		close(pipex->tab_fd[i]);
	i = 0;
	while (pipex->tab_pid[i])
		i++;
	while (i--)
		waitpid(pipex->tab_pid[i], NULL, 0);
	free(pipex->tab_fd);
	free(pipex->tab_pid);
}

void	ft_end(t_pipe *pipex, int code)
{
	int	i;

	i = 0;
	if (pipex->cmd)
		ft_free_cmd(pipex->cmd);
	if (pipex->input_fd)
		close(pipex->input_fd);
	if (pipex->file_out)
		close(pipex->file_out);
	if (pipex->pid)
		free(pipex->pid);
	while (pipex->split_path[i])
		free(pipex->split_path[i++]);
	free(pipex->split_path);
	ft_close_and_wait(pipex);
	if (code == 0)
		exit(0);
	write(2, "pipex : unexepted error\n", 25);
	exit(1);
}
