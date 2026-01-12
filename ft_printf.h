/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smeza-ro <smeza-ro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 17:43:10 by smeza-ro          #+#    #+#             */
/*   Updated: 2026/01/12 14:43:31 by smeza-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <unistd.h>
# include <stdarg.h>

int	ft_printf(const char *s, ...);
int	put_char(char c);
int put_str(char *s);
int	put_nbr(int i);
int	put_hex(unsigned int i, char c);
int	put_ptr(void *p);

#endif