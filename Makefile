BIN = caveman

SRC = main.c Util.c Map.c Ghost.c
OBJS = $(SRC: .c=.o)
DEPS = $(SRC: .c=.d)

CFLAGS = -Wshadow -Wall -Wpendatic -Wextra -g

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
