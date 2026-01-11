/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftcheck.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smeza-ro <smeza-ro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 18:51:49 by smeza-ro          #+#    #+#             */
/*   Updated: 2026/01/11 21:33:17 by smeza-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int print_char(char c)
{
	write (1, &c, 1);
	return (1);
}

int print_str(char *s)
{
	int	len;

	len = 0;
	while (s[len])
	{
		write(1, &s[len], 1);
		len++;
	}
	return (len);
}

int	print_hex(unsigned int i)
{
	char	*hex;
	int		len;

	hex = "0123456789abcdef";
	len = 0;
	if (i > 15)
		len += print_hex(i / 16);
	len += print_char(hex[i % 16]);
	return (len);
}

int main()
{
	printf("%d\n", print_hex(256));
}