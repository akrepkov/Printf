CFLAGS = -Wall -Werror -Wextra
NAME = libftprintf.a

SRCS = ft_printf.c ft_printf_func.c ft_printf_func2.c
	
OBJS = ft_printf.o ft_printf_func.o ft_printf_func2.o

all: $(NAME)

$(NAME): $(OBJS)
	@ar -rc $(NAME) $(OBJS)

%.o: %.c
	@echo $< "done"
	@$(CC) $(CFLAGS) -o $@ -c $<

clean:
	rm -f $(OBJS) 

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: fclean clean re all