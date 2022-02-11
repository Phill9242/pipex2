/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phiolive <phiolive@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 15:48:07 by phiolive          #+#    #+#             */
/*   Updated: 2022/02/11 17:26:13 by phiolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

// INCLUDES ---------------------------------------------

# include <stdio.h>
# include <errno.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <fcntl.h>

// STRUCTS------------------------------------------------

typedef struct s_pipex{
	char	***cmd_full;
	char	**env_path;
	char	**cmd_path;
	char	**cmd_name;
	int		*pipes;
	int		fdin;
	int		fdout;
	int		argc;
	int		n_cmd;
}	t_pipex;

//######################################################
// ---------FUNCTIONS -----------------#################
//######################################################

// FT_CHECK_ARGC-----------------------------------------------------
void	ft_check_argc(int argc, t_pipex *pipex);

//FT_CHECK_COMMANDS--------------------------------------------------
void	ft_check_commands(char **argv, t_pipex *pipex, char **envp);
void	ft_path_commands_check(t_pipex *pipex, char **envp);

// FT_CHECK_FDS -----------------------------------------------------
void	ft_check_fds(int argc, char **argv, t_pipex *pipex);

// FT_CLOSE----------------------------------------------------------
void	ft_close(t_pipex *pipex, int code, char *str);
void	ft_close_fd(char *argv, int ext);
void	ft_close_process(t_pipex *pipex, int ext, char *err);

// FT_CREATE_PIPES --------------------------------------------------
void	ft_open_pipes(t_pipex *pipex);

// FT_FREE ----------------------------------------------------------
void	ft_free_pipex(t_pipex *pipex);

// FT_PARSE_COMMANDS ------------------------------------------------
void	ft_parse_comands(t_pipex *pipex, char **argv);

// FT_PROCESS
int		ft_start_process(t_pipex *pipex, char **envp);

// PIPEX ------------
void	ft_initialize_struct(t_pipex *pipex);

// FT_CHECK_COMMAND_UTILS--------------------------------------------
void	ft_check_access(t_pipex *pipex);
void	ft_send_argv_to_struct_path(char **argv, t_pipex *pipex);
void	ft_split_envp(t_pipex *pipex, char **envp);

// FT_SPLIT_SPACE_UTILS----------------------------------------------
int		ft_count_words_spc(char *s);
int		ft_alloc_for_quote(int *k, char **rtn, char *s);
int		ft_alloc_for_no_quote(int *k, char **rtn, char *s);

// FT_SPLIT_SPACE----------------------------------------------------
char	**ft_split_space(char *s);

// LIBFT-------------------------------------------------------------
void	*ft_memset(void *dest, int c, size_t len);
size_t	ft_strlen(char *s);
void	*ft_calloc(size_t number, size_t size, char *name, t_pipex *pipex);
char	*ft_strjoin(char *s1, char *s2);
void	ft_bzero(void *s, size_t n);

// SPLIT ------------------------------------------------------------
char	**ft_split(char const *s, char delimiter);

#endif
