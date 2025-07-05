CC = wclang

SRCS := src/Game.c src/views/DeadView.c src/views/MainView.c src/Setup.c

OBJS := $(patsubst %.c,%.o,$(SRCS))

CFLAGS := -I/opt/will/include -O2 -Wall -Wextra -Wpedantic -Werror
LDFLAGS := -L/opt/will/lib/SDL -lSDL2 -lSDL2_image \
			-Wl,-rpath,/opt/will/lib/SDL

OUT := game

$(OUT): $(OBJS)
	$(CC) $(LDFLAGS) -o $@ $^

%.o: %.c 
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(OUT)

.PHONY: clean