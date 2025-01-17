OBJ = \
		Fixed.o \
		main.o \

all: fixed

fixed: $(OBJ)
	c++ $^ -o $@

%.o: %.cpp
	c++ -std=c++98 -Wall -Werror -Wextra -c $^ -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f fixed

re: fclean all

.PHONY: clean fclean re