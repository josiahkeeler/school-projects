#all, clean, fclean, re, bonus

NAME = libftprintf.a
LIBFT = libft.a
WGCC = gcc -Wall -Wextra -Werror
SOURCES = ft_printf.c ft_convert_alpha.c ft_convert_numbers.c \
	ft_flags.c ft_puthex.c
OBJECTS = ft_printf.o ft_convert_alpha.o ft_convert_numbers.o \
	ft_flags.o ft_puthex.o

all:$(NAME)

$(NAME): $(LIBFT)
	@cp libft/$(LIBFT) $(NAME)
	@$(WGCC) -I. -c $(SOURCES)
	@ar rcs $(NAME) $(OBJECTS)

$(LIBFT):
	@$(MAKE) -C libft

clean:
	@$(MAKE) clean -C libft
	@rm -f $(OBJECTS)

fclean: clean
	@$(MAKE) fclean -C libft
	@rm -f $(NAME) libft/*.h.gch

re: fclean all

bonus: all

.PHONY: $(NAME)