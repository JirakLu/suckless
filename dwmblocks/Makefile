include config.mk

SRC = dwmblocks.c
OBJ = $(SRC:.c=.o)

all: dwmblocks

.c.o:
	$(CC) -c $(CFLAGS) $<

config.h:
	cp config.def.h $@

$(OBJ): config.h config.mk

dwmblocks: dwmblocks.o
	$(CC) -o $@ dwmblocks.o $(LDFLAGS)

clean:
	rm -f $(OBJ) dwmblocks

install: all
	mkdir -p $(DESTDIR)$(PREFIX)/bin
	cp -f dwmblocks $(DESTDIR)$(PREFIX)/bin
	chmod 755 $(DESTDIR)$(PREFIX)/bin/dwmblocks
	# TODO: add man pages

uninstall:
	rm -f $(DESTDIR)$(PREFIX)/bin/dwmblocks

.PHONY: all clean install uninstall
