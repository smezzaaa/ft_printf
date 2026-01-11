/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftcheck.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smeza-ro <smeza-ro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 18:51:49 by smeza-ro          #+#    #+#             */
/*   Updated: 2026/01/11 19:57:37 by smeza-ro         ###   ########.fr       */
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
	int		mod;
	int		i;
	char	*hex;

	hex = "0123456789abcdef";
	mod = 0;
	i = 0;
	while (mod)
	{
		
	}
}

int main()
{
	printf("%x\n", 256);
}