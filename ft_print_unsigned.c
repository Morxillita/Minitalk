/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngibelli <ngibelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 09:47:37 by ngibelli          #+#    #+#             */
/*   Updated: 2024/10/07 19:57:05 by ngibelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_print_unsigned_number(unsigned int n)
{
	int	count;

	count = 0;
	if (n >= 10)
		count += ft_print_unsigned_number(n / 10);
	count += ft_print_char(n % 10 + '0');
	return (count);
}

int	ft_print_unsigned(unsigned int n)
{
	return (ft_print_unsigned_number(n));
}
