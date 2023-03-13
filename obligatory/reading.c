/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reading.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luhumber <luhumber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 17:04:51 by luhumber          #+#    #+#             */
/*   Updated: 2023/03/02 14:10:14 by luhumber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_make_calloc(t_pipe *pipex, int code)
{
	if (code == 1)
	{
		pipex->error1++;
		pipex->good_path_1 = ft_calloc(1, 1);
		pipex->last_cmd1 = ft_calloc(1, 1);
		if (pipex->file_error == 0)
			write(STDERR_FILENO, "pipex : command not found\n", 27);
	}
	if (code == 2)
	{
		pipex->error2++;
		pipex->good_path_2 = ft_calloc(1, 1);
		pipex->last_cmd2 = ft_calloc(1, 1);
		write(STDERR_FILENO, "pipex : command not found\n", 27);
	}
}

char	*ft_loop_access(t_pipe *pipex, char *tmp, char **cmd)
{
	char	*tab;
	int		i;
	int		k;

	i = 0;
	while (i < pipex->tab_size)
	{
		k = 0;
		tab = ft_strjoin(pipex->split_path[i], tmp);
		while (tab[k] && tab[k] != ' ')
			k++;
		tab[k] = '\0';
		if (access(tab, F_OK) != -1)
			break ;
		free(tab);
		i++;
	}
	*cmd = ft_strjoin(pipex->split_path[i], tmp);
	free(tmp);
	return (tab);
}

char	*ft_allocate_cmd(t_pipe *pipex, char *cmd)
{
	char	*buff;
	int		i;
	int		k;

	i = 0;
	k = 0;
	buff = malloc(sizeof(char) * (ft_strlen(cmd) + 2));
	if (!buff)
		ft_error(pipex);
	buff[i] = '/';
	i++;
	while (cmd[k])
		buff[i++] = cmd[k++];
	buff[i] = '\0';
	return (buff);
}

char	*ft_find_path(t_pipe *pipex, char **cmd)
{
	char	*tmp;

	if (*cmd == NULL)
		return (NULL);
	if (access(*cmd, F_OK) != -1)
	{
		*cmd = ft_strdup(*cmd);
		return (ft_strdup(*cmd));
	}
	tmp = ft_allocate_cmd(pipex, *cmd);
	return (ft_loop_access(pipex, tmp, cmd));
}

void	ft_good_path(t_pipe *pipex, int i)
{
	pipex->split_path = ft_split(pipex->path, ':');
	if (!pipex->split_path)
		ft_error(pipex);
	while (pipex->split_path[i++])
		pipex->tab_size = i;
	pipex->good_path_1 = ft_find_path(pipex, &pipex->cmd1);
	if (pipex->cmd1 != NULL)
	{
		pipex->last_cmd1 = ft_split(pipex->cmd1, ' ');
		if (!pipex->last_cmd1)
			ft_error(pipex);
	}
	else
		ft_make_calloc(pipex, 1);
	pipex->good_path_2 = ft_find_path(pipex, &pipex->cmd2);
	if (pipex->cmd2 != NULL)
	{
		pipex->last_cmd2 = ft_split(pipex->cmd2, ' ');
		if (!pipex->last_cmd2)
			ft_error(pipex);
	}
	else
		ft_make_calloc(pipex, 2);
}
