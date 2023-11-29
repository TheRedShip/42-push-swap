SRCS    = ft_isalpha.c \
			ft_isalnum.c \
			ft_isascii.c \
			ft_isdigit.c \
			ft_isprint.c \
			ft_strlen.c \
			ft_memset.c \
			ft_bzero.c \
			ft_memcmp.c \
			ft_memcpy.c \
			ft_memmove.c \
			ft_strlcpy.c \
			ft_strlcat.c \
			ft_toupper.c \
			ft_tolower.c \
			ft_strchr.c \
			ft_strrchr.c \
			ft_strncmp.c \
			ft_memchr.c \
			ft_strnstr.c \
			ft_atoi.c \
			ft_calloc.c \
			ft_strdup.c \
			ft_substr.c \
			ft_strjoin.c \
			ft_strtrim.c \
			ft_split.c \
			ft_itoa.c \
			ft_strmapi.c \
			ft_striteri.c \
			ft_putchar_fd.c \
			ft_putstr_fd.c \
			ft_putendl_fd.c \
			ft_putnbr_fd.c \
			ft_split_mult.c \
			ft_abs.c		\
			ft_min.c		\
			get_next_line_utils_bonus.c \
			get_next_line_bonus.c

SRCSBONUS = ft_lstnew.c \
			ft_lstadd_front.c \
			ft_lstsize.c \
			ft_lstlast.c \
			ft_lstadd_back.c \
			ft_lstdelone.c \
			ft_lstclear.c \
			ft_lstiter.c \
			ft_lstmap.c

NAME    = libft.a

OBJS    =  $(SRCS:.c=.o)

OBJSBONUS = $(SRCSBONUS:.c=.o)

HEADERS    = includes/

all : $(NAME)

.c.o: 
	cc -Wall -Wextra -Werror -I $(HEADERS) -c $< -o $@

$(NAME) : $(OBJS)
	ar rcs $(NAME) $(OBJS)

bonus: $(OBJS) $(OBJSBONUS)
	ar rcs $(NAME) $(OBJS) $(OBJSBONUS)

clean :
	rm -f $(OBJS) $(OBJSBONUS)

fclean : clean
	rm -f $(NAME)

re : fclean all
