CC = gcc
CFLAGS = -Wall -Wextra -Werror
LIBFLAGS = -L libft/ -lft
LIBFT = libft/libft.a

SRCS_SV = src/server.c
SRCS_CL = src/client.c

SV_NAME = server
CL_NAME = client

OBJS_SV = $(SRCS_SV:.c=.o)
OBJS_CL = $(SRCS_CL:.c=.o)

all: print lib sv_start server cl_start client

lib:
	@if [ ! -f libft/libft.a ]; then \
		echo "\033[45m\033[1;37m--------------------BUILDING LIBFT--------------------\033[0m"; \
		echo "\033[1;93m"; \
		$(MAKE) -C libft; \
		echo "\n\033[42m\033[1;37m--------------------------DONE-------------------------\033[0m\n"; \
	fi

sv_start:
	@if [ ! -f $(SV_NAME) ]; then \
		echo "\033[45m\033[1;37m--------------------BUILDING SERVER--------------------\033[0m\033[1;93m\n"; \
	fi

server: $(LIBFT) $(OBJS_SV)
	$(CC) $(CFLAGS) -o $(SV_NAME) $(OBJS_SV) $(LIBFLAGS)
	@echo "\n\033[42m\033[1;37m--------------------------DONE-------------------------\033[0m\n"

cl_start:
	@if [ ! -f $(CL_NAME) ]; then \
		echo "\033[45m\033[1;37m--------------------BUILDING CLIENT--------------------\033[0m\033[1;93m\n"; \
	fi

client: $(LIBFT) $(OBJS_CL)
	$(CC) $(CFLAGS) -o $(CL_NAME) $(OBJS_CL) $(LIBFLAGS)
	@echo "\n\033[42m\033[1;37m--------------------------DONE-------------------------\033[0m"

print:
	@if [ ! -f $(CL_NAME) ]; then \
		echo "\033[32m              ##\           ##\   ##\               ##\ ##\       \033[0m"; \
		echo "\033[32m              \__|          \__|  ## |              ## |## |      \033[0m"; \
		echo "\033[32m######\####\  ##\ #######\  ##\ ######\    ######\  ## |## |  ##\ \033[0m"; \
		echo "\033[32m##  _##  _##\ ## |##  __##\ ## |\_##  _|   \____##\ ## |## | ##  |\033[0m"; \
		echo "\033[32m## / ## / ## |## |## |  ## |## |  ## |     ####### |## |######  / \033[0m"; \
		echo "\033[32m## | ## | ## |## |## |  ## |## |  ## |##\ ##  __## |## |##  _##<  \033[0m"; \
		echo "\033[32m## | ## | ## |## |## |  ## |## |  \####  |\####### |## |## | \##\ \033[0m"; \
		echo "\033[32m\__| \__| \__|\__|\__|  \__|\__|   \____/  \_______|\__|\__|  \__|\033[0m\n\n\n"; \
	fi

clean:
	$(MAKE) -C libft clean
	rm -rf $(OBJS_SV) $(OBJS_CL)

fclean:
	$(MAKE) -C libft fclean
	rm -rf $(SV_NAME) $(CL_NAME) $(OBJS_SV) $(OBJS_CL)

re: fclean all