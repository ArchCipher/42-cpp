NAME = phonebook

HEADER = -I.

SRC_FILES = main add_contact \
			Contact PhoneBook
OBJS = $(SRCS:.cpp=.o)

SRCS = $(addsuffix .cpp, $(SRC_FILES))

CXX = c++
FLAGS = -Wall -Wextra -Werror -pedantic -std=c++98
SFLAGS = -fsanitize=address

%.o:%.cpp $(HEADER)
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