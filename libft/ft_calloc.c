/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: assabich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 18:24:32 by assabich          #+#    #+#             */
/*   Updated: 2024/11/27 16:09:49 by assabich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t n, size_t size)
{
	char	*arr;
	size_t	i;

	i = 0;
	if (n != 0 && (n * size) / n != size)
		return (NULL);
	arr = (char *)malloc(n * size);
	if (arr == NULL)
		return (NULL);
	while (i < (n * size))
	{
		arr[i] = 0;
		i++;
	}
	return (arr);
}
/*
#include <stdio.h>
int main() {
    int n = 5;  // Number of elements
    int *original_calloc_array;
    int *ft_calloc_array;

    // Allocate memory using original calloc
    original_calloc_array = (int *)calloc(n, sizeof(int));
    if (original_calloc_array == NULL) {
        printf("Original calloc memory allocation failed\n");
        return 1;
    }

    // Allocate memory using ft_calloc
    ft_calloc_array = (int *)ft_calloc(n, sizeof(int));
    if (ft_calloc_array == NULL) {
        printf("ft_calloc memory allocation failed\n");
        free(original_calloc_array);  // Free the original memory
        return 1;
    }

    // Print values from the original calloc
    printf("Original calloc array values:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", original_calloc_array[i]);
    }
    printf("\n");

    // Print values from the ft_calloc
    printf("ft_calloc array values:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", ft_calloc_array[i]);
    }
    printf("\n");

    // Free the allocated memory
    free(original_calloc_array);
    free(ft_calloc_array);

    return 0;
}*/
