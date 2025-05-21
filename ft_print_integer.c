/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_integer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngibelli <ngibelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 09:30:05 by ngibelli          #+#    #+#             */
/*   Updated: 2024/10/07 19:55:15 by ngibelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_print_number(long n)
{
	int	count;

	count = 0;
	if (n < 0)
	{
		count += ft_print_char('-');
		n = -n;
	}
	if (n >= 10)
		count += ft_print_number(n / 10);
	count += ft_print_char(n % 10 + '0');
	return (count);
}

int	ft_print_integer(int n)
{
	return (ft_print_number((long)n));
}

/*#include <stdio.h>

int	main(void)
{
    int a = 42;

    printf("Standard printf:\n");
    printf("Character: %c\n", 'A');
    printf("String: %s\n", "hola mundo");
    printf("Pointer: %p\n", &a);
    printf("Integer: %d\n", 42);
    printf("Unsigned: %u\n", 42);
    printf("Hex (lowercase): %x\n", 42);
    printf("Hex (uppercase): %X\n", 42);

    ft_printf("\nCustom ft_printf:\n");
    ft_printf("Character: %c\n", 'A');
    ft_printf("String: %s\n", "hola mundo");
    ft_printf("Pointer: %p\n", &a);
    ft_printf("Integer: %d\n", 42);
    ft_printf("Unsigned: %u\n", 42);
    ft_printf("Hex (lowercase): %x\n", 42);
    ft_printf("Hex (uppercase): %X\n", 42);

    return (0);
}
*/