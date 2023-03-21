/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luhumber <luhumber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 22:50:30 by lucas             #+#    #+#             */
/*   Updated: 2023/03/21 15:30:52 by luhumber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_execute(t_pipe *pipex, int fd[2], int i)
{
	if (dup2(pipex->input_fd, STDIN_FILENO) == -1)
		return (ft_print_error("dup2"));
	close(fd[0]);
	if (pipex->cmd[i + 1] != NULL && dup2(fd[1], 1) == -1)
		return (ft_print_error("dup2"));
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
		return (ft_print_error("dup2"));
	while (pipex->cmd[i] != NULL)
	{
		if (pipe(fd) == -1)
			return (ft_print_error("pipe"));
		pid = fork();
		if (pid == -1)
			ft_print_error("pipe");
		else if (pid == 0)
			if (!ft_execute(pipex, fd, i))
				return (1);
		pipex->tab_pid[i] = pid;
		pipex->tab_fd[i] = pipex->input_fd;
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
	ft_end(&pipex, 0);
	return (0);
}
