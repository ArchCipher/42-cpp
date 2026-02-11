NAME = megaphone

SRCS = megaphone.cpp
OBJS = $(SRCS:.cpp=.o)

CXX = c++
FLAGS = -Wall -Wextra -Werror -std=c++98
SFLAGS = -fsanitize=address
# add pedanitic?

%.o:%.cpp
	$(CXX) $(FLAGS) $(SFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(FLAGS) $(SFLAGS) $(OBJS) -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re