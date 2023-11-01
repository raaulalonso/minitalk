CC = gcc
CFLAGS = #-Wall -Wextra -Werror
LIBFLAGS = -L libft/ -lft

SRCS_SV = src/server.c
SRCS_CL = src/client.c

SV_NAME = server
CL_NAME = client

OBJS_SV = $(SRCS_SV:.c=.o)
OBJS_CL = $(SRCS_CL:.c=.o)

all: server client

server: $(OBJS_SV)
	$(MAKE) -C libft
	$(CC) $(CFLAGS) -o $(SV_NAME) $(OBJS_SV) $(LIBFLAGS)

client: $(OBJS_CL)
	$(MAKE) -C libft
	$(CC) $(CFLAGS) -o $(CL_NAME) $(OBJS_CL) $(LIBFLAGS)

clean:
	$(MAKE) -C libft clean
	rm -rf $(OBJS_SV) $(OBJS_CL)

fclean:
	$(MAKE) -C libft fclean
	rm -rf $(SV_NAME) $(CL_NAME) $(OBJS_SV) $(OBJS_CL)

re: fclean all