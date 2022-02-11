/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phiolive <phiolive@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 15:32:20 by phiolive          #+#    #+#             */
/*   Updated: 2022/02/11 15:32:21 by phiolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/pipex.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char	*rtn;
	int		i;
	int		j;
	size_t	len_s1;
	size_t	len_s2;

	i = -1;
	j = -1;
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	rtn = ft_calloc(len_s1 + len_s2 + 1, sizeof (char), "ft_strjoin", 0);
	if (!rtn)
		return (NULL);
	while (s1[++i])
		rtn[i] = s1[i];
	while (s2[++j])
		rtn[i + j] = s2[j];
	rtn[i + j] = 0;
	return (rtn);
}

size_t	ft_strlen(char *s)
{
	size_t	x;

	x = 0;
	while (s[x])
		x++;
	return (x);
}

void	*ft_calloc(size_t number, size_t size, char *name, t_pipex *pipex)
{
	void	*rtn;

	rtn = malloc((number * size));
	if (!rtn)
	{
		rtn = ft_strjoin ("Error when allocating memory ", name);
		write (2, rtn, ft_strlen (rtn));
		write (2, "\n", 1);
		free (rtn);
		if (pipex)
			ft_free_pipex(pipex);
		exit (9);
	}
	ft_bzero (rtn, number * size);
	return (rtn);
}

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}

void	*ft_memset(void *dest, int c, size_t len)
{
	unsigned char	*anchor;

	anchor = (unsigned char *)dest;
	while (len--)
		*anchor++ = (unsigned char) c;
	return (dest);
}
