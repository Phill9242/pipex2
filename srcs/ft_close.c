/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_close.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phiolive <phiolive@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 15:33:01 by phiolive          #+#    #+#             */
/*   Updated: 2022/02/11 15:49:43 by phiolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/pipex.h"

void	ft_close(t_pipex *pipex, int code, char *str)
{
	char	*msg;

	msg = ft_strjoin ("Error: ", str);
	perror (msg);
	free (msg);
	ft_free_pipex (pipex);
	exit (code);
}

void	ft_close_fd(char *argv, int ext)
{
	char	*msg;

	msg = ft_strjoin ("Bash: ", argv);
	perror (msg);
	free (msg);
	ext++;
}

void	ft_close_process(t_pipex *pipex, int ext, char *err)
{
	write(2, err, ft_strlen(err));
	ft_free_pipex (pipex);
	if (ext == 127)
		free(err);
	exit (ext);
}
