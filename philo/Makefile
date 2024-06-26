# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lpaixao- <lpaixao-@student.42.rio>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/20 14:45:35 by lpaixao-          #+#    #+#              #
#    Updated: 2024/05/22 16:19:54 by lpaixao-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

COLOUR_GREEN=\033[0;32m
COLOUR_RED=\033[0;31m
COLOUR_BLUE=\033[0;34m
COLOUR_YELLOW=\033[0;33m
COLOUR_GREY=\033[0;90m
COLOUR_END=\033[0m

NAME = philo

CC = cc

FLAGS = -Wall -Wextra -Werror -g -pthread

SRCS = \
main.c \
errors.c \
philo_utils.c \
structs.c \
philosophers.c \
actions.c \
philo_utils2.c \
philo_utils3.c \
mutexes.c

OBJS = ${SRCS:.c=.o}

PHILOS = 5

DIE = 800

EAT = 200

SLEEP = 200

#NUMBERS = $(PHILOS) $(DIE) $(EAT) $(SLEEP) 7

#NUMBERS					=	1 800 200 200   # The philosopher should not eat and should die
#NUMBERS					=	5 800 200 200   # No philosopher should die.
#NUMBERS					=	5 900 200 200 7 # No philosopher should die.
#NUMBERS					=	4 410 200 200   # No philosopher should die.
#NUMBERS					=	4 310 200 100 7 # One philosopher should die.

#NUMBERS					=	4 10 200 100	#One philosopher should die

#NUMBERS					=	5 410 200 100 7 # One philosopher should die.
#NUMBERS					=	5 120 80 80 	# Moana tolds all will die
#NUMBERS					=	2 200 50 50 1
#NUMBERS					=	50 1000 60 60 1
#NUMBERS					=	2 110 50 50 2

#NUMBERS					=	4 200 205 200	# One should die
#NUMBERS					=	4 410 200 200 10	# No one should die. Stop after 10
#NUMBERS					=	-5 600 200 200	# ERROR - CRASH
#NUMBERS					=	5 -5 200 200	# ERROR - CRASH
#NUMBERS					=	4 600 -5 200	# ERROR - CRASH
#NUMBERS					=	5 600 200 -5	# ERROR - CRASH
#NUMBERS					=	4 600 200 200 -5	# ERROR - CRASH
#NUMBERS					=	5 600 150 150	# No one should die
#NUMBERS					=	4 410 200 200	# No one should die
#NUMBERS					=	100 800 200 200	# No one should die
NUMBERS					=	105 800 200 200	# No one should die

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

all: $(NAME)
	@echo "$(COLOUR_BLUE) philo ready to be used$(COLOUR_END)"

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $(OBJS) -o $(NAME)

clean:
	rm -f main.o errors.o philo_utils.o structs.o philosophers	rm -f $(OBJS)
	@echo "Objects deleted"

fclean: clean
	rm -f $(NAME)
	@echo "All cleaned"

re: fclean all

run: re
	./$(NAME) $(NUMBERS)

val: re
	valgrind --leak-check=full --show-leak-kinds=all ./$(NAME) $(NUMBERS)

hell: re
	valgrind --tool=helgrind -s ./$(NAME) $(NUMBERS)
#  

count: re
	./$(NAME) $(NUMBERS) | grep "1 is eating" | wc -l

norm:
		@echo "$(COLOUR_BLUE)Passando a Norminette com a flag -R CheckForbiddenSourceHeader: $(COLOUR_END)"
	@-norminette -R CheckForbiddenSourceHeader

sanitize: fclean $(OBJS)
	$(CC) $(FLAGS) $(OBJS) -o $(NAME) -fsanitize=address
	./$(NAME) $(NUMBERS)
