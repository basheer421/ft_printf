NAME = ft_printf.a
FILES = ft_printf.c
LIBFT_DICT = libft
LIBFT = libft.a
CC = cc	
CFLAGS = -Wall -Wextra -Werror
OBJS = $(FILES:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) # Make .o files and make .a file
	cd $(LIBFT_DICT) && make $(LIBFT) && cd ..
	ar rcs $(NAME) $(OBJS) $(LIBFT_DICT)/$(LIBFT)

clean: # Removes all .o files
	cd $(LIBFT_DICT) && make clean && cd ..
	rm -f $(OBJS)

fclean:	clean # Removes the .a file
	rm -f $(NAME) $(LIBFT_DICT)/$(LIBFT)

re:	fclean all # Removes .a file and redo
