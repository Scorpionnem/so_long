NAME = libgnl.a

SRCS = get_next_line.c get_next_line_utils.c get_next_line_internals.c get_line_count.c get_file.c

OBJDIR = obj
OBJS = $(SRCS:%.c=$(OBJDIR)/%.o)

CC = cc
CFLAGS = -Wall -Werror -Wextra

$(OBJDIR)/%.o: %.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -o $@ -c $<

all: $(NAME)

$(NAME): $(OBJS)
	@ar rcs $(NAME) $(OBJS)

clean:
	@rm -rf $(OBJDIR)

fclean: clean
	@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
