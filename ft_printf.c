/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smeza-ro <smeza-ro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 15:43:42 by smeza-ro          #+#    #+#             */
/*   Updated: 2026/01/08 19:12:44 by smeza-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_check(char c, va_list ap)
{
	int	len;
	
	len = 0;
	if (c == 'c')
		len = print_char(va_arg(ap, int));
	if (c == 's')
		len = print_str(va_arg(ap, char *));
	if (c == 'd')
		len = print_int
}

int	ft_printf(const char *s, ...)
{
	va_list	ap;
	int		i;
	int		result;

	i = 0;
	result = 0;
	va_start(ap, s);
	
	while(s[i])
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

int	main()
{
	printf("ciao %d %s", 1234, "ciao");
}