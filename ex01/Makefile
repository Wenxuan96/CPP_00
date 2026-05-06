NAME = phonebook

C++ = c++
C++FLAGS = -Wall -Wextra -Werror

SRCS = main.cpp Contact.cpp Phonebook.cpp utils.cpp
OBJS = $(SRCS:%.cpp=%.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(C++) $(C++FLAGS) $(OBJS) -o $(NAME)


%.o: %.cpp
	$(C++) $(C++FLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all