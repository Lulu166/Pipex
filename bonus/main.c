/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luhumber <luhumber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 22:50:30 by lucas             #+#    #+#             */
/*   Updated: 2023/03/14 09:47:10 by luhumber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_init_struct(t_pipe *pipex)
{
	
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
	ft_init_struct(&pipex);
}
