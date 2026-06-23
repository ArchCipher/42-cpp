NAME = PmergeMe

SRC_FILES = main PmergeMe
SRCS = $(addsuffix .cpp, $(SRC_FILES))
OBJS = $(SRCS:.cpp=.o)

DEPS = $(OBJS:.o=.d)

CXX = c++
FLAGS = -Wall -Wextra -Werror -pedantic -std=c++98
# SFLAGS = -fsanitize=address

%.o:%.cpp
	$(CXX) $(FLAGS) -g $(SFLAGS) -MMD -MP -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(FLAGS) $(SFLAGS) $(OBJS) -o $@

clean:
	rm -f $(OBJS) $(DEPS)

fclean: clean
	rm -f $(NAME)

re: fclean all

-include $(DEPS)

.PHONY: all clean fclean re tidy
