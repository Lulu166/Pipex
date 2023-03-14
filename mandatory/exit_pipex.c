/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_pipex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luhumber <luhumber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 15:50:37 by luhumber          #+#    #+#             */
/*   Updated: 2023/03/14 14:43:24 by luhumber         ###   ########.fr       */
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

void	ft_create_struct(t_pipe *pipex, char **argv, char **envp)
{
	pipex->file1 = argv[1];
	if (ft_parsing_args(argv[2]) == 0 && argv[2][0] != '\0')
		pipex->cmd1 = argv[2];
	else
		pipex->cmd1 = NULL;
	if (ft_parsing_args(argv[3]) == 0 && argv[3][0] != '\0')
		pipex->cmd2 = argv[3];
	else
		pipex->cmd2 = NULL;
	pipex->file2 = argv[4];
	pipex->env_path = envp;
	pipex->error1 = 0;
	pipex->error2 = 0;
	pipex->file_error = 0;
	pipex->file_out = open(pipex->file2, O_WRONLY
			| O_TRUNC | O_CREAT, 0644);
	pipex->file_in = open(pipex->file1, O_RDONLY);
	if (pipex->file_in == -1)
		pipex->file_error = 1;
	pipex->pid1 = -1;
	pipex->pid2 = -1;
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
