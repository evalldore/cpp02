NAME			:= fixed
CPPFLAGS		:= -Wall -Wextra -Werror -std=c++98
SRCS			:= main.cpp Fixed.cpp
BINDIR			:= bin/
OBJS			:= $(addprefix $(BINDIR), $(SRCS:.cpp=.o))
RM				:= rm -f
CC				:= c++

all : $(NAME)

$(BINDIR)%.o : $(SRCDIR)%.cpp
	@$(CC) -c $(CPPFLAGS) -o $@ $^

$(NAME) : $(BINDIR) $(OBJS)
	@echo $(NAME): Compiling!
	@$(CC) $(CPPFLAGS) -o $(NAME) $(OBJS)

$(BINDIR) :
	@mkdir $(BINDIR)

clean:
	@echo $(NAME): Deleting binaries.
	@rm -r $(BINDIR)

fclean: clean
	@echo $(NAME): Deleting program.
	@rm -f $(NAME)

re : fclean all