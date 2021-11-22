NAME = libftprintf.a

SRCS =	ft_printf.c

OBJS = $(SRCS:.c=.o)
CC = cc
CFLAGS = -Wall -Werror -Wextra
RM = rm -f
AR = ar -rcs

all: $(NAME)

$(NAME):$(OBJS) $(INC)
	$(AR) $(NAME) $(OBJS) 

%.o:%.c
	$(CC) $(CFLAGS) -o $@ -c $<

clean:
	$(RM) $(OBJS)

fclean:clean
	$(RM) $(NAME)

re: fclean all
