NAME = megaphone

C++ = c++
C++FLAGS = -Wall -Wextra -Werror

SRCS = megaphone.cpp
OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(C++) $(C++FLAGS) $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS) $(NAME)

fclean: clean
	rm -f $(OBJS) $(NAME)

re: fclean all