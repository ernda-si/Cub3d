# === COLORS ===
RED=\033[1;31m
YELLOW=\033[1;33m
ORANGE=\033[1;38;5;214m
GREEN=\033[1;32m
CYAN=\033[1;36m
RESET=\033[0m

# === NAME ===
NAME = cub3d

# === VALGRIND FLAGS ===
VAL = valgrind --leak-check=full --show-leak-kinds=all --track-fds=yes \
	--track-origins=yes --suppressions=readline.supp

# === COMPILATION ===
CC = cc
CFLAGS = -Wall -Werror -Wextra -I$(INCLUDES) -I$(LIBFT_DIR) -I$(GNL_DIR) -g
OBJDIR = build

# === INCLUDES ===
INCLUDES = include/

# === LIBFT ===
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

# === GET_NEXT_LINE ===
GNL_DIR = get_next_line
GNL_SRC = get_next_line.c get_next_line_utils.c
GNL_SRCS = $(addprefix $(GNL_DIR)/, $(GNL_SRC))

# === SRC PATH ===
SRC = src

# === FILES ===
SRC_GENERAL = main.c

SRCS_DIR = $(addprefix $(SRC)/, $(SRC_GENERAL)) $(GNL_SRCS)

OBJS_DIR = $(addprefix $(OBJDIR)/, $(SRCS_DIR:%.c=%.o))

# === RULES ===
all: $(NAME)

$(NAME): $(OBJS_DIR) $(LIBFT)
	@echo "$(YELLOW)Compiling $(NAME)...$(RESET)"
	@$(CC) $(CFLAGS) $(OBJS_DIR) $(LIBFT) -o $(NAME) -I/usr/include -Imlx_linux -O3
	@echo "$(GREEN)Done!$(RESET)"

$(LIBFT):
	@make -C $(LIBFT_DIR) -s

$(OBJDIR):
	@mkdir -p $(OBJDIR)

$(OBJDIR)/%.o: %.c
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@echo "$(RED)Removing objects$(RESET)"
	@rm -rf $(OBJDIR)
	@make clean -C $(LIBFT_DIR) -s

fclean: clean
	@echo "$(RED)Removing $(NAME)$(RESET)"
	@rm -rf $(NAME)
	@make fclean -C $(LIBFT_DIR) -s

re: fclean all
	@echo "$(ORANGE)Re-Done!!$(RESET)"

val: re
	$(VAL) ./$(NAME)

debug: re
	$(VAL) ./$(NAME) -d

.PHONY: all clean fclean re val debug
