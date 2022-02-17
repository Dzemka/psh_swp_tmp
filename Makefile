NAME = push_swap.a

SRC_DIR = ./src

CMD_DIR = ./src/commands

SRC_MAIN = $(SRC_DIR)/push_swap.c $(SRC_DIR)/algorithms.c $(SRC_DIR)/fill_stack.c \
 			$(SRC_DIR)/ft_push_b.c $(SRC_DIR)/ft_push_a.c $(SRC_DIR)/ft_push_a_utils.c

SRC_COMMANDS = $(CMD_DIR)/swap.c $(CMD_DIR)/push.c $(CMD_DIR)/rotate.c $(CMD_DIR)/reverse_rotate.c

SRC = $(SRC_MAIN) $(SRC_COMMANDS)

OBJ = $(SRC:%.c=%.o)

CC = gcc

RM = rm -rf

HEADER = push_swap.h

CFLAGS = -Wall -Werror -Wextra

LIB = libft.a

LIB_DIR = ./libft

PROGRAM = push_swap

.PHONY : all clean fclean re

all : $(LIB) $(NAME) $(PROGRAM)

$(PROGRAM)	:	$(LIB_DIR)/$(LIB) $(NAME)
				$(CC) -o $(PROGRAM) $(SRC_DIR)/push_swap.c $(NAME)

$(NAME) : $(OBJ) $(HEADER) $(LIB_DIR)/$(LIB)
			ar rcs $(NAME) $? $(LIB_DIR)/*.o

$(LIB) :
		cd $(LIB_DIR) && $(MAKE) all

%.o : %.c
		$(CC) $(CFLAGS) -c $< -o $@

clean :
		$(RM) $(OBJ)
		cd $(LIB_DIR) && $(MAKE) clean

fclean : clean
		$(RM) $(NAME) $(PROGRAM)
		cd $(LIB_DIR) && $(MAKE) fclean

re     : fclean all