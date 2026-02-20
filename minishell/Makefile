NAME = minishell
SOURCES = main.c \
		 linklist.c \
		 parser.c \
		 check_type.c \
		 check_quote.c \
		 expansion_value.c \
		 ft_echo.c \
		 ft_export.c \
		 ft_env.c \
		 ft_split.c
CC = cc
RM = rm -f
OBJ = $(SOURCES:.c=.o)
CFLAG = -Wall -Wextra -Werror 
CFAGLINE = -lreadline

.PHONY : all clean fclean re

all: $(NAME)

.c.o:
	$(CC) $(CFLAG) -c $< -o $(<:.c=.o)

$(NAME): $(OBJ)
	$(CC) $(CFLAG) -o $(NAME) $(OBJ) $(CFAGLINE)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean $(NAME)