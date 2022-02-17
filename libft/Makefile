# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: olugash <olugash@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/23 01:18:46 by olugash           #+#    #+#              #
#    Updated: 2021/11/07 06:40:40 by olugash          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

RM = rm -rf

GNL_DIR = ./get_next_line/

GNL_SRC = get_next_line.c get_next_line_utils.c

GNL = $(addprefix $(GNL_DIR), $(GNL_SRC))


SRC			= 	ft_bzero.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_memchr.c \
            		ft_memcmp.c ft_memset.c ft_strchr.c ft_strlcat.c ft_strlcpy.c ft_strlen.c \
            		ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_tolower.c ft_toupper.c ft_putchar_fd.c \
					ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_itoa.c ft_memcpy.c ft_atoi.c \
					ft_calloc.c ft_strdup.c ft_memmove.c ft_substr.c ft_split.c ft_strjoin.c ft_strtrim.c \
					ft_strmapi.c ft_striteri.c ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c \
					ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c ft_lstnew.c \
					ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c \
					 ft_lstiter.c ft_lstmap.c

OBJ_DIR = ./objective/

OBJ = $(addprefix $(OBJ_DIR), $(SRC:%.c=%.o))

OBJ_GNL = $(addprefix $(GNL_DIR), $(GNL_SRC:%.c=%.o))

CC = cc

HEADER = libft.h

CFLAGS = -Wall -Werror -Wextra

.PHONY : all clean fclean re bonus

all: $(OBJ_DIR) $(NAME)

$(OBJ_DIR) :
			mkdir -p $(OBJ_DIR)

$(NAME) : $(OBJ) $(OBJ_GNL)
	ar rcs $(NAME) $(OBJ) $(OBJ_GNL)

$(OBJ_DIR)%.o : %.c
			$(CC) $(CFLAGS) -c $< -o $@

$(GNL_DIR)%.o : %.c
			cd $(GNL_DIR) && $(CC) $(CFLAGS) -c $< -o $@

clean	:
	$(RM) $(OBJ_DIR)

fclean	:	clean
	$(RM) $(NAME)

re	:	fclean all


