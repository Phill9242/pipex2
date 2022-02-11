/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_comands.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phiolive <phiolive@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 15:33:12 by phiolive          #+#    #+#             */
/*   Updated: 2022/02/11 17:20:23 by phiolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/pipex.h"

void	ft_parse_comands(t_pipex *pipex, char **argv)
{
	int	i;

	i = 0;
	pipex->cmd_full = ft_calloc(pipex->n_cmd + 1, 8, "ft_parse_comands", 0);
	pipex->cmd_full[pipex->n_cmd] = NULL;
	while (argv[i + 2] && i < pipex->n_cmd)
	{
		pipex->cmd_full[i] = ft_split_space(argv[i + 2]);
		i++;
	}
}
