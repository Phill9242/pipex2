/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_fds.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phiolive <phiolive@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 15:32:51 by phiolive          #+#    #+#             */
/*   Updated: 2022/02/11 16:01:11 by phiolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/pipex.h"

static	int	ft_check_in(char **argv, int *t)
{
	if (access(argv[1], F_OK))
	{
		ft_close_fd (argv[1], 4);
		t[0]++;
	}
	else if (access(argv[1], R_OK))
	{
		ft_close_fd (argv[1], 5);
		t[0]++;
	}
	return (t[0]);
}

static	void	ft_check_fd_return(t_pipex *pipex)
{
	if (pipex->fdin == -1)
	{
		write (2, "Fail to create the pipe to the input file\n", 56);
		exit (7);
	}
	if (pipex->fdout == -1)
	{
		write (2, "Fail to create the pipe to the output file\n", 57);
		exit (8);
	}
}

void	ft_check_fds(int argc, char **argv, t_pipex *pipex)
{
	int	t[0];

	t[0] = 0;
	t[0] = ft_check_in (argv, t);
	if (!(access(argv[argc - 1], F_OK)))
	{
		if (access(argv[argc - 1], W_OK))
			ft_close_fd (argv[argc - 1], 6);
		else
			pipex->fdout = open (argv[argc - 1], O_WRONLY | O_TRUNC);
	}
	if (t[0] > 0)
		pipex->fdin = 0;
	else
		pipex->fdin = open (argv[1], O_RDONLY);
	pipex->fdout = open (argv[argc - 1], O_RDWR | O_CREAT | O_APPEND, 0644);
	ft_check_fd_return (pipex);
}
