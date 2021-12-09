NAME = libftprintf.a

SRCS =	ft_parse.c	\
		ft_printf.c	\
		ft_utils.c	\
		ft_utils2.c	\
		ft_utils3.c	\
		ft_print.c

INCLS = ft_printf.h

FLAGS = -Wall -Wextra -Werror

PATH_SRCS = ./

PATH_INCLS = ./

OBJ = $(patsubst %.c, %.o, $(SRCS))

RM = rm -f

all: $(NAME)

$(NAME): $(OBJ)
		ar rcs $(NAME) $?

%.o: %.c $(INCLS)
		$(CC) $(FLAGS) -I $(PATH_INCLS) -c $<

bonus: all
	
clean:
		$(RM) $(OBJ)

fclean: clean
		$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus