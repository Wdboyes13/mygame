OUT = game
CC ?= clang

CFLAGS += -O2 -Wall -Wextra
CPPFLAGS += $(shell pkg-config --cflags SDL2) $(shell pkg-config --cflags SDL2_image) $(shell pkg-config --cflags SDL2_mixer)
LDFLAGS += $(shell pkg-config --libs-only-L SDL2) $(shell pkg-config --libs-only-L SDL2_image) $(shell pkg-config --libs-only-L SDL2_mixer)
LDLIBS += $(shell pkg-config --libs-only-l SDL2) $(shell pkg-config --libs-only-l SDL2_image) $(shell pkg-config --libs-only-l SDL2_mixer) 

SRCS = ../src/views/CredsView.c ../src/views/DeadView.c ../src/Game.c ../src/ScoreRenderer/Init.c ../src/views/MainView.c ../src/views/MenuView.c ../src/ScoreRenderer/RenderNum.c ../src/Setup.c ../src/StartMusic.c ../src/views/MainHelpers/UpdatePos.c ../src/views/WinView.c 
OBJS := $(patsubst %.c,%.o,$(SRCS))
DESTDIR ?= /usr/local/bin

$(OUT): $(OBJS)
	$(CC) -o $@ $^ $(LDFLAGS) $(LDLIBS)

%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $< $(CPPFLAGS)

clean:
	rm -f $(OBJS) $(OUT)

install: $(OUT)
	install -d -m 755 $(DESTDIR)
	install -m 755 $(OUT) $(DESTDIR)/$(OUT)

.PHONY: install clean
