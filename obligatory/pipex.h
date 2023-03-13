/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luhumber <luhumber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 14:24:16 by luhumber          #+#    #+#             */
/*   Updated: 2023/03/02 14:05:49 by luhumber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/wait.h>
# include "libft/libft.h"
# include <string.h>
# include <errno.h>

typedef struct pipe {
	int		fd[2];
	int		pid1;
	int		pid2;
	char	**env_path;
	char	*path;
	char	*file1;
	char	*file2;
	int		file_in;
	int		file_out;
	char	*cmd1;
	char	*cmd2;
	char	**last_cmd1;
	char	**last_cmd2;
	char	**split_path;
	char	*good_path_1;
	char	*good_path_2;
	int		tab_size;
	int		found;
	int		error1;
	int		error2;
	int		file_error;
}	t_pipe;

void	ft_create_struct(t_pipe *pipex, char **argv, char **envp);
char	*ft_find_path(t_pipe *pipex, char **cmd);
void	ft_get_path(t_pipe *pipex);
void	ft_good_path(t_pipe *pipex, int i);
int		ft_error(t_pipe *pipex);
int		ft_exit(t_pipe *pipex);
int		ft_parsing_args(char *cmd);

#endif