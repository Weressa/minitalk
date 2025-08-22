/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: assabich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 13:48:49 by assabich          #+#    #+#             */
/*   Updated: 2024/11/27 15:01:15 by assabich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size == 0)
	{
		while (src[i])
			i++;
		return (i);
	}
	while (i < size - 1 && src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	if (i < size)
		dest[i] = '\0';
	while (src[i] != '\0')
		i++;
	return (i);
}
/*
#include <stdio.h>
#include <bsd/string.h>

int	main(void)
{
	char chaine[] = "Texte", copie[100] = {0};
	char chaine2[] = "Texte", copie2[100] = {0};

	size_t	m = sizeof(copie);
	size_t	n = sizeof(copie2);

	m = 7;
	n = 7;
	printf("chaine vaut : %s\n", chaine);
	printf("taille vaut : %zu\n", ft_strlcpy(copie, chaine, m));
	printf("taille vaut : %zu\n", strlcpy(copie2, chaine2, n));
	printf("copie vaut : %s\n", copie2);
	return (0);
}*/
