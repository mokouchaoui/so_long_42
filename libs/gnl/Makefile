NAME = gnl.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs
HEADER = get_next_line.h

PATH_SRCS = ./
FILES_SRCS =	get_next_line get_next_line_utils

SRCS_DIR = ./
SRCS = $(addprefix $(SRCS_DIR), $(addsuffix .c, $(FILES_SRCS)))

OBJS_DIR = ./
OBJS = $(addprefix $(OBJS_DIR), $(addsuffix .o, $(FILES_SRCS)))


all: $(NAME)

$(NAME): $(OBJS) $(HEADER) ./Makefile
	$(AR) $@ $^
	
%.o: %.c $(SRCS) $(HEADER)
	$(CC) $(CFLAGS) -c -o $@ $(OBJS_DIR)$< 

clean:
	rm -rf $(OBJS)

fclean: clean
	$(RM) $(NAME)

re : fclean all

.PHONY: all clean fclean re