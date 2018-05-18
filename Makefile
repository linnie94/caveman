BIN = caveman

SRC = main.c Util.c Map.c Ghost.c
OBJS = $(SRC:.c=.o)
DEPS = $(SRC:.c=.d)

<<<<<<< HEAD
CFLAGS = -Wshadow -Wall -Wpendatic -Wextra -g
=======
CFLAGS = -Wshadow -Wall -Wpedantic -Wextra -g
>>>>>>> 09d847fae4035a9708912776e8506d0168d19c70

LDFLAGS = -lm -lSDL2

$(BIN): $(OBJS)
	gcc $(CFLAGS) $(OBJS) $(LDFLAGS) -o $(BIN)

%.o : %.c Makefile
	gcc $(CFLAGS) -MMD -MP -MT $@ -MF $*.td -c $<
	mv -f $*.td $*.d

%.d: ;
-include *.d

clean:
	rm -f $(BIN) $(OBJS) $(DEPS)
