CC = gcc
CFLAGS = -Wall -Wextra -std=c11
TARGET = aptb

SRCS = aptb.c coloro.c
OBJS = $(SRCS:.c=.o)
BINDIR = bin

all: $(BINDIR)/$(TARGET)

$(BINDIR)/$(TARGET): $(OBJS) | $(BINDIR)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c coloro.h
	$(CC) $(CFLAGS) -c $<

$(BINDIR):
	mkdir -p $(BINDIR)

clean:
	rm -f $(OBJS) $(BINDIR)/$(TARGET)