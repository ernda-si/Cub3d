.RECIPEPREFIX := >
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
VAL_BASE = valgrind --leak-check=full --show-leak-kinds=all --track-fds=yes \
--track-origins=yes
SUPPRESS_FILE = $(wildcard suppress.x11)

ifeq ($(SUPPRESS_FILE),)
VAL = $(VAL_BASE)
else
VAL = $(VAL_BASE) --suppressions=$(SUPPRESS_FILE)
endif

# === COMPILATION ===
CC = cc
CFLAGS = -Wall -Werror -Wextra -g -O3 -I$(INCLUDES) -I$(LIBFT_DIR) -I$(GNL_DIR) -I$(MLX_DIR)
OBJDIR = build
MLXFLAGS = -lX11 -lXext -lm

# === PATHS ===
INCLUDES = includes
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a
GNL_DIR = get_next_line
MLX_DIR = minilibx-linux
MLX = /home/eve/42/red/3Dcube/dpaes-so_cub3d_mandatory/incs/minilibx-linux/libmlx.a
SRC = src

# === SOURCES ===
GNL_SRC = get_next_line.c get_next_line_utils.c
GNL_SRCS = $(addprefix $(GNL_DIR)/, $(GNL_SRC))

SRC_GENERAL = \
main.c \
rendering/rendering_bootstrap.c \
rendering/frame_render_loop.c \
rendering/vertical_slice_renderer.c \
rendering/wall_texture_sampling.c \
rendering/ray_grid_traversal.c \
rendering/ray_setup.c \
rendering/wall_projection.c \
parsing/validate_map_enclosure.c \
parsing/parse_map_block.c \
parsing/extract_player_spawn.c \
parsing/validate_map_content.c \
parsing/map_validation_steps.c \
parsing/parse_scene_file.c \
parsing/parse_texture_entries.c \
parsing/texture_config_validation.c \
parsing/color_conversion.c \
parsing/parse_rgb_values.c \
parsing/load_texture_images.c \
core/cleanup_resources.c \
core/error_report.c \
core/input_handler.c \
core/game_tick.c \
core/keyboard_events.c \
core/camera_turn.c \
core/image_pixel_write.c \
core/player_translation.c \
core/collision_checks.c \
core/string_utils.c \
core/memory_utils.c \
core/parsing_helpers.c
SRCS_DIR = $(addprefix $(SRC)/, $(SRC_GENERAL)) $(GNL_SRCS)
OBJS_DIR = $(addprefix $(OBJDIR)/, $(SRCS_DIR:%.c=%.o))

all: $(NAME)

$(NAME): $(OBJS_DIR) $(LIBFT) $(MLX)
> @echo "$(YELLOW)Compiling $(NAME)...$(RESET)"
> @$(CC) $(CFLAGS) $(OBJS_DIR) $(LIBFT) $(MLX) $(MLXFLAGS) -o $(NAME)
> @echo "$(GREEN)Done!$(RESET)"

$(LIBFT):
> @make -C $(LIBFT_DIR) -s

$(OBJDIR):
> @mkdir -p $(OBJDIR)

$(OBJDIR)/%.o: %.c
> @mkdir -p $(@D)
> @$(CC) $(CFLAGS) -c $< -o $@

clean:
> @echo "$(RED)Removing objects$(RESET)"
> @rm -rf $(OBJDIR)
> @make clean -C $(LIBFT_DIR) -s

fclean: clean
> @echo "$(RED)Removing $(NAME)$(RESET)"
> @rm -rf $(NAME)
> @make fclean -C $(LIBFT_DIR) -s

re: fclean all
> @echo "$(ORANGE)Re-Done!!$(RESET)"

run: all
> @./$(NAME) maps/default.cub

val: re
> $(VAL) ./$(NAME) maps/default.cub

.PHONY: all clean fclean re run val
