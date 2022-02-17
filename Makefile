NAME = push_swap.a

SRC_DIR = ./src/

CMD_DIR = ./src/commands/

FUNCTIONS_MAIN = push_swap.c algorithms.c fill_stack.c ft_push_b.c ft_push_a.c ft_push_a_utils.c

FUNCTION_COMMAND = swap.c push.c rotate.c reverse_rotate.c

SRC_MAIN = $(addprefix $(SRC_DIR), $(FUNCTIONS_MAIN))

SRC_COMMANDS = $(addprefix $(CMD_DIR), $(FUNCTION_COMMAND))

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
			ar rcs $(NAME) $? $(LIB_DIR)/objective/*.o $(LIB_DIR)/get_next_line/*.o

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