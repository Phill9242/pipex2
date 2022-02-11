/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phiolive <phiolive@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 15:33:27 by phiolive          #+#    #+#             */
/*   Updated: 2022/02/11 15:34:55 by phiolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/pipex.h"

void	ft_initialize_struct(t_pipex *pipex)
{
	pipex->cmd_full = NULL;
	pipex->env_path = NULL;
	pipex->cmd_path = NULL;
	pipex->pipes = NULL;
	return ;
}

int	main(int argc, char **argv, char **envp)
{
	t_pipex	pipex;

	if (argc && argv && envp)
	{
		ft_check_argc(argc, &pipex);
		ft_initialize_struct (&pipex);
		ft_check_fds (argc, argv, &pipex);
		ft_check_commands(argv, &pipex, envp);
		ft_parse_comands(&pipex, argv);
		ft_open_pipes(&pipex);
		ft_start_process(&pipex, envp);
	}
	ft_free_pipex(&pipex);
	return (0);
}
