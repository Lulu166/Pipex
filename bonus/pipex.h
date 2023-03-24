/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <lucas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 14:24:16 by luhumber          #+#    #+#             */
/*   Updated: 2023/03/24 22:15:26 by lucas            ###   ########.fr       */
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
# include <stdio.h>
# include <errno.h>

typedef struct pipe {
	int		cpy_out;
	int		*pid;
	int		input_fd;
	int		file_out;
	int		*tab_pid;
	int		*tab_fd;
	char	***cmd;
	char	**env_path;
	char	*path;
	char	**split_path;
	int		here_doc;
	char	*limiter;
}	t_pipe;

void	init_struct(t_pipe *pipex, int argc, char **argv, char **envp);
int		ft_error(t_pipe *pipex);
int		ft_print_error(char	*str);
void	ft_end(t_pipe *pipex, int code);

#endif