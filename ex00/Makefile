PROGRAM = megaphone
COMPILER = g++
CPPFLAGS = -Wall -Wextra -Werror #-std=c++98
SRCS = megaphone.cpp
OBJS = $(SRCS:.cpp=.o)

all: $(PROGRAM)

$(PROGRAM): $(OBJS)
	$(COMPILER) $(CPPFLAGS) -o $@ $(OBJS)

%.o: %.cpp
	$(COMPILER) $(CPPFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(PROGRAM)

re: fclean all

.PHONY: all clean fclean re
