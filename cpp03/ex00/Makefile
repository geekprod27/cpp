NAME = claptrap

CC	= c++
CFLAGS	= -Wall -Wextra -Werror -std=c++98

PROGRESS = 🔁
CHECK = ✅

all: $(NAME)

SRC_NAME =		main.cpp				\
				ClapTrap.cpp

OBJ = $(SRC_NAME:.cpp=.o)
DEPS = $(SRC_NAME:.cpp=.d)

-include : $(DEPS)


$(NAME): $(OBJ)
	@printf "\e[2K\r- Build \033[1;33m${NAME}\033[0m [${PROGRESS}]"
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME) 
	@printf "\e[2K\r- Build \033[1;32m${NAME}\033[0m [${CHECK}]\n"

%.o: %.cpp
	@printf "\e[2K\r- \033[1;34m$<\033[0m [${PROGRESS}]"
	@$(CC) $(CFLAGS) -MMD -o $@ -c $<
	@printf "\e[2K\r- \033[1;32m$<\033[0m [${CHECK}]\n"

clean:
	@printf "\e[2K\r- \033[36mClean des objs\033[0m [${PROGRESS}]"
	@rm -rf $(OBJ) $(DEPS)
	@printf "\e[2K\r- \033[31mClean des objs\033[0m [${CHECK}]\n"

fclean:	clean
	@printf "\e[2K\r- \033[36mClean de lexecutable\033[0m [${PROGRESS}]"
	@rm -f $(NAME)
	@printf "\e[2K\r- \033[31mClean de lexecutable\033[0m [${CHECK}]\n"

re:	fclean
	@make all