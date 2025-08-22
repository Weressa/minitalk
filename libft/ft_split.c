/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: assabich <assabich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 17:47:15 by assabich          #+#    #+#             */
/*   Updated: 2025/04/11 15:30:59 by assabich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	count(char const *s, char c)
{
	int	i;
	int	n;

	i = 0;
	n = 0;
	while (s[i])
	{
		if (s[i] != c && (i == 0 || s[i - 1] == c))
			n++;
		i++;
	}
	return (n);
}

char	*substr(char const *s, int start, int end)
{
	int		len;
	int		i;
	char	*sub;

	len = end - start +1;
	i = 0;
	sub = (char *)malloc((len + 1) * sizeof(char));
	if (sub == NULL)
		return (NULL);
	while (i < len)
	{
		sub[i] = s[start + i];
		i++;
	}
	sub[len] = '\0';
	return (sub);
}

static char	**free_split(char **sp, int j)
{
	while (j > 0)
		free(sp[--j]);
	free(sp);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		j;
	int		start;
	char	**sp;

	i = 0;
	j = 0;
	start = 0;
	sp = (char **)malloc((count(s, c) + 1) * sizeof(char *));
	if (!sp)
		return (NULL);
	while (s[i] != '\0')
	{
		if (s[i] != c && (i == 0 || s[i - 1] == c))
			start = i;
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
		{
			sp[j++] = substr(s, start, i);
			if (!sp[j - 1])
				return (free_split(sp, j), NULL);
		}
		i++;
	}
	return (sp[j] = NULL, sp);
}
