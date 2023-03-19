/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <lucas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 13:57:59 by lucas             #+#    #+#             */
/*   Updated: 2023/03/15 16:54:29 by lucas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

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
