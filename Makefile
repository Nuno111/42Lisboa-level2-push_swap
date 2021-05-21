NAME = push_swap

CC = gcc

ERR_FLAGS = -Wall -Wextra -Werror

DEBUG_FLAGS = -g -fsanitize=address

DEP_FLAGS = -I. -I/libft

LIBFT = libft/libft.a

SRC = $(wildcard ./*.c)

all : libft push_swap

libft :
	cd libft && {MAKE}

push_swap : $(NAME)

$(NAME) : *.c push_swap.h 
	$(CC) $(ERR_FLAGS) $(DEBUG_FLAGS) *.c $(LIBFT) $(DEP_FLAGS) -o $(NAME)

clean :
	rm -f $(DST0) $(DST1) $(DST2)

fclean : clean
	rm -rf $(NAME) $(CUB3DLIB) $(MACNAME) *.dSYM
	cd libs/libft && make fclean
	cd libs/macopengl && make clean

re : fclean all

.PHONY : all clean fclean re
