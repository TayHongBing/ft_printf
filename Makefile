# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thong-bi <thong-bi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/09 15:01:58 by thong-bi          #+#    #+#              #
#    Updated: 2023/01/19 17:20:10 by thong-bi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	libftprintf.a

CC				=	gcc
CFLAGS			=	-Wall -Wextra -Werror
AR				=	ar
ARFLAGS 		=	rcs
RM				=	rm -rf

SRC				=	ft_printf ft_printhex ft_printptr ft_printunsigned ft_print_char ft_printnbr ft_printpercent ft_printstr
SRCS 			=	$(addsuffix .c, $(SRC))

OBJ_DIR			=	obj
OBJS			=	$(SRCS:%.c=$(OBJ_DIR)/%.o)

LIBFT_PATH		=	./libft
LIBFT			=	$(LIBFT_PATH)/libft.a

$(OBJ_DIR)/%.o:		%.c
					$(CC) $(CFLAGS) -c $< -o $@

all:				$(NAME)

$(NAME):			$(LIBFT) $(OBJ_DIR) $(OBJS)
				cp	$(LIBFT) $(NAME)
					$(AR) $(ARFLAGS) $(NAME) $(OBJS)

$(LIBFT):
					make -C $(LIBFT_PATH) all

$(OBJ_DIR):
					mkdir -p $(OBJ_DIR)

clean:
					make -C $(LIBFT_PATH) clean
					$(RM) $(OBJ_DIR)

fclean:				clean
					make -C $(LIBFT_PATH) fclean
					$(RM) $(NAME)

re:					fclean all

.PHONY:				all clean fclean re libft