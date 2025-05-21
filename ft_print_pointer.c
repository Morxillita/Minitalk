/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngibelli <ngibelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 09:47:37 by ngibelli          #+#    #+#             */
/*   Updated: 2024/10/07 19:57:05 by ngibelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_print_hex_ptr(unsigned long long num)
{
	int	count;

	count = 0;
	if (num >= 16)
	{
		count += ft_print_hex_ptr(num / 16);
		count += ft_print_hex_ptr(num % 16);
	}
	else
	{
		if (num <= 9)
			count += ft_print_char(num + '0');
		else
			count += ft_print_char(num - 10 + 'a');
	}
	return (count);
}

int	ft_print_pointer(void *ptr)
{
	int	count;

	count = 0;
	if (ptr == NULL)
	{
		ft_print_string("(nil)");
		return (5);
	}
	count += ft_print_string("0x");
	if (ptr == 0)
		count += ft_print_char('0');
	else
		count += ft_print_hex_ptr((unsigned long)ptr);
	return (count);
}
