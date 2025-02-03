OBJ = \
		Fixed.o \
		Point.o \
		main.o \

all: bsp

bsp: $(OBJ)
	c++ $^ -o $@

%.o: %.cpp
	c++ -std=c++98 -Wall -Werror -Wextra -c $^ -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f bsp

re: fclean all

.PHONY: clean fclean re