NAME = PmergeMe

CC	= c++
CFLAGS	= -Wall -Wextra -Werror -std=c++98 -g

PROGRESS = 🔁
CHECK = ✅

all: $(NAME)

SRC_NAME =		main.cpp	PmergeMe.cpp

OBJ_NAME = $(SRC_NAME:.cpp=.o)
DEPS_NAME = $(SRC_NAME:.cpp=.d)

OBJ_PATH = obj/
OBJ = $(addprefix $(OBJ_PATH),$(OBJ_NAME))
DEPS = $(addprefix $(OBJ_PATH),$(DEPS_NAME))

-include : $(DEPS)

$(NAME): $(OBJ)
	@printf "\e[2K\r- Build \033[1;33m${NAME}\033[0m [${PROGRESS}]"
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME) 
	@printf "\e[2K\r- Build \033[1;32m${NAME}\033[0m [${CHECK}]\n"

$(OBJ_PATH)%.o: %.cpp
	@printf "\e[2K\r- \033[1;34m$<\033[0m [${PROGRESS}]"
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) -MMD -o $@ -c $<
	@printf "\e[2K\r- \033[1;32m$<\033[0m [${CHECK}]\n"

clean:
	@printf "\e[2K\r- \033[36mClean des objs\033[0m [${PROGRESS}]"
	@rm -rf $(OBJ) $(DEPS)
	@printf "\e[2K\r- \033[31mClean des objs\033[0m [${CHECK}]\n"

fclean:	clean
	@printf "\e[2K\r- \033[36mClean de lexecutable\033[0m [${PROGRESS}]"
	@rm -f $(NAME)
	@rmdir $(OBJ_PATH)
	@printf "\e[2K\r- \033[31mClean de lexecutable\033[0m [${CHECK}]\n"

re:	fclean
	@make all