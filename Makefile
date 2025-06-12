CC = gcc
CFLAGS = -Wall -Wextra -std=c11
TARGET = aptb

SRCS = aptb.c coloro.c
OBJS = $(SRCS:.c=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c coloro.h
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f $(OBJS) $(TARGET)