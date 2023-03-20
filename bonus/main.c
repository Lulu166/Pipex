/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <lucas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 22:50:30 by lucas             #+#    #+#             */
/*   Updated: 2023/03/19 23:33:47 by lucas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_execute(t_pipe *pipex, int fd[2], int i)
{
	if (dup2(pipex->input_fd, STDIN_FILENO) == -1)
		ft_error(pipex);
	if (pipex->cmd[i + 1] != NULL)
		if (dup2(fd[1], 1) == -1)
			ft_error(pipex);
	close(fd[0]);
	if (execve(pipex->cmd[i][0], pipex->cmd[i], pipex->env_path) == -1)
		return (0);
	return (1);
}

int	ft_pipex_algo(t_pipe *pipex)
{
	int		fd[2];
	int		i;
	pid_t	pid;

	i = 0;
	if (dup2(pipex->file_out, STDOUT_FILENO) == -1)
		ft_error(pipex);
	while (pipex->cmd[i] != NULL)
	{
		if (pipe(fd) == -1)
			ft_error(pipex);
		pid = fork();
		if (pid == -1)
			ft_error(pipex);
		else if (pid == 0)
			if (!ft_execute(pipex, fd, i))
				return (1);
		waitpid(pid, NULL, 1);
		pipex->input_fd = fd[0];
		close(fd[1]);
		i++;
	}
	return (0);
}

int	ft_here_doc(t_pipe *pipex)
{
	char	*line;
	int		fd[2];

	if (pipex->here_doc == 1)
	{
		if (pipe(fd) == -1)
			ft_error(pipex);
		while (1)
		{
			write(1, "heredoc>", 8);
			line = get_next_line(1);
			if (!ft_strncmp(line, pipex->limiter, ft_strlen(line) - 1))
				break ;
			write(fd[1], line, ft_strlen(line));
			write(fd[1], "\n", 1);
			free(line);
		}
		free(line);
		pipex->input_fd = fd[0];
		close(fd[1]);
	}
	return (0);
}

int	main(int argc, char **argv, char **envp)
{
	t_pipe	pipex;

	if (argc < 5)
	{
		write(STDERR_FILENO, "pipex : Error args\n", 20);
		exit (1);
	}
	if (!envp || !envp[0])
	{
		write(STDERR_FILENO, "pipex : Error envp\n", 20);
		exit(1);
	}
	init_struct(&pipex, argc, argv, envp);
	if (ft_here_doc(&pipex))
		return (0);
	ft_pipex_algo(&pipex);
	// TODO cmd qui ne message pas d'erreur
	// TODO remplacer ancien outfile ??
	//ft_end(&pipex, 0);
	return (0);
}
