/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_argc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phiolive <phiolive@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 15:32:37 by phiolive          #+#    #+#             */
/*   Updated: 2022/02/11 16:49:28 by phiolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/pipex.h"

void	ft_check_argc(int argc, t_pipex *pipex)
{
	if (argc != 5)
	{
		write (2, "invalid number of arguments\n", 29 );
		exit (3);
	}
	pipex->argc = argc;
	pipex->n_cmd = (argc - 3);
}
