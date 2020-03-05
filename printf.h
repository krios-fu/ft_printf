/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krios-fu <krios-fu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 13:06:28 by krios-fu          #+#    #+#             */
/*   Updated: 2020/02/29 19:11:43 by krios-fu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __PRINTF_H
# define __PRINTF_H

# include <unistd.h>
# include <stddef.h>
# include <stdlib.h>
# include <stdarg.h>

typedef struct	s_printf
{
	char		tab;
	char		zero_space;
	char		type;
	char		dot;
	char		*str;
	int			precision;
	int			width;
	int			len_str;
	va_list		ap;
}				t_printf;

void			ft_addresspunter(char *str);
int				ft_atoi(const char *str);
int				ft_hexalen(size_t nb);
void			ft_hexatolower(size_t nb);
void			ft_hexatoupper(unsigned int nb);
size_t			ft_intlen(long nb);
int				ft_isalpha(int c);
int				ft_isdigit(int c);
void			*ft_memcpy(void *dst, const void *src, size_t n);
void			ft_print_char(t_printf *p, char c);
void			ft_print_di(t_printf *p, int nb);
void			ft_print_str(t_printf *p, char *str);
void			ft_print_u(t_printf *p, int nb);
void			ft_print_x(t_printf *p, ssize_t x);
void			ft_print_xup(t_printf *p, ssize_t x);
void			ft_putchar_fd(char c, int fd);
void			ft_putnbr_fd(int n, int fd);
void			ft_putstr_fd(char *s, int fd);
void			ft_putunbr_fd(int n, int fd);
char			*ft_strdup(const char *s1);
size_t			ft_strlen(const char *str);
int				ft_printf(const char *str, ...);
int				ft_punlen(char *str);
void			ft_print_p(t_printf *p, char *str);

#endif
