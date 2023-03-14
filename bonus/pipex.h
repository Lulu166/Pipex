/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <lucas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 14:24:16 by luhumber          #+#    #+#             */
/*   Updated: 2023/03/13 22:56:28 by lucas            ###   ########.fr       */
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
	char	**cmd;
	char	**last_cmd;
	char	**split_path;
	char	**good_path;
}	t_pipe;



#endif