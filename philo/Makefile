# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lpaixao- <lpaixao-@student.42.rio>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/20 14:45:35 by lpaixao-          #+#    #+#              #
#    Updated: 2024/05/19 15:22:18 by lpaixao-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

COLOUR_GREEN=\033[0;32m
COLOUR_RED=\033[0;31m
COLOUR_BLUE=\033[0;34m
COLOUR_YELLOW=\033[0;33m
COLOUR_END=\033[0m

NAME = philo

CC = cc

FLAGS = -Wall -Wextra -Werror -g -pthread -o3

SRCS = \
main.c \
errors.c \
philo_utils.c \
structs.c \
philosophers.c \
actions.c \
philo_utils2.c

OBJS = ${SRCS:.c=.o}

PHILOS = 5

DIE = 800

EAT = 200

SLEEP = 200

NUMBERS = $(PHILOS) $(DIE) $(EAT) $(SLEEP)

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

all: $(NAME)
	@echo "$(COLOUR_BLUE) philo ready to be used$(COLOUR_END)"

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS)
	@echo "Objects deleted"

fclean: clean
	rm -f $(NAME)
	@echo "All cleaned"

re: fclean all

run: re
	./$(NAME) $(NUMBERS)

val: re
	valgrind --leak-check=full --show-leak-kinds=all ./$(NAME) $(NUMBERS)

norm:
		@echo "$(COLOUR_BLUE)Passando a Norminette com a flag -R CheckForbiddenSourceHeader: $(COLOUR_END)"
	@-norminette -R CheckForbiddenSourceHeader

sanitize: fclean $(OBJS)
	$(CC) $(FLAGS) $(OBJS) -o $(NAME)
	./$(NAME) $(NUMBERS)
