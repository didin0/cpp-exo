######################################
# COLOR
######################################

#----TEXT-----

RED = \033[031m
DEF = \033[0m
GREEN = \033[032m
YELLOW = \033[33m
BLUE = \033[034m
PURPLE = \033[035m

######################################
#		VARIABLES
######################################

NAME = claptrap
SRCS = $(wildcard *.cpp)
HEADERS = $(wildcard *.hpp)
OBJS = $(SRCS:.cpp=.o)
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 #-fno-elide-constructors
RM = rm -f

######################################
#		RULES
######################################

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)
	@printf "${GREEN}Executable ${NAME} created successfully!${DEF}\n"

%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)
	@printf "${YELLOW}Object files cleaned!${DEF}\n"

fclean: clean
	$(RM) $(NAME)
	@printf "${RED}Executable and object files removed!${DEF}\n"

re: fclean all

.PHONY: all clean fclean re
