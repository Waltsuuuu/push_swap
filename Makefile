# === Compiler & Flags ===
CC = cc
CFLAGS = -Wall -Wextra -Werror -Iincludes -Ilibft

# === Executables ===
NAME = push_swap

# === PUSH_SWAP ===
SRCS =	src/main.c \
		src/utils/exit.c \
		src/utils/is_sorted.c \
		src/validate_and_parse/check_input.c \
		src/validate_and_parse/parse_input.c \
		src/operations/swap.c \

# === LIBFT ===
LIBFT_DIR = libft
LIBFT_LIB = $(LIBFT_DIR)/libft.a

# === Objects ===
OBJS = $(SRCS:.c=.o)
.SECONDARY: $(OBJS)

# === Build Targets ===
all: $(NAME) $(LIBFT_LIB)

$(LIBFT_LIB):
	@echo "Making libft..."
	@$(MAKE) --no-print-directory -s -C $(LIBFT_DIR)

$(NAME): $(OBJS) $(LIBFT_LIB)
	@$(CC) $(CFLAGS) $^ -o $@
	@echo "Project compiled successfully."

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

# === Cleanup ===
clean:
	@rm -f $(OBJS)
	@$(MAKE) --no-print-directory -s -C $(LIBFT_DIR) clean
	@echo "Cleaned object files."

fclean: clean
	@rm -f $(NAME)
	@$(MAKE) --no-print-directory -s -C $(LIBFT_DIR) fclean
	@echo "Cleaned executables."

re: fclean all

.PHONY: all clean fclean re
