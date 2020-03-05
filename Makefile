SRCS		= ft_addresspunter.c ft_hexatolower.c ft_hexatolower.c ft_hexatolower.c ft_hexatoupper.c ft_intlen.c ft_isdigit.c ft_memcpy.c ft_print_d_i.c \
				ft_print_str.c ft_print_u.c ft_putchar_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_strdup.c ft_strlen.c ft_atoi.c  ft_print_char.c ft_isalpha.c \
				ft_putunbr_fd.c ft_printf.c ft_hexalen.c ft_print_x.c ft_printf_xup.c ft_print_p.c ft_punlen.c

OBJS		= ${SRCS:.c=.o}

NAME		= libftprintf.a

CC			= cc

RM			= rm -f

FLAGS		= -Wall -Werror -Wextra

.c.o:
			${CC} ${FLAGS} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
			@ar rc  ${NAME} ${OBJS}
			@ranlib ${NAME}


all:		${NAME}

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all