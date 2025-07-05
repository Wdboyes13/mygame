CC = wclang
LD = ld

VIEW_SRCS := $(wildcard src/views/*.c) $(wildcard src/views/MainHelpers/*.c)
MAIN_SRCS := $(filter-out $(VIEW_SRCS), $(wildcard src/*.c))

# Object files
VIEW_OBJS := $(patsubst %.c,%.o,$(VIEW_SRCS))
MAIN_OBJS := $(patsubst %.c,%.o,$(MAIN_SRCS))

# Groups
VIEWS_OBJ := src/views.o
MAIN_OBJ := src/main.o

OBJS := $(VIEWS_OBJ) $(MAIN_OBJ)

CFLAGS := -I/opt/will/include -O2 -Wall -Wextra -Werror

LDFLAGS := -L/opt/will/lib/SDL -lSDL2 -lSDL2_image -lSDL2_mixer \
			-Wl,-rpath,/opt/will/lib/SDL

OUT := game

# Final executable depends on the combined object files
$(OUT): $(OBJS)
	$(CC) $(LDFLAGS) -o $@ $^

# Archive views.o
$(VIEWS_OBJ): $(VIEW_OBJS)
	$(LD) -r -o $@ $^

# Archive main.o
$(MAIN_OBJ): $(MAIN_OBJS)
	$(LD) -r -o $@ $^

# Compile all .c to .o
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean
clean:
	rm -f $(OBJS) $(OUT) 
	rm -f $(MAIN_OBJS)
	rm -f $(VIEW_OBJS) 

git: clean
	git add .
	git commit -m "Updated: $(shell date)"
	git push

.PHONY: clean git