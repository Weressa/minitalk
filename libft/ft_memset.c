/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: assabich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 17:28:29 by assabich          #+#    #+#             */
/*   Updated: 2024/11/15 10:45:18 by assabich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *ptr, int v, unsigned int size)
{
	char	*p;

	p = (char *)ptr;
	while (size > 0)
	{
		p[size - 1] = v;
		size--;
	}
	return (p);
}
/*
#include <stdio.h>
#include <string.h>

int main() {
    char str1[20], str2[20];

    // Initialize both strings with the same value
    strcpy(str1, "Hello, World!");
    strcpy(str2, "Hello, World!");

    // Apply memset to str1
    memset(str1, 'A', 5);  // Set first 5 characters to 'A'

    // Apply ft_memset to str2
    ft_memset(str2, 'A', 5);  // Set first 5 characters to 'A'

    // Print the results
    printf("After memset and ft_memset:\n");
    printf("str1: %s\n", str1);  // Should print AAAAA, World!
    printf("str2: %s\n", str2);  // Should print AAAAA, World!

    return 0;
}*/
