/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luhumber <luhumber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 14:22:38 by luhumber          #+#    #+#             */
/*   Updated: 2023/03/14 13:44:34 by luhumber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_child(t_pipe *pipex)
{
	if (pipex->error2 == 1)
		return ;
	pipex->pid2 = fork();
	if (pipex->pid2 < 0)
		ft_error(pipex);
	if (pipex->pid2 == 0)
	{
		if (pipex->file_out == -1)
			ft_error(pipex);
		if (dup2(pipex->fd[0], STDIN_FILENO) == -1)
			ft_error(pipex);
		if (dup2(pipex->file_out, STDOUT_FILENO) == -1)
			ft_error(pipex);
		close(pipex->fd[0]);
		//close(pipex->fd[1]);
		if (pipex->last_cmd2 != NULL)
			execve(pipex->good_path_2, pipex->last_cmd2, pipex->env_path);
	}
}

void	ft_parent(t_pipe *pipex)
{
	if (pipex->error1 == 1 || pipex->file_error == 1)
		return ;
	pipex->pid1 = fork();
	if (pipex->pid1 < 0)
		ft_error(pipex);
	if (pipex->pid1 == 0)
	{
		if (dup2(pipex->fd[1], STDOUT_FILENO) == -1)
			ft_error(pipex);
		if (dup2(pipex->file_in, STDIN_FILENO) == -1)
			ft_error(pipex);
		//close(pipex->fd[0]);
		close(pipex->fd[1]);
		if (pipex->last_cmd1 != NULL)
			execve(pipex->last_cmd1[0], pipex->last_cmd1, pipex->env_path);
	}
}

void	ft_pipex_algo(t_pipe *pipex)
{
	ft_get_path(pipex);
	if (pipe(pipex->fd) == -1)
		ft_error(pipex);
	ft_good_path(pipex, 0);
	ft_parent(pipex);
	if (pipex->file_error == 1)
		ft_printf("%s\n", strerror(errno));
	ft_child(pipex);
	//close(pipex->fd[0]);
	//close(pipex->fd[1]);
	if (pipex->error1 == 0 && pipex->error2 == 0)
	{
		if (pipex->pid1)
			waitpid(pipex->pid1, NULL, 0);
		if (pipex->pid2)
			waitpid(pipex->pid2, NULL, 0);
	}
}

void	ft_get_path(t_pipe *pipex)
{
	while (*pipex->env_path)
	{
		if (ft_strnstr(*pipex->env_path, "PATH=", 5))
		{
			pipex->path = *pipex->env_path + 5;
			return ;
		}
		pipex->env_path++;
	}
	if (pipex->found == 1)
		ft_error(pipex);
}

int	main(int argc, char **argv, char **envp)
{
	t_pipe	pipex;

	if (argc != 5)
	{
		write(STDERR_FILENO, "pipex : Error args\n", 20);
		exit (1);
	}
	if (!envp || !envp[0])
	{
		write(STDERR_FILENO, "pipex : Error envp\n", 20);
		exit(1);
	}
	ft_create_struct(&pipex, argv, envp);
	ft_pipex_algo(&pipex);
	if (pipex.file_out)
		close(pipex.file_out);
	if (pipex.file_in)
		close(pipex.file_in);
	if (pipex.fd[0])
		close(pipex.fd[0]);
	if (pipex.fd[1])
		close(pipex.fd[1]);
	ft_exit(&pipex);
	return (0);
}