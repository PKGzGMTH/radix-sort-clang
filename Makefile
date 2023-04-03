CFLAG = -Wall -Wextra -Werror
SRC = main.c
NAME = radix-sort

all: $(NAME)

$(NAME):
	@$(CC) $(CFLAG) -o $(NAME) $(SRC)

fclean:
	@rm -rf $(NAME)

re: fclean all

test: re
	@./$(NAME) 11 1 0 20 33 13

hardtest: re
	@./$(NAME) 93 83 20 56 22 47 94 62 25 58 53 73 46 36 55 70 11 69 29 63 10 75 51 74 6 12 85 26 92 65 37 44 61 96 32 30 4 39 81 41 21 87 99 5 16 0 42 66 24 54 50 90 78 13 57 15 40 17 1 23 52 48 18 28 97 2 49 72 7 91 43 68 3 84 80 31 14 60 59 89 79 35 77 98 8 34 38 19 76 86 9 88 82 100 33 95 27 64 45 71 67

.PHONY: all re fclean $(NAME)
