/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smeza-ro <smeza-ro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 18:51:49 by smeza-ro          #+#    #+#             */
/*   Updated: 2026/01/13 12:43:10 by smeza-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	put_char(int c)
{
	write (1, &c, 1);
	return (1);
}

int	put_str(char *s)
{
	int	len;

	len = 0;
	if (!s)
		return (write(1, "(null)", 6));
	while (s[len])
	{
		write(1, &s[len], 1);
		len++;
	}
	return (len);
}

int	put_nbr(int i)
{
	int			len;
	long int	n;

	len = 0;
	n = (long int)i;
	if (n < 0)
	{
		len += put_char('-');
		n *= -1;
	}
	if (n >= 10)
		len += put_nbr(n / 10);
	len += put_char((n % 10) + '0');
	return (len);
}

int	put_hex(unsigned int i, char c)
{
	char	*hex;
	int		len;

	if (c == 'x')
		hex = "0123456789abcdef";
	else
		hex = "0123456789ABCDEF";
	len = 0;
	if (i > 15)
		len += put_hex(i / 16, c);
	len += put_char(hex[i % 16]);
	return (len);
}

int	put_ptr(void *p)
{
	unsigned long long	num;
	char				*hex;
	int					len;

	if (!p)
		return (write(1, "(nil)", 5));
	num = (unsigned long long)p;
	hex = "0123456789abcdef";
	len = 0;
	if (num > 15)
		len += put_ptr((void *)(num / 16));
	if (num < 16)
		len = write(1, "0x", 2);
	len += put_char(hex[num % 16]);
	return (len);
}
