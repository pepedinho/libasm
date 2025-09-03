NAME = libasm.a

SRCS = ft_strlen.s\
			 ft_strcpy.s\
			 ft_strcmp.s\
			 ft_write.s\
			 ft_read.s\

# Concaténation des fichiers source de base et supplémentaires
ALL_SRCS = $(SRCS) $(BONUS_SRCS)

OBJS = $(SRCS:.s=.o)

ALL_OBJS = $(ALL_SRCS:.s=.o)

NASM = nasm
NFLAGS = -f elf64
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g3

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

bonus: $(BONUS_SRCS:.s=.o) $(OBJS)
	ar rcs $(NAME) $(ALL_OBJS)

%.o: %.s 
	@echo $(NASM)
	$(NASM) $(NFLAGS) $< -o $@

clean:
	rm -f $(OBJS) $(ALL_OBJS)

clean_bonus:
	rm -f $(BONUS_OBJS)

fclean: clean
	rm -f $(NAME)
	rm -f test

re: fclean all

tests: all
	gcc -Wall -Wextra -g tests/test.c -L. -lasm -o test -g3
	./test

.PHONY: all bonus clean fclean re tests
