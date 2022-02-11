/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_comands.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phiolive <phiolive@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 15:32:44 by phiolive          #+#    #+#             */
/*   Updated: 2022/02/11 15:32:46 by phiolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/pipex.h"

void	ft_check_commands(char **argv, t_pipex *pipex, char **envp)
{
	ft_send_argv_to_struct_path(argv, pipex);
	ft_path_commands_check(pipex, envp);
}

void	ft_path_commands_check(t_pipex *pipex, char **envp)
{
	ft_split_envp(pipex, envp);
	ft_check_access (pipex);
}
