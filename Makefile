NAME = push_swap

BONUSNAME = checker

SRCS = push_swap.c operations.c sorting.c moving.c calculations.c optimisation.c special_cases.c

BONUSSRCS = checker.c checking.c processing.c moves.c

OBJS := ${SRCS:.c=.o}

BONUSOBJS := ${BONUSSRCS:.c=.o}

HEADER = push_swap.h

FLAGS = -Wall -Wextra -Werror

all:	$(NAME)

$(NAME):	$(OBJS)
	cc $(FLAGS) -o $(NAME) $(OBJS)

$(OBJS):	$(SRCS)
	cc -c $(FLAGS) $(SRCS)

bonus: $(BONUSNAME)

$(BONUSNAME):	$(BONUSOBJS)
	cc $(FLAGS) -o $(BONUSNAME) $(BONUSOBJS)

$(BONUSOBJS):	$(BONUSSRCS)
	cc -c $(FLAGS) $(BONUSSRCS)

clean:
	rm -f $(OBJS) $(BONUSOBJS)

fclean:	clean
	rm -f $(NAME) $(BONUSNAME)

re:	fclean all