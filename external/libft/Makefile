NAME = libft.a

SRCS =	ft_is/ft_isalpha.c ft_is/ft_isdigit.c ft_is/ft_isalnum.c ft_is/ft_isascii.c ft_is/ft_isprint.c \
		\
		ft_memory/ft_memset.c ft_memory/ft_bzero.c ft_memory/ft_memcpy.c ft_memory/ft_memmove.c\
		ft_memory/ft_memchr.c ft_memory/ft_memcmp.c ft_memory/ft_calloc.c ft_memory/free_2d.c \
		ft_memory/ft_realloc.c\
		\
		ft_strings/ft_strlen.c ft_strings/ft_strlcpy.c ft_strings/ft_strlcat.c ft_strings/ft_strchr.c ft_strings/ft_strrchr.c ft_strings/ft_strncmp.c ft_strings/ft_strnstr.c ft_strings/ft_atoi.c ft_strings/ft_strdup.c\
		ft_strings/ft_substr.c ft_strings/ft_strjoin.c ft_strings/ft_itoa.c ft_strings/ft_strmapi.c ft_strings/ft_striteri.c ft_strings/ft_strtrim.c ft_strings/ft_split.c ft_strings/ft_strjoin_free.c \
		\
		ft_toupper.c ft_tolower.c \
		\
		ft_print/ft_putchar_fd.c ft_print/ft_putendl_fd.c ft_print/ft_putstr_fd.c ft_print/ft_putnbr_fd.c ft_print/ft_putchar.c \
		\
		ft_list/ft_lstnew_bonus.c ft_list/ft_lstadd_front_bonus.c ft_list/ft_lstsize_bonus.c ft_list/ft_lstlast_bonus.c ft_list/ft_lstadd_back_bonus.c \
		ft_list/ft_lstdelone_bonus.c ft_list/ft_lstclear_bonus.c ft_list/ft_lstiter_bonus.c ft_list/ft_lstmap_bonus.c

OBJDIR = obj
OBJS = $(SRCS:%.c=$(OBJDIR)/%.o)

CC = cc
CFLAGS = -Wall -Werror -Wextra

$(OBJDIR)/%.o: %.c
	@mkdir -p $(dir $@)
	@echo Compiling $<
	@$(CC) $(CFLAGS) -o $@ -c $<

all: $(NAME)

$(NAME): $(OBJS)
	@echo Compiling $(NAME)
	@ar rcs $(NAME) $(OBJS)

clean:
	@rm -rf $(OBJDIR)

fclean: clean
	@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
