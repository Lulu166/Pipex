/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luhumber <luhumber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 14:24:16 by luhumber          #+#    #+#             */
/*   Updated: 2023/03/20 13:40:07 by luhumber         ###   ########.fr       */
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
	int		*pid;
	int		i;
	int		input_fd;
	int		file_out;
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