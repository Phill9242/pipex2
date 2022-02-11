/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phiolive <phiolive@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 15:29:57 by phiolive          #+#    #+#             */
/*   Updated: 2022/02/11 15:31:03 by phiolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/pipex.h"

static void	ft_free(void *pointer)
{
	free (pointer);
	pointer = NULL;
	return ;
}

static void	ft_free_double(void **pointer)
{
	int	i;

	i = -1;
	while (pointer[++i])
		ft_free(pointer[i]);
	free (pointer);
	pointer = NULL;
}

static void	ft_free_triple(void ***pointer)
{
	int	i;

	i = -1;
	while (pointer[++i])
		ft_free_double(pointer[i]);
	free (pointer);
	pointer = NULL;
}

void	ft_free_pipex(t_pipex *pipex)
{
	if (pipex->cmd_full)
		ft_free_triple ((void *) pipex->cmd_full);
	if (pipex->env_path)
		ft_free_double ((void *)pipex->env_path);
	if (pipex->cmd_path)
		ft_free_double ((void *)pipex->cmd_path);
	if (pipex->cmd_name)
		ft_free_double ((void *)pipex->cmd_name);
	if (pipex->pipes)
		ft_free ((void *)pipex->pipes);
	return ;
}
