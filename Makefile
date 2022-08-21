NAME = ft_printf.a
FILES = ft_printf.c ft_printf_utils.c
LIBFT_DICT = libft
LIBFT = libft.a
CC = cc	
CFLAGS = -Wall -Wextra -Werror
OBJS = $(FILES:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) # Make .o files and make .a file
	ar rcs $(NAME) $(OBJS)

clean: # Removes all .o files
	rm -f $(OBJS)

fclean:	clean # Removes the .a file
	rm -f $(NAME)

re:	fclean all # Removes .a file and redo
