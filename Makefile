NAME = libftprintf.a
FLAGS = -Wall -Werror -Wextra
SRC := ft_c.c ft_d.c ft_f.c ft_init.c ft_init2.c ft_init3.c ft_o.c ft_p.c \
ft_printf.c ft_s.c ft_u.c ft_x.c
SRC_DIR = ./srcs
OBJECTS := $(SRC:.c=.o)
LIBRARIES = libftprintf.a ./libft/libft.a
SRC := $(addprefix $(SRC_DIR)/, $(SRC))
INC_DIR = ./includes/
LIB_DIR = ./libft/

(NAME):
	@make -C ./libft --no-print-directory
	@cp ./libft/libft.a $(NAME)
	@echo "creating ft_printf objects..."
	@gcc $(FLAGS) -c $(SRC) -I$(INC_DIR) -I$(LIB_DIR)
	@echo "\033[92mdone!\033[0m"
	@echo "creating libftprintf.a library..."
	@ar -rc $(NAME) $(OBJECTS)
	@echo "\033[92mdone!\033[0m"
all: $(NAME)
test: $(NAME)
	rm -f ./printf_tester
	gcc -o printf_tester -g ft_printf_tester.c $(SRC) ./libft/libft.a
	./printf_tester
clean:
	@echo "cleaning..."
	@make clean -C ./libft --no-print-directory
	@echo "libft objects removed!"
	@rm -f $(OBJECTS)
	@echo "ft_printf objects removed!"
fclean: clean
	@make fclean -C ./libft --no-print-directory
	@rm -f $(NAME)
	@echo "libftprintf.a removed!"
re: fclean all
