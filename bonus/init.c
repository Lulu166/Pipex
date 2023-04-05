/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luhumber <luhumber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 15:48:27 by lucas             #+#    #+#             */
/*   Updated: 2023/04/05 11:15:55 by luhumber         ###   ########.fr       */
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

char	*ft_get_path(char *cmd, t_pipe *pipex)
{
	int		j;
	char	*tmp;
	char	*tab;

	j = 0;
	tab = NULL;
	if (ft_parsing_args(cmd) == 0)
	{
		tmp = ft_strjoin("/", cmd);
		while (pipex->split_path[j])
		{
			tab = ft_strjoin(pipex->split_path[j], tmp);
			if (access(tab, F_OK) != -1)
				break ;
			free(tab);
			tab = NULL;
			j++;
		}
		free(tmp);
	}
	if (!tab)
		return (ft_printf("pipex : command not found: %s\n", cmd), free(cmd),
			NULL);
	free(cmd);
	return (tab);
}

void	ft_allocate_cmd(t_pipe *pipex, int argc, char **argv, int i)
{
	int	j;

	j = 0;
	pipex->cmd = malloc(sizeof(char **) * (argc));
	if (!pipex->cmd)
		ft_end(pipex, 1);
	while (i < argc)
	{
		pipex->cmd[j] = ft_split(argv[i], ' ');
		if (!pipex->cmd[j])
			ft_end(pipex, 1);
		pipex->cmd[j][0] = ft_get_path(pipex->cmd[j][0], pipex);
		i++;
		j++;
	}
	pipex->cmd[j] = NULL;
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
		pipex->input_fd = open(argv[i++], O_RDONLY);
		if (pipex->input_fd == -1)
		{
			ft_print_error(argv[i -1]);
			pipex->input_fd = 1;
		}
		pipex->file_out = open
			(argv[argc -1], O_RDWR | O_TRUNC | O_CREAT, 0644);
	}
}

void	init_struct(t_pipe *pipex, int argc, char **argv, char **envp)
{
	pipex->env_path = envp;
	pipex->here_doc = 0;
	pipex->tab_fd = ft_calloc(sizeof(int), (argc - 2));
	pipex->tab_pid = ft_calloc(sizeof(pid_t), (argc - 2));
	pipex->pid = NULL;
	check_here_doc(pipex, argc, argv);
	ft_get_env(pipex);
	if (pipex->here_doc == 0)
	{
		ft_allocate_cmd(pipex, argc - 1, argv, 2);
		pipex->pid = malloc(sizeof(int) * (argc - 2));
		if (!pipex->pid)
			ft_end(pipex, 1);
	}
	else if (pipex->here_doc == 1)
	{
		ft_allocate_cmd(pipex, argc - 1, argv, 3);
		pipex->pid = malloc(sizeof(int) * (argc - 3));
		if (!pipex->pid)
			ft_end(pipex, 1);
	}
}
