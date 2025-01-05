CC       := clang
CFLAGS   := -Wall -Wextra -std=c99

SRC_DIR  := src
LIB_DIR  := lib

INCLUDES := -I$(LIB_DIR)

LDFLAGS  := \
    $(LIB_DIR)/libraylib.a \
    -framework CoreVideo \
    -framework OpenGL \
    -framework IOKit \
    -framework Cocoa \
    -framework GLUT

SOURCES  := $(wildcard $(SRC_DIR)/*.c)
OBJECTS  := $(SOURCES:.c=.o)

EXEC     :=  nebula


.PHONY: all clean

all: $(EXEC)

$(EXEC): $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(EXEC) $(SRC_DIR)/*.o
