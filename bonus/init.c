/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <lucas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 15:48:27 by lucas             #+#    #+#             */
/*   Updated: 2023/03/18 00:15:36 by lucas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_get_path(char *cmd, t_pipe *pipex)
{
	int		j;
	char	*tmp;
	char	*tab;

	j = 0;
	tmp = ft_strjoin("/", cmd);
	while (pipex->split_path[j])
	{
		tab = ft_strjoin(pipex->split_path[j], tmp);
		if (access(tab, F_OK) != -1)
			break ;
		free(tab);
		j++;
	}
	free(tmp);
	return (tab);
}

void	ft_get_env(t_pipe *pipex)
{
	while (*pipex->env_path)
	{
		if (ft_strnstr(*pipex->env_path, "PATH=", 5))
		{
			pipex->path = *pipex->env_path + 5;
			pipex->split_path = ft_split(pipex->path, ':');
			if (!pipex->split_path)
				ft_error(pipex);
			return ;
		}
		pipex->env_path++;
	}
}

void	check_here_doc(t_pipe *pipex, int argc, char **argv)
{
	int	i;

	i = 1;
	if (!ft_strncmp("here_doc", argv[i], ft_strlen(argv[i])))
	{
		pipex->here_doc = 1;
		pipex->limiter = argv[++i];
		pipex->file_out = open
			(argv[argc -1], O_RDWR | O_APPEND | O_CREAT, 0644);
		i++;
	}
	else
	{
		pipex->input_fd = open(argv[1], O_RDONLY);
		pipex->file_out = open
			(argv[argc -1], O_RDWR | O_TRUNC | O_CREAT, 0644);
	}
}

void	init_struct(t_pipe *pipex, int argc, char **argv, char **envp)
{
	int	i;
	int	j;

	i = 2;
	j = 0;
	pipex->env_path = envp;
	pipex->here_doc = 0;
	check_here_doc(pipex, argc, argv);
	pipex->cmd = malloc(sizeof(char **) * (argc - 1));
	ft_get_env(pipex);
	while (i < argc - 1)
	{
		pipex->cmd[j] = ft_split(argv[i], ' ');
		pipex->cmd[j][0] = ft_get_path(pipex->cmd[j][0], pipex);
		i++;
		j++;
	}
	pipex->cmd[j] = NULL;
	pipex->pid = malloc(sizeof(int) * (argc - 2));
}
