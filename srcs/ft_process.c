/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phiolive <phiolive@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 15:33:20 by phiolive          #+#    #+#             */
/*   Updated: 2022/02/11 15:42:40 by phiolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/pipex.h"

static	void	ft_initial_process(t_pipex *pipex, char **envp)
{
	char	*msg;

	if (!pipex->fdin)
	{
		ft_free_pipex (pipex);
		exit (1);
	}
	if (dup2 (pipex->fdin, 0) == -1)
		ft_close_process (pipex, 13, "Error duplicating the file descriptor");
	if (dup2 (pipex->pipes[1], 1) == -1)
		ft_close_process (pipex, 13, "Error duplicating the file descriptor");
	if (execve (pipex->cmd_path[0], pipex->cmd_full[0], envp) == -1)
	{
		msg = ft_strjoin (pipex->cmd_name[0], ": command not found\n");
		ft_close_process (pipex, 127, msg);
	}
}

static	void	ft_final_process_false_in(t_pipex *pipex, char **envp)
{
	char	*msg;

	if (dup2 (pipex->fdout, 1) == -1)
		ft_close_process (pipex, 13, "Fail to duplicate the file descriptor:");
	if (dup2 (pipex->pipes[0], 0) == -1)
		ft_close_process (pipex, 13, "Fail to duplicate the file descriptor:");
	if (execve (pipex->cmd_path[1], pipex->cmd_full[1], envp) == -1)
	{
		msg = ft_strjoin (pipex->cmd_name[1], ": command not found\n");
		ft_close_process (pipex, 127, msg);
	}
}

static	void	ft_final_process(t_pipex *pipex, char **envp)
{
	char	*msg;

	if (!pipex->fdin)
		ft_final_process_false_in(pipex, envp);
	if (dup2 (pipex->pipes[0], 0) == -1)
		ft_close_process (pipex, 13, "Fail to duplicate the file descriptor:");
	if (dup2 (pipex->fdout, 1) == -1)
		ft_close_process (pipex, 13, "Fail to duplicate the file descriptor:");
	close (pipex->fdout);
	if (pipex->fdin)
		close (pipex->fdin);
	if (execve (pipex->cmd_path[1], pipex->cmd_full[1], envp) == -1)
	{
		msg = ft_strjoin (pipex->cmd_name[1], ": command not found\n");
		ft_close_process (pipex, 127, msg);
	}
}

int	ft_start_process(t_pipex *pipex, char **envp)
{
	int	pid;
	int	wstatus;

	pid = 1;
	if (pipex->fdin)
		pid = fork ();
	if (pid == -1)
		ft_close_process (pipex, 12, "Error: cannot fork the process");
	if (!pid)
		ft_initial_process(pipex, envp);
	else
		waitpid(pid, &wstatus, WNOHANG);
	close (pipex->pipes[1]);
	ft_final_process (pipex, envp);
	return (0);
}
