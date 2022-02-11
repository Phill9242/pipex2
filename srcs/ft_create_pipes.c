/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_pipes.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phiolive <phiolive@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 15:32:03 by phiolive          #+#    #+#             */
/*   Updated: 2022/02/11 15:34:10 by phiolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/pipex.h"

void	ft_open_pipes(t_pipex *pipex)
{
	int	k;

	pipex->pipes = ft_calloc (pipex->n_cmd + 1, 4, "ft_open_pipes", NULL);
	k = pipe(pipex->pipes);
	if (k == -1)
	{
		write (2, "Error when trying to open the pipes\n", 37);
		exit (11);
	}
	return ;
}
