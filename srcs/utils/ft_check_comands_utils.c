/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_comands_utils.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phiolive <phiolive@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 15:23:41 by phiolive          #+#    #+#             */
/*   Updated: 2022/02/11 15:27:52 by phiolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/pipex.h"

static void	ft_check_access_loop(t_pipex *pipex, int k)
{
	int	i;

	i = -1;
	if (!(access (pipex->cmd_name[k], F_OK)))
	{
		pipex->cmd_path[k] = ft_strjoin("", pipex->cmd_name[k]);
		return ;
	}
	while (pipex->env_path[++i])
	{
		pipex->cmd_path[k] = ft_strjoin(pipex->env_path[i], pipex->cmd_name[k]);
		if (!(access (pipex->cmd_path[k], F_OK)))
			return ;
		free (pipex->cmd_path[k]);
		pipex->cmd_path[k] = NULL;
	}
	pipex->cmd_path[k] = ft_strjoin(pipex->env_path[i - 1], pipex->cmd_name[k]);
}

void	ft_check_access(t_pipex *pipex)
{
	int	k;

	k = -1;
	pipex->cmd_path = ft_calloc (pipex->argc - 2, 8, "ft_check_access", 0);
	while (pipex->cmd_name[++k])
		ft_check_access_loop(pipex, k);
}

static char	*ft_take_cmd_name(char *argv)
{
	char	*rtn;
	int		i;
	int		j;
	int		alloc;

	alloc = 0;
	j = 0;
	i = 0;
	if (argv[i] == '\'')
		i++;
	while (argv[i] && argv[i] != ' ' && argv[i] != '\'')
	{
		i++;
		alloc++;
	}
	rtn = ft_calloc ((size_t) alloc + 1, sizeof(char), "ft_take_cmd_name", 0);
	i = 0;
	if (argv[i] == '\'')
		i++;
	while (argv[i] && argv[i] != ' ' && argv[i] != '\'')
	{
		rtn[j++] = argv[i];
		i++;
	}
	return (rtn);
}

void	ft_send_argv_to_struct_path(char **argv, t_pipex *pipex)
{
	int	i;
	int	j;

	i = 2;
	j = 0;
	pipex->cmd_name = ft_calloc (pipex->argc - 2, 8, "ft_send_argv", 0);
	while (i < pipex->argc - 1)
		pipex->cmd_name[j++] = ft_take_cmd_name(argv[i++]);
	return ;
}

void	ft_split_envp(t_pipex *pipex, char **envp)
{
	int		i;
	char	*path1;
	char	*step;

	i = -1;
	while (envp[++i])
	{
		if (envp[i][0] == 'P' && envp[i][1] == 'A' && envp[i][2] == 'T' &&
			envp[i][3] == 'H' && envp[i][4] == '=')
			pipex->env_path = ft_split(envp[i], ':');
	}
	path1 = ft_strjoin ("", &pipex->env_path[0][5]);
	free (pipex->env_path[0]);
	pipex->env_path[0] = path1;
	i = -1;
	while (pipex->env_path[++i])
	{
		step = ft_strjoin(pipex->env_path[i], "/");
		free (pipex->env_path[i]);
		pipex->env_path[i] = step;
	}
}
