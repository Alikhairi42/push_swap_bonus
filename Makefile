NAME = push_swap
BONUS_NAME = checker

SRCF = check_input_utilise.c ft_split.c input_check.c push_swap.c \
       small_sort.c sort_bucket.c sort_utlise.c stack_push.c \
       stack_r.c stack_rr.c stack_ss.c
OBJF = ${SRCF:.c=.o}

SRCF_BN = checker_utilise.c get_next_line_bonus_utilise.c \
		get_next_line_bonus.c checker.c check_input_utilise.c \
		ft_split.c input_check.c small_sort.c sort_bucket.c sort_utlise.c \
		stack_push.c stack_r.c stack_rr.c stack_ss.c
OBJF_BN = ${SRCF_BN:.c=.o}

CC = cc
CFLAGS = -Wall -Wextra -Werror

all: ${NAME}

${NAME}: ${OBJF}
	${CC} ${CFLAGS} ${OBJF} -o ${NAME}

%.o: %.c
	${CC} ${CFLAGS} -c $< -o $@ -MMD

bonus: ${OBJF_BN}
	${CC} ${CFLAGS} ${OBJF_BN} -o ${BONUS_NAME}

clean:
	rm -f $(OBJF) ${OBJF:.o=.d} ${OBJF_BN} ${OBJF_BN:.o=.d}

fclean: clean
	rm -f $(NAME) ${BONUS_NAME}

re: fclean all

.PHONY: clean

-include ${OBJF:.o=.d} ${OBJF_BN:.o=.d}
