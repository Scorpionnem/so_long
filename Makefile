NAME = so_long

CC = cc
CFLAGS = -Wall -Wextra -Werror -MMD -MP -g

EXTERNALDIR = external
MLXDIR = minilibx-linux
GNLDIR = gnl
OBJDIR = obj
LIBFTDIR = libft

INCLUDES = -I includes/ -I $(EXTERNALDIR)/$(MLXDIR)/ -I $(EXTERNALDIR)/$(GNLDIR)/ -I $(EXTERNALDIR)/$(LIBFTDIR)/

SRCS =	src/main.c \
		src/parsing/parsing.c\
		src/parsing/flood_fill.c\
		src/parsing/parse_map.c\

OBJS = $(SRCS:%.c=$(OBJDIR)/%.o)
DEPS = $(SRCS:%.c=$(OBJDIR)/%.d)

MLX = $(EXTERNALDIR)/$(MLXDIR)/libmlx.a
GNL = $(EXTERNALDIR)/$(GNLDIR)/libgnl.a
LIBFT = $(EXTERNALDIR)/$(LIBFTDIR)/libft.a

all: minilibx $(MLX) $(GNL) $(LIBFT) $(NAME)

run: all
	./$(NAME)

re: fclean all

$(EXTERNALDIR):
	@mkdir -p $(EXTERNALDIR)

$(MLX): $(EXTERNALDIR)
	@make -C $(EXTERNALDIR)/$(MLXDIR) all --no-print-directory

$(GNL): $(EXTERNALDIR)
	@make -C $(EXTERNALDIR)/$(GNLDIR) all --no-print-directory

$(LIBFT): $(EXTERNALDIR)
	@make -C $(EXTERNALDIR)/$(LIBFTDIR) all --no-print-directory

$(NAME): $(OBJS)
	@echo Compiling $(NAME)
	@$(CC) $(CFLAGS) $(INCLUDES) -o $@ $^ $(MLX) $(GNL) $(LIBFT) -lXext -lX11 -lm -lz

$(OBJDIR)/%.o: %.c
	@mkdir -p $(dir $@)
	@echo Compiling $<
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	@make -C $(EXTERNALDIR)/$(MLXDIR) clean --no-print-directory
	@make -C $(EXTERNALDIR)/$(GNLDIR) clean --no-print-directory
	@make -C $(EXTERNALDIR)/$(LIBFTDIR) clean --no-print-directory
	@echo Cleaning objects
	@rm -rf $(OBJDIR)

fclean: clean
	@make -C $(EXTERNALDIR)/$(GNLDIR) fclean --no-print-directory
	@make -C $(EXTERNALDIR)/$(LIBFTDIR) fclean --no-print-directory
	@echo Cleaning $(NAME)
	@rm -rf $(NAME)

minilibx: $(EXTERNALDIR)
	@if ls $(EXTERNALDIR) | grep -q "$(MLXDIR)"; then \
		echo "\033[32;1;4mminilibx-linux Found\033[0m"; \
	else \
		echo "\033[31;1;4mminilibx-linux Not Found\033[0m"; \
		echo "\033[31;1mDownloading minilibx-linux from github \033[0m"; \
		git clone https://github.com/42paris/minilibx-linux.git $(EXTERNALDIR)/$(MLXDIR); \
	fi

.PHONY: all clean fclean run re

-include $(DEPS)
