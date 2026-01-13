/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smeza-ro <smeza-ro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 15:43:42 by smeza-ro          #+#    #+#             */
/*   Updated: 2026/01/13 12:20:35 by smeza-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	put_uns_int(unsigned int i)
{
	int	len;

	len = 0;
	if (i >= 10)
		len += put_nbr(i / 10);
	len += put_char((i % 10) + '0');
	return (len);
}

static int	ft_check(char c, va_list ap)
{
	int	len;

	len = 0;
	if (c == 'c')
		len = put_char(va_arg(ap, int));
	else if (c == 's')
		len = put_str(va_arg(ap, char *));
	else if (c == 'd' || c == 'i')
		len = put_nbr(va_arg(ap, int));
	else if (c == 'x' || c == 'X')
		len = put_hex(va_arg(ap, unsigned int), c);
	else if (c == 'p')
		len += put_ptr(va_arg(ap, void *));
	else if (c == 'u')
		len = put_uns_int(va_arg(ap, unsigned int));
	else if (c == '%')
		len = write(1, "%", 1);
	return (len);
}

int	ft_printf(const char *s, ...)
{
	va_list	ap;
	int		i;
	int		result;

	i = 0;
	result = 0;
	va_start(ap, s);
	while (s[i])
	{
		if (s[i] == '%' && s[i + 1])
		{
			result += ft_check(s[i + 1], ap);
			i++;
		}
		else
			result += write(1, &s[i], 1);
		i++;
	}
	va_end(ap);
	return (result);
}
/* 
int	main()
{
	printf("ciao %%");
} */