/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_space_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phiolive <phiolive@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 16:07:26 by phiolive          #+#    #+#             */
/*   Updated: 2022/02/11 17:05:20 by phiolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/pipex.h"

int	ft_count_words_spc(char *s)
{
	int	i;
	int	words;

	words = 0;
	i = -1;
	while (s[++i])
	{
		if (s[i] == '\'')
		{
			i++;
			while (s[i] && s[i] != '\'' )
				i++;
			words++;
			if (!s[i])
				break ;
		}
		else if (s[i] != ' ' && (s[i + 1] == ' '
				|| s[i + 1] == '\'' || !s[i + 1]))
			words++;
	}
	return (words);
}

int	ft_alloc_for_no_quote(int *k, char **rtn, char *s)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != ' ' && s[i] != '\'')
		i++;
	if (i)
		rtn[k[0]] = (char *) ft_calloc (i + 1, sizeof(char), "ft_alloc", 0);
	if (!s[i])
		return (-1);
	if (i)
		k[0]++;
	return (i);
}

int	ft_alloc_for_quote(int *k, char **rtn, char *s)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != '\'' )
		i++;
	if (!s[i])
	{
		rtn[k[0]] = (char *) ft_calloc (i + 1, sizeof(char), "ft_alloc", 0);
		return (i);
	}
	else
	{
		rtn[k[0]] = (char *) ft_calloc (i + 1, sizeof(char), "ft_alloc", 0);
		k[0]++;
		return (i + 1);
	}
}
