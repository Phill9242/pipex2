/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_space.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phiolive <phiolive@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 15:33:34 by phiolive          #+#    #+#             */
/*   Updated: 2022/02/11 17:36:17 by phiolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/pipex.h"

static	int	ft_cpy_for_no_quote(char *rtn, char *s, int *k)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != ' ' && s[i] != '\'')
	{
		rtn[i] = s[i];
		i++;
	}
	if (!s[i])
		return (-1);
	if (i)
		k[0]++;
	return (i);
}

static	int	ft_cpy_for_quote(char *rtn, char *s, int *k)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != '\'' )
	{
		rtn[i] = s[i];
		i++;
	}
	rtn[i] = 0;
	if (!s[i])
		return (-1);
	else
	{
		k[0]++;
		return (i + 1);
	}
}

static	void	ft_divide_str(char **rtn, char *s)
{
	int	i;
	int	k[1];
	int	rtn_i;

	k[0] = 0;
	i = -1;
	rtn_i = 0;
	while (s[++i])
	{
		if (s[i] == '\'')
		{
			rtn_i = ft_cpy_for_quote(rtn[k[0]], &s[i + 1], k);
			i += rtn_i;
		}
		else
		{
			rtn_i = ft_cpy_for_no_quote(rtn[k[0]], &s[i], k);
			i += rtn_i;
		}
		if (rtn_i == -1)
			break ;
		rtn_i = 0;
	}
}

static	void	ft_alloc_str(char **rtn, char *s)
{
	int	i;
	int	k[1];
	int	rtn_i;

	k[0] = 0;
	i = -1;
	rtn_i = 0;
	while (s[++i])
	{
		if (s[i] == ' ')
			i = i;
		else if (s[i] == '\'')
		{
			rtn_i = ft_alloc_for_quote(k, rtn, &s[i + 1]);
			i += rtn_i;
		}
		else
		{
			rtn_i = ft_alloc_for_no_quote(k, rtn, &s[i]);
			if (rtn_i == -1)
				break ;
			i += rtn_i;
		}
	}
}

char	**ft_split_space(char *s)
{
	char	**rtn;
	int		words;

	words = ft_count_words_spc (s);
	rtn = (char **) ft_calloc (words + 1, 8, "ft_split_space", 0);
	ft_alloc_str (rtn, s);
	ft_divide_str(rtn, s);
	return (rtn);
}
