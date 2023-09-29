NAME		= philo

CC			= cc
CFLAGS		= -Wall -Werror -Wextra -MMD -MP -g

ifeq ($(MAKECMDGOALS), debug)
	CFLAGS += -fsanitize=address -fno-omit-frame-pointer
endif

SRC_PATH	= srcs
SRC			= main.c \
				print_error.c
SRCS		= $(addprefix $(SRC_PATH)/, $(SRC))

OBJ_PATH	= obj
OBJ 		= $(SRC:%.c=%.o)
OBJS		= $(addprefix $(OBJ_PATH)/, $(OBJ))

INC_PATH	= includes
INC			= philo.h
INCS		= $(addprefix $(INC_PATH)/, $(INC))

RM			= rm -f

CHECK		= \033[32m[✔]\033[0m
REMOVE		= \033[31m[✘]\033[0m
GENERATE	= \033[33m[➤]\033[0m
BLUE		= \033[1;34m
YELLOW		= \033[1;33m
RESET		= \033[0m

all : $(NAME)

$(NAME) : $(OBJS)
	@ echo ""
	@ $(CC) $(CFLAGS) -o $(NAME) $(OBJS)
	@ mkdir -p ./obj
	@ echo "$(CHECK) $(BLUE)Compiling Philosophers... $(RESET)"

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c $(INCS)
	@ mkdir -p $(@D)
	@ $(CC) $(CFLAGS) -o $@ -c $<
	@ printf "$(GENERATE) $(YELLOW)Generating $@... %-50.50s\r$(RESET)"

clean:
	@ $(RM) -r ./obj/
	@ printf "$(REMOVE) $(BLUE)Remove $(NAME) object files.$(RESET)\n"

fclean:
	@ $(RM) $(NAME)
	@ $(RM) -r ./obj/
	@ printf "$(REMOVE) $(BLUE)Remove $(NAME) object files and $(NAME).$(RESET)\n"

re: fclean all

run: all
	@ clear
	@ ./$(NAME)

debug: re run

.PHONY : all clean fclean re run debug